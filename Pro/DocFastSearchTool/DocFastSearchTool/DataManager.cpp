#include"DataManager.h"
#include"Sysutil.h"

//��̬��
#pragma comment(lib, "./sqlite/sqlite3.lib")

SqliteManager::SqliteManager() : m_db(nullptr)
{}
SqliteManager::~SqliteManager()
{
	Close();
}

void SqliteManager::Open(const string &path)
{
	char *zErrMsg = 0;
	int rc;
	rc = sqlite3_open(path.c_str(), &m_db);
	if (rc)
	{
		//fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_db));
		ERROR_LOG("Can't open database: %s", sqlite3_errmsg(m_db));
		exit(0);
	}
	else
	{
		//fprintf(stderr, "Opened database successfully\n");
		TRACE_LOG("Opened database successfully.");
	}
}
void SqliteManager::Close()
{
	if(m_db)
	{
		int rc = sqlite3_close(m_db);
		if(rc != SQLITE_OK)
		{
			//fprintf(stderr, "Close database failed: %s\n", sqlite3_errmsg(m_db));
			ERROR_LOG("Close database failed: %s", sqlite3_errmsg(m_db));
		}
		else
			//fprintf(stderr, "Close database successfully\n");
			TRACE_LOG( "Close database successfully.");
	}
}

void SqliteManager::ExecuteSql(const string &sql)
{
	char *zErrMsg = 0;
	int rc = sqlite3_exec(m_db, sql.c_str(), 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		//fprintf(stderr, "SQL(%s) error: %s\n", sql.c_str(),zErrMsg);
		ERROR_LOG("SQL(%s) error: %s", sql.c_str(),zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		//fprintf(stdout, "SQL(%s) Execute successfully.\n", sql.c_str());
		TRACE_LOG("SQL(%s) Execute successfully.", sql.c_str());
	}
}

void SqliteManager::GetResultTable(const string &sql, int &row, int &col, char **&ppRet)
{
	char *zErrMsg = 0;
	int rc = sqlite3_get_table(m_db, sql.c_str(), &ppRet, &row, &col, &zErrMsg);
	if(rc != SQLITE_OK)
	{
		//fprintf(stdout, "Get Result Table error: %s\n", zErrMsg);
		ERROR_LOG("Get Result Table error: %s", zErrMsg);
	}
	else
	{
		//fprintf(stdout, "Get Result Table successfully.\n", zErrMsg);
		TRACE_LOG( "Get Result Table successfully.", zErrMsg);
	}
}

////////////////////////////////////////////////////////////////////////////////////
AutoGetResultTable::AutoGetResultTable(SqliteManager *db, const string &sql, int &row, 
									   int &col, char **&ppRet) : m_db(db)
{
	m_db->GetResultTable(sql, row, col, ppRet);
	m_ppRet = ppRet;
}
AutoGetResultTable::~AutoGetResultTable()
{
	if(m_ppRet)
		sqlite3_free_table(m_ppRet);
}


//////////////////////////////////////////////////////////////////////////////////////

DataManager& DataManager::GetInstance()
{
	static DataManager inst;
	return inst;
}
DataManager::DataManager()
{
	m_dbmgr.Open(DOC_DB);
	InitSqlite();
}
DataManager::~DataManager()
{}

void DataManager::InitSqlite()
{
	char sql[SQL_BUFFER_SIZE] = {0};
	sprintf(sql, "create table if not exists %s(id integer primary key autoincrement, doc_name text, doc_path text)", DOC_TABLE);
	m_dbmgr.ExecuteSql(sql);
}

void DataManager::InsertDoc(const string &path, const string &doc)
{
	char sql[SQL_BUFFER_SIZE] = {0};
	sprintf(sql, "insert into %s values(null, '%s', '%s')",DOC_TABLE, doc.c_str(), path.c_str());
	//insert into %s values(null, stl.pdf, c:\\)
	m_dbmgr.ExecuteSql(sql);
}
void DataManager::GetDocs(const string &path, multiset<string> &docs)
{
	char sql[SQL_BUFFER_SIZE] = {0};
	sprintf(sql, "select doc_name from %s where doc_path='%s'", DOC_TABLE, path.c_str());

	int row=0, col=0;
	char **ppRet = 0;
	//m_dbmgr.GetResultTable(sql, row, col, ppRet);
	AutoGetResultTable at(&m_dbmgr, sql, row, col, ppRet);

	for(int i=1; i<=row; ++i)
		docs.insert(ppRet[i]);

	//�ͷŽ����
	//sqlite3_free_table(ppRet);
}
void DataManager::DeleteDoc(const string &path, const string &doc)
{
	char sql[SQL_BUFFER_SIZE] = {0};
	sprintf(sql, "delete from %s where doc_name='%s' and doc_path='%s'", DOC_TABLE, doc.c_str(), path.c_str());
	m_dbmgr.ExecuteSql(sql);

	///////////////////////////////////////////
	//����ɾ��Ŀ¼�µ����ļ�
	string doc_path = path; //C:\Users\baoso\Desktop\Pro_81\my_dir
	doc_path += "\\";       //C:\Users\baoso\Desktop\Pro_81\my_dir\ 
	doc_path += doc;        //C:\Users\baoso\Desktop\Pro_81\my_dir\CC

	memset(sql, 0, SQL_BUFFER_SIZE);
	sprintf(sql, "delete from %s where doc_path like '%s%%'", DOC_TABLE, doc_path.c_str());
	m_dbmgr.ExecuteSql(sql);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DataManager::Search(const string &key, vector<pair<string,string>> &doc_path)
{
	char sql[SQL_BUFFER_SIZE] = {0};
	sprintf(sql, "select doc_name, doc_path from %s where doc_name like '%%%s%%'", DOC_TABLE, key.c_str());
	int row=0, col=0;
	char **ppRet = nullptr;
	
	//m_dbmgr.GetResultTable(sql, row, col, ppRet);
	AutoGetResultTable at(&m_dbmgr, sql, row, col, ppRet);

	doc_path.clear();
	//   doc_name       doc_path
	//   1.txt         c:\ 
	for(int i=1; i<=row; ++i)
		doc_path.push_back(make_pair(ppRet[i*col], ppRet[i*col+1]));

	//�ͷŽ����
	//sqlite3_free_table(ppRet);
}