#include "MyData.h"
#include <string.h>

// конструкторы
MyData::MyData() : m_job("undefined")
{
	sex = UNDEF;
	m_age = 0;
	//m_job = nullptr;
	m_salary = .0;
};
MyData::MyData(Sex s, size_t age, const char* job, float salary) : m_job(job)	// конструктор с параметрами
{
	sex = s;
	m_age = age;
	m_salary = salary;
}


// методы


// перегрузки
