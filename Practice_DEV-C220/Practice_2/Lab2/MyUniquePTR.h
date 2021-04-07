#pragma once
#include<iostream>


template<typename T> class MyUniquePTR
{
	T* m_ptr{};												// ��������� �� ������ ���� ����
public:
	MyUniquePTR() = default;								
	MyUniquePTR(T* ptr) : m_ptr(ptr) { };					// ��������� ��� "��������" ����� �����������
	~MyUniquePTR() { delete m_ptr; }						// ���������� ����������� �� �������� ���������
	
	// �� ����� ���� ���������� � ������� ����������� ����������� � ���������� ������������
	MyUniquePTR(const MyUniquePTR& other) = delete;				// ����������� ����������� // ���������� ������
	MyUniquePTR(MyUniquePTR&& other)							//  ���������� �����
	{
		this->m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
	}
	MyUniquePTR& operator=(const MyUniquePTR& other) = delete;	// �������� ������������	// ����������� ������
	MyUniquePTR& operator=(MyUniquePTR&& other)					// ���������� ����� 
	{
		if ( this != &other )
		{
			delete[] this->m_ptr;            
			this->m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
		return *this;
	}

	const T& operator*() const { return *m_ptr; }				// ������� ��� ���������
	const T* operator->() const { return m_ptr; }				// ����� ������������ ��� ��������
	T& operator*() { return *m_ptr; }				
	T* operator->() { return m_ptr; }		

	//T* MyUniquePTR::GetString() const
	//{
	//	// �������� �� ������ ���������
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

