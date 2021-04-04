#pragma once
#include<iostream>


template<typename T> class MyUniquePTR
{
	T* m_ptr;					// указатель на начало чего либо
public:
	MyUniquePTR() = default;								// указатель для "владения" через конструктор
	MyUniquePTR(T* ptr = nullptr) : m_ptr(ptr) { };		
	~MyUniquePTR() { delete m_ptr; }						// деструктор позаботится об удалении указателя
	
	// Мы можем явно определить и удалить конструктор копирования с оператором присваивания
	MyUniquePTR(const MyUniquePTR& other) = delete;				// конструктор копирования
	MyUniquePTR& operator=(const MyUniquePTR& other) = delete;	// оператор присваивания

	MyUniquePTR(std::string)
	{

	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }

	bool operator bool() const 
	{ 
		if ( m_ptr != nullptr )
		{
			return true;
		}
		else
		{
			return false;
		}		
	}

};

