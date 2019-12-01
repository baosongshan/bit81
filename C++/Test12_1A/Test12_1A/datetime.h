
#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d); 
	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
private:
	int _year;
	int _month;
	int _day;
};


/*
class CDateTime
{
	friend ostream& operator<<(ostream &out, const CDateTime &dt);
public:
	CDateTime(int year = 1900, int month = 1, int day = 1);
public:
	void GetCurDateTime();
	void DShowDateTime();
	void ShowCalendar(int year, int month);
public:
	/*CDateTime(const Date& d);
	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	
private:
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;
	int _second;
};
*/