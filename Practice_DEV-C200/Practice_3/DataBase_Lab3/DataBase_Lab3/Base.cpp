#include "Base.h"
#include<string.h>
#include<iostream>

// ������������
Base::Base() : count(0), capacity(2), pBase(new Pair[2]) {}; 
Base::~Base() { delete[] pBase; };


Base::Base(const Base& bd) : count(bd.count), capacity(bd.count)	// ����������� �����������
{
	if (count == 0)
	{
		this->pBase = nullptr;
	}
	else {
		this->pBase = new Pair[count];
		for (size_t i = 0; i < count; i++)
		{
			this->pBase[i] = bd.pBase[i];
		}
	}
	
};
Base::Base(Base&& bd): count(bd.count), capacity(bd.count), pBase(bd.pBase)	// ����������� �����������
{
	bd.pBase = nullptr;
	bd.count = 0;
	bd.capacity = 0;
};

// ������������

Base& Base::operator=(const Base& bd)	// �������� ������������
{
	if (this != &bd)                       // �������� ��� ����������������
	{
		delete[] this->pBase;                  // ����������� ���������� ���� ������
		this->pBase = bd.pBase;
		this->count = bd.count;
		this->capacity = bd.capacity;
	}
	return *this;
};

MyData& Base::operator[](const char* key)
{
	// �������� ���� �� � ���� ����� ����-���
	for (size_t i = 0; i < this->count; i++)
	{
		if (this->pBase[i].key == key)
		{
			// ���������� ������ �� ������� ������ MyData			
			return this->pBase[i].data;			
												
		}	
	}

	// ���������� ����� ���� � ����
	if (this->capacity <= this->count)
	{
		// ��������� ������ ������ � ����
		// ���������������� ������
		this->capacity++;
		Pair* p = new Pair[capacity];
		for (size_t i = 0; i < this->count; i++)
		{
			p[i] = std::move(this->pBase[i]);				// �������� ����������� �� ���������
		}
		delete[] this->pBase;
		this->pBase = p;
	}
	// ��������� ����
	this->pBase[this->count].key = key;			// �������� �������������  MyString operator=
	this->count++;								// ����������� ���������� ������ � ����
	return this->pBase[this->count - 1].data;	// ���������� ������ MyData �� ������ ����������� count 
												// �������� ������ �� MyData �� ���������
};

// ������

// ������� ����������
void Base::deletePair(const char* key)
{

};