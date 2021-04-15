#pragma once
#include<iostream>

template<typename T, size_t size> class MyArray
{
	T ar[ size ]{};			//как обеспечить инициализацию элементов базового типа по умолчанию нулем?

public:
	MyArray() = default;
	MyArray(const T* val, size_t size2 = size) 
	{ 
		size_t s = std::min(size, size2);
		for ( size_t i = 0; i < s; i++ )
		{
			ar[ i ] =  val[ i ];
		}
	};

};

template<typename T, size_t size> MyArray(const T(& temp)[ size ])->MyArray<T, size>;
