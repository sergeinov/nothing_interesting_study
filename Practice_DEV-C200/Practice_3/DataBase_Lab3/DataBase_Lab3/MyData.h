#pragma once
#include "MyString.h"
#include<iostream>

class MyData 

{
public:
	enum Sex {UNDEF, MALE, FEMALE};
private:
	Sex sex;
	size_t m_age;
	MyString m_job;
	float m_salary;
public:
	//������������
	MyData();
	MyData(Sex s, size_t age, const char* job, float salary);
	

	// ������ ����������
	// ��� ������ ������ � ���������� std::cout << myBase["Petrova"];
	friend std::ostream& operator<<(std::ostream& os, const MyData& data);

};

