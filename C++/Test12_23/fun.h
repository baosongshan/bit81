#pragma once
#include<assert.h>

template<typename Type=int, size_t SIZE=100>
class Array
{
public:
	Array(size_t sz = SIZE);
	~Array();
public:
	Type& operator[](int pos);
	Type& at(int pos);
public:
	Type front()const;
	Type back()const;
public:
	Array operator+(int offset);
	Type& operator*();
private:
	Type *base;
	int  size;
	size_t capacity;
};

//////////////////////////////////////////////////
template<typename Type,size_t SIZE>
Array<Type,SIZE>::Array(size_t sz) : base(nullptr)
{
	base = new Type[sz];
	memset(base, 0, sizeof(Type)*sz);
	size = 0;
	capacity = sz;
}
template<typename Type, size_t SIZE>
Array<Type,SIZE>::~Array()
{
	delete []base;
	base = nullptr;
	size = capacity = 0;
}

template<typename Type, size_t SIZE>
Type& Array<Type,SIZE>::operator[](int pos)
{
	assert(pos<0 || pos>size);
	return base[pos];
}


/*
//int fun(int a, int b);

template<typename Type>
Type fun(Type a, Type b);

*/