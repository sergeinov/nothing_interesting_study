#pragma once
#include<iostream>


template<typename T> class MyUniquePTR
{
	T* m_ptr{};												// указатель на начало чего либо
public:
	MyUniquePTR() = default;								
	MyUniquePTR(T* ptr) : m_ptr(ptr) { };					// указатель для "владения" через конструктор
	~MyUniquePTR() { delete m_ptr; }						// деструктор позаботится об удалении указателя
	
	// Мы можем явно определить и удалить конструктор копирования с оператором присваивания
	MyUniquePTR(const MyUniquePTR& other) = delete;				// конструктор копирования // копировать нельзя
	MyUniquePTR(MyUniquePTR&& other)							//  перемещать можно
	{
		this->m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
	}
	MyUniquePTR& operator=(const MyUniquePTR& other) = delete;	// оператор присваивания	// присваивать нельзя
	MyUniquePTR& operator=(MyUniquePTR&& other)					// перемещать можно 
	{
		if ( this != &other )
		{
			delete[] this->m_ptr;            
			this->m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
		return *this;
	}

	const T& operator*() const { return *m_ptr; }				// обертка для указателя
	const T* operator->() const { return m_ptr; }				// чтобы пользоваться как объектом
	T& operator*() { return *m_ptr; }				
	T* operator->() { return m_ptr; }		

	//T* MyUniquePTR::GetString() const
	//{
	//	// проверка на пустой указатель
	//	if ( !this )
	//	{
	//		return "NULL...";
	//	}
	//	if ( m_ptr )
	//	{
	//		return m_ptr;
	//	}
	//	else
	//	{
	//		return "ptr empty...";
	//	}
	//};

	/*void MyUniquePTR::SetNewString(T& source)
	{
		delete[] m_ptr;
		m_ptr = source;
	}*/

	operator bool() const
	{ 
		return m_ptr != nullptr;
	}

};

