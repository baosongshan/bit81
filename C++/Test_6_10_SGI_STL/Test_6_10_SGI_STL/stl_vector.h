#pragma once

#include"stl_alloc.h"
#include"stl_uninitialized.h"

template<class T, class Alloc = alloc>
class vector
{
public:
	//��ȡ
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
		fill_initialize(n, value);
	}
private:
	void fill_initialize(size_type n, const T &value)
	{
		start = allocate_and_fill(n, value);
		finish = start + n;
		end_of_storage = finish;
	}
	iterator allocate_and_fill(size_type n, const T &value)
	{
		iterator result = data_allocator::allocate(n);
		Uninitialized_fill_n(result, n, value);
		return result;
	}
private:
	typedef simple_alloc<value_type, Alloc> data_allocator;
private:
	iterator start;
	iterator finish;
	iterator end_of_storage;
};