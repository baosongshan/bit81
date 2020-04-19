#include"ScanManager.h"
#include"Sysutil.h"

ScanManager::ScanManager()
{}
void ScanManager::StartScan(const string &path)
{
	while(1)
	{
		//�ȴ�3����ɨ��
		this_thread::sleep_for(chrono::seconds(3));
		ScanDirectory(path);
	}
}
ScanManager& ScanManager::CreateInstance(const string &path)
{
	static ScanManager inst;
	thread scan_thread(&StartScan, &inst, path);
	scan_thread.detach();
	return inst;
}

void ScanManager::ScanDirectory(const string &path)
{
	//1 ɨ�豾���ļ�ϵͳ
	vector<string> local_files;  //subfiles
	vector<string> local_dirs;   //subdirs
	DirectionList(path, local_files, local_dirs);
	set<string> local_set;
	local_set.insert(local_files.begin(), local_files.end());
	local_set.insert(local_dirs.begin(), local_dirs.end());

	//2 ɨ�����ݿ��ļ�ϵͳ
	DataManager &m_db = DataManager::GetInstance();

	multiset<string> db_set;
	m_db.GetDocs(path, db_set);

	//3 �Աȱ����ļ������ݿ��ļ�
	auto local_it = local_set.begin();
	auto db_it = db_set.begin();
	while(local_it!=local_set.end() && db_it!=db_set.end())
	{
		if(*local_it < *db_it)
		{
			//�����ļ����ڣ����ݿ��ļ������ڣ������ݿ������ļ�
			m_db.InsertDoc(path, *local_it);
			local_it++;
		}
		else if(*local_it > *db_it)
		{
			//�����ļ������ڣ����ݿ��ļ����ڣ������ݿ�ɾ���ļ�
			m_db.DeleteDoc(path, *db_it);
			db_it++;
		}
		else
		{
			//�����ļ����ڣ����ݿ��ļ����ڣ������ݿ��ļ�����Ҫ�ı�
			local_it++;
			db_it++;
		}
	}

	while(local_it != local_set.end())
	{
		//�����ļ����ڣ����ݿ��ļ������ڣ������ݿ������ļ�
		m_db.InsertDoc(path, *local_it);
		local_it++;
	}
	while(db_it != db_set.end())
	{
		//�����ļ������ڣ����ݿ��ļ����ڣ������ݿ�ɾ���ļ�
		m_db.DeleteDoc(path, *db_it);
		db_it++;
	}

	//�ݹ������Ŀ¼
	for(const auto &dir : local_dirs)
	{
		string dir_path = path; //C:\Users\baoso\Desktop\Pro_81\my_dir
		dir_path += "\\";       // C:\Users\baoso\Desktop\Pro_81\my_dir\ 
		dir_path += dir;        //C:\Users\baoso\Desktop\Pro_81\my_dir\AA
		ScanDirectory(dir_path);
	}
}