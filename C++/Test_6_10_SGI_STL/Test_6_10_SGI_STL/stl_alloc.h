#pragma once

#include<iostream>
#include<new>
using namespace std;

#define __THROW_BAD_ALLOC throw bad_alloc

//一级空间配置器
template<int inst>
class __malloc_alloc_template
{
public:
	static void* allocate(size_t n)
	{
		void *result = malloc(n);
		if(0 == result)
			result = oom_malloc(n);
		return result;
	}
	static void* reallocate(void *p, size_t old_sz, size_t new_sz)
	{
		void *result = realloc(p, new_sz);
		if(0 == result)
			result = oom_realloc(p, new_sz);
		return result;
	}
	static void  deallocate(void *p, size_t n)
	{
		free(p);
	}
	static void(* set_malloc_handler(void(*f)()))()
	{
		void (*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return old;
	}
private:
	static void* oom_malloc(size_t n);
	static void* oom_realloc(void *p, size_t n);
	static void(*__malloc_alloc_oom_handler)();//函数指针
};

template<int inst>
void(*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

template<int inst>
void* __malloc_alloc_template<inst>::oom_malloc(size_t n)
{
	void(*my_malloc_handler)();
	void *result;

	for(;;)
	{
		my_malloc_handler = __malloc_alloc_oom_handler;
		if(0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC();
		}
		(*my_malloc_handler)();
		result = malloc(n);
		if(result)
			return result;
	}
}

template<int inst>
void* __malloc_alloc_template<inst>::oom_realloc(void *p, size_t n)
{
	void(*my_malloc_handler)();
	void *result;

	for(;;)
	{
		my_malloc_handler = __malloc_alloc_oom_handler;
		if(0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC();
		}
		(*my_malloc_handler)();
		result = realloc(p, n);
		if(result)
			return result;
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//二级空间配置器
enum {__ALIGN = 8};
enum {__MAX_BYTES = 128};
enum {__NFREELISTS = __MAX_BYTES / __ALIGN};

template<bool threads, int inst>
class __default_alloc_template
{
public:
	static void* allocate(size_t n);
	static void  deallocate(void *p, size_t n);
	static void* reallocate(void *p, size_t old_sz, size_t new_sz);
private:
	//这个函数作用是什么
	static size_t ROUND_UP(size_t bytes)
	{
		return (((bytess) + __ALIGN-1) & ~(__ALIGN-1));
	}
	static size_t FREELIST_INDEX(size_t bytes)
	{
		return ((bytes)+__ALIGN-1)/__ALIGN-1;
	}

private:
	union obj
	{
		union obj *free_list_link;
		char client_data[1];
	};
private:
	static obj *free_list[__NFREELISTS]; //数组
private:
	static char *start_free;
	static char *end_free;
	static size_t heap_size;
};