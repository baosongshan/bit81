#include"Sysutil.h"

void DirectionList(const string &path, vector<string> &subfile, vector<string> &subdir)
{
	string _path = path;  //"C:\\Users\\baoso\\Desktop\\Pro_81\\my_dir"
	_path += "\\*.*";     //"C:\\Users\\baoso\\Desktop\\Pro_81\\my_dir\\*.*";

	_finddata_t file;
	long handle = _findfirst(_path.c_str(), &file); //搜索path路劲下的第一个文件
	if(handle == -1)
	{
		perror("_findfirst");  //日志系统
		return;
	}

	do
	{
		if(strcmp(file.name,".")==0 || strcmp(file.name,"..")==0) //skip . and ..
			continue;

		if(file.attrib & _A_SUBDIR) 
		{
			//目录
			//cout<<file.name<<endl;
			//string tmp_path = path; //"C:\\Users\\baoso\\Desktop\\Pro_81\\my_dir";
			//tmp_path += "\\";       //"C:\\Users\\baoso\\Desktop\\Pro_81\\my_dir\\";
			//tmp_path += file.name;  //"C:\\Users\\baoso\\Desktop\\Pro_81\\my_dir\\AA";
			//DirectionList(tmp_path);
			subdir.push_back(file.name);
		}
		else
			//cout<<file.name<<endl;
			subfile.push_back(file.name);
	}while(_findnext(handle, &file) == 0);

	_findclose(handle);
}