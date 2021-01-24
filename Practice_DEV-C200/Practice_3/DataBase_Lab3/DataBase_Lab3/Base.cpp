#include "Base.h"
#include<string.h>

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

};