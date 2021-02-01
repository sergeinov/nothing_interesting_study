#include "Counter.h"
#include <iomanip>

/*
*	конструкторы
*/
Counter::Counter(const char* p) : m_nOwners(1)
{
	this->m_pStr = new char[strlen(p) + 1];
	strcpy(this->m_pStr, p);					// копируем 
};

Counter::~Counter()
{
	delete[] m_pStr;	// удаляем созданную строку 
};

/*
*	методы
*/
void Counter::AddOwner()	// добавляем владельца
{
	m_nOwners++;
	m_curCounters++;
};
void Counter::RemoveOwner()	// удаляем владельца
{
	m_nOwners--;
	m_curCounters--;
	if (m_nOwners == 0)
	{
		delete this;		// вызывает конструктор удаления ~Counter()
	}
};

/*
*	перегрузки
*/