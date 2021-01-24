#pragma once
#include "MyString.h"
#include "MyData.h"
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

	friend class Base;
	//friend ostream& operator<<(ostream& os, const Pair& pair);
};

