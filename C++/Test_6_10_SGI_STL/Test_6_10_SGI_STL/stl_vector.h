#pragma once

#include"stl_alloc.h"

template<class T, class Alloc = alloc>
class vector
{
public:
	//萃取
	typedef T  value_type;
	typedef value_type * pointer;
	typedef value_type & reference;
	typedef size_t       size_type;
	typedef size_t       difference_type;
public:
	typedef value_type*  iterator;
public:
	vector() : start(0),finish(0),end_of_storage(0)
	{}
	vector(int n, const T &value)
	{
		//1 配置空间
		//2 构造对象
	}
private:
	iterator start;
	iterator finish;
	iterator end_of_storage;
};