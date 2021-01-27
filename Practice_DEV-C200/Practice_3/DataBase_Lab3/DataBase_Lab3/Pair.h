#pragma once
//#include "MyString.h"
#include "MyData.h"
#include<iostream>

class Pair
{
private:
	MyString key;		// ���� - �������
	MyData data;		// ������ � ����������
//public:
	// ������������
	Pair();
	Pair(const char* key, const MyData& data);

	// ������
	bool operator==(const char* key) const;		// ��� �������� ���� �� � ���� ���

	// ����������
	friend std::ostream& operator<<(std::ostream& os, const Pair& pair);

	friend class Base;
};

