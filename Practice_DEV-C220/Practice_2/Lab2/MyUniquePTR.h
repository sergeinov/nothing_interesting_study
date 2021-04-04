#pragma once
#include<iostream>


template<typename T> class MyUniquePTR
{
	T* m_ptr;					// ��������� �� ������ ���� ����
public:
	MyUniquePTR() = default;								// ��������� ��� "��������" ����� �����������
	MyUniquePTR(T* ptr = nullptr) : m_ptr(ptr) { };		
	~MyUniquePTR() { delete m_ptr; }						// ���������� ����������� �� �������� ���������
	
	// �� ����� ���� ���������� � ������� ����������� ����������� � ���������� ������������
	MyUniquePTR(const MyUniquePTR& other) = delete;				// ����������� �����������
	MyUniquePTR& operator=(const MyUniquePTR& other) = delete;	// �������� ������������

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

