#pragma once

template <class T>
inline T* value_type(const T*)
{
	cout<<"T = "<<typeid(T).name()<<endl;
	return (T*)(0);
}