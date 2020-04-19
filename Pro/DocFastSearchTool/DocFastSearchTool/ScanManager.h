#pragma once
#include"Common.h"
#include"DataManager.h"

class ScanManager
{
public:
	static ScanManager& CreateInstance(const string &path);
public:
	void StartScan(const string &path);
	void StartWatch(); // ¼à¿ØÏß³Ì
	void ScanDirectory(const string &path);
private:
	ScanManager();
private:
	//DataManager m_db;
};