#pragma once
#include "MyString.h"
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
	//конструкторы
	MyData();
	MyData(Sex s, size_t age, const char* job, float salary);
	

	// методы перегрузки

	//friend ostream& operator<<(ostream& os, const MyData& data);

};

