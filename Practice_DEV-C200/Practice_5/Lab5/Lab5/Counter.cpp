#include "Counter.h"
#include <iomanip>

/*
*	статические переменные
*/
Counter*  pHead = nullptr;
unsigned int m_curCounters = 0;

/*
*	конструкторы
*/
Counter::Counter(const char* p) : m_nOwners(1)
{
	this->m_pStr = new char[strlen(p) + 1];
	strcpy(this->m_pStr, p);					// копируем 

	//включить в список
	
};


Counter::~Counter()
{
	delete[] m_pStr;	// удаляем созданную строку 

	//исключить из списка

};

/*
*	методы
*/
void Counter::AddOwner()	// добавляем владельца
{
	m_nOwners++;
	//m_curCounters++;
};
void Counter::RemoveOwner()	// удаляем владельца
{
	m_nOwners--;
	//m_curCounters--;
	if (m_nOwners == 0)
	{
		delete this;		// вызывает конструктор удаления ~Counter()
	}
}
Counter* Counter::find(const char* str)		// для поиска  похожей строки
{
	Counter* p = pHead;		// указатель на начало списка
	while ( p != nullptr )
	{
		if ( !strcmp(str, p->m_pStr) )
		{
			p->m_nOwners++;				// если похожая строка , добаваляем владельца
			return p;					// возвращаем адрес
		}
		p = p->pNext;					// пермещаемся на следующую строку
	}
	return new Counter(str);	// если не нашли создалт новую, через конструктор
}
;

/*
*	перегрузки
*/