#pragma once
#include"MyArrayError.h"
#include"MyEmptyStack.h"
#include"MyStackFullError.h"
#include<iostream>
#include<ostream>


template <typename T, size_t size> class MyStack
{
	T arr[ size ];			// массив каких-то данных
	size_t count;			// размер массива
public:
	MyStack() : count(0) { };

	void push(const T&);		// положить в массив
	T pop();					// взять с массива данные(сверху)
	T& operator[](int);			// изменить в массиве данные по индексу

	template<typename T, size_t size> friend std::ostream& operator<<(std::ostream& os, const MyStack<T, size>& s);		// вывод массива
};


template<typename T, size_t size>
inline void MyStack<T, size>::push(const T& data)
{
	if ( count == size )
	{
		throw MyStackFullError(size);		// вызов исключения написанный в классе MyStackFullError
	}

	arr[ count ] = data;
	count++;
}

template<typename T, size_t size>
inline T MyStack<T, size>::pop()			
{
	if ( count == 0 )
	{
		throw MyEmptyStack(count);			// вызов исключения написанный в классе MyEmptyStack
	}
	count--;
	return arr[count];
}

template<typename T, size_t size>
inline T& MyStack<T, size>::operator[](int index)			
{
	if ( index < count && index >= 0 )
	{
		return arr[ index ];
	}
	throw MyArrayError(index, count);		// вызов исключения написанный в классе MyArrayError
}



template<typename T, size_t size> std::ostream& operator<<(std::ostream& os, const MyStack<T, size>& s)		// печатаем массив
{
	os << "Размер: " << s.count << std::endl;
	for ( size_t i = 0; i < s.count; i++ )
	{
		os << s.arr[i] << " " << std::endl;
	}
	return os;
}