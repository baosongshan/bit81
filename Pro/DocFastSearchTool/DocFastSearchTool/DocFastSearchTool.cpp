#include"Common.h"
#include"Sysutil.h"
#include"./sqlite/sqlite3.h"
#include"DataManager.h"
#include"ScanManager.h"



void Test_DirectionList()
{
	const string &path = "C:\\Users\\baoso\\Desktop\\Pro_81\\my_dir";
	vector<string> subfile, subdir;
	DirectionList(path, subfile, subdir);
	for(const auto &e : subfile)
		cout<<e<<endl;
	for(const auto &e : subdir)
		cout<<e<<endl;
}

void Test_Sqlite()
{
	//数据打开
	sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);
	if(rc != SQLITE_OK)
		printf("Open database failed.\n");
	else
		printf("Open database successed.\n");

	//操作数据库
	string sql = "select * from my_tb";
	char **result;
	int row;
	int col;
	char *zErrMsg = 0;

	sqlite3_get_table(db, sql.c_str(), &result, &row, &col, &zErrMsg);

	for (int i = 1; i <= row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			//cout<<*((result+(i*col)+j))<<"  ";
			printf("%-5s", *(result+(i*col)+j));

		}
		cout<<endl;
	}
	//cout<<endl;

	sqlite3_free_table(result);
	//关闭数据库
	sqlite3_close(db);
}

void Test_SqliteManager()
{
	SqliteManager sm;
	sm.Open("doc.db");

	//string sql = "create table if not exists doc_tb(id integer primary key autoincrement, doc_name text, doc_path text)";
	//sm.ExecuteSql(sql);
	//string sql1 = "insert into doc_tb values(null, 'stl.pdf', 'c:\\')";
	//sm.ExecuteSql(sql1);

	string sql = "select * from doc_tb";
	int row=0, col=0;
	char **ppRet = 0;
	sm.GetResultTable(sql, row, col, ppRet);
	for(int i=0; i<=row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			printf("%-10s", *(ppRet+(i*col)+j));
		}
		printf("\n");
	}
	sqlite3_free_table(ppRet);
}

void Test_Log()
{
	FILE *fp = fopen("Test.txt", "r");
	if(fp == NULL)
	{
		TRACE_LOG("Open File Error.");
		return;
	}
	else
		TRACE_LOG("Open File Success.");

	fclose(fp);
}

void Test_Set()
{
	//单重集合
	vector<int> v = {5,8,9,3,5,5,5,5,5,5,7,6,2,1,0};
	
	multiset<int> s;
	//set<int> s;
	for(const auto &e : v)
		s.insert(e);

	auto it = s.begin();
	while(it != s.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

void Test_Map()
{
	//映射
	pair<int, string> p1 = {1, "abc"};
	pair<int, string> p2 = {5, "xyz"};
	pair<int, string> p3 = {3, "lmn"};
	pair<int, string> p4 = {2, "opq"};
	pair<int, string> p5 = {9, "hjk"};
	pair<int, string> p6 = {7, "rty"};

	//cout<<p1.first<<" : "<<p1.second<<endl;
	map<int, string> mp;
	mp.insert(p1);
	mp.insert(p2);
	mp.insert(p3);
	mp.insert(p4);
	mp.insert(p5);
	mp.insert(p6);

	for(const auto &e : mp)
		cout<<e.first<<" : "<<e.second<<endl;
	
}


void Test_Scan()
{
	const string &path = "C:\\Users\\baoso\\Desktop\\Pro_81\\my_dir";
	ScanManager sm;
	sm.ScanDirectory(path);
}

int main(int argc, char *argv[])
{
	//Test_DirectionList();
	//Test_Sqlite();
	//Test_SqliteManager();
	//Test_Log();
	//Test_Set();
	//Test_Map();
	Test_Scan();
	return 0;
}

/*
static int callback(void *data, int argc, char **argv, char **azColName)
{
	int i;
	fprintf(stderr, "%s: \n", (const char*)data);
	for (i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
void Test_Sqlite()
{
	//数据打开
	sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);
	if(rc != SQLITE_OK)
		printf("Open database failed.\n");
	else
		printf("Open database successed.\n");

	//操作数据库

	char *zErrMsg = 0;
	const char* data = "Callback function called";

	//sqlite3_exec(sqlite3*, const char *sql, sqlite_callback, void *data, char **errmsg)；
	//string sql = "create table you_tb(id int, name varchar(20), path varchar(100))";
	//string sql = "insert into you_tb values(1, 'abc', 'c:\\')";

	string sql = "select id, name, path from my_tb where id=2";

	//rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		//fprintf(stdout, "Table created successfully\n");
		//fprintf(stdout, "Insert Data successfully\n");
		fprintf(stdout, "Select Data successfully\n");
	}

	sqlite3_close(db);
}

int main(int argc, char *argv[])
{
	//Test_DirectionList();
	Test_Sqlite();
	return 0;
}
*/