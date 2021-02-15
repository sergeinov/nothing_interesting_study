#pragma once
#include"MyArrayError.h"
#include"MyEmptyStack.h"
#include"MyStackFullError.h"
#include<iostream>
#include<ostream>


template <typename T, size_t size> class MyStack
{
	T arr[ size ];			// ������ �����-�� ������
	size_t count;			// ������ �������
public:
	MyStack() : count(0) { };

	void push(const T&);		// �������� � ������
	T pop();					// ����� � ������� ������(������)
	T& operator[](int);			// �������� � ������� ������ �� �������

	template<typename T, size_t size> friend std::ostream& operator<<(std::ostream& os, const MyStack<T, size>& s);		// ����� �������
};


template<typename T, size_t size>
inline void MyStack<T, size>::push(const T& data)
{
	if ( count == size )
	{
		throw MyStackFullError(size);		// TODO catch
	}

	arr[ count ] = data;
	count++;
}

template<typename T, size_t size>
inline T MyStack<T, size>::pop()			// TODO
{
	if ( count == 0 )
	{
		throw MyEmptyStack(count);
	}
	count--;
	return arr[count];
}

template<typename T, size_t size>
inline T& MyStack<T, size>::operator[](int index)			// TODO
{
	if ( index < count && index >= 0 )
	{
		return arr[ index ];
	}
	throw MyArrayError(index, count);		// ����� ���������� ���������� � ������ MyArrayError
}



template<typename T, size_t size> std::ostream& operator<<(std::ostream& os, const MyStack<T, size>& s)		// TODO
{
	os << "������: " << s.count << std::endl;
	for ( size_t i = 0; i < s.count; i++ )
	{
		os << s.arr[i] << " " << std::endl;
	}
}