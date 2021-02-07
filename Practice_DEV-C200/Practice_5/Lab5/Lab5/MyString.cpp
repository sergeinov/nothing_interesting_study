#include "MyString.h"
#include"Counter.h"		// в тему использования метода неполного обьявления

/*
*	конструкторы
*/
MyString::MyString(const char* str)
{
	
	if (str)
	{
		//TODO
		// написать поиск по списку, если нет такой строки в списке тогда создаем
		//m_pMyCounter = new Counter(str);	// создаем обьект
		m_pMyCounter = Counter::find(str);
	}
	else
	{
		m_pMyCounter = nullptr;
	}
};

MyString::MyString(const MyString& object)		// конструктор копирования
{
	this->m_pMyCounter = object.m_pMyCounter;	// присваиваем указатель на строку
	this->m_pMyCounter->AddOwner();				// создаем владельца по этому адресу
};

MyString::MyString(MyString&& otherStr)			// // перемещающий конструктор move
{
	// TODO
	this->m_pMyCounter = otherStr.m_pMyCounter;
	otherStr.m_pMyCounter = nullptr;
};			

MyString::~MyString()
{
	if (m_pMyCounter)	// проверка на нулевой указатель
	{
		m_pMyCounter->RemoveOwner();	// удаляем владельца
	}
}
;

/*
*	методы
*/
const char* MyString::GetString() const		// метод получения значения
{
	// TODO
	if ( m_pMyCounter->m_pStr )
	{
		return m_pMyCounter->m_pStr;
	}
	return "empty";
};

void MyString::SetNewString(const char* source)
{
		// TODO

};

/*
*	перегрузки
*/

MyString& MyString::operator=(const MyString& object)
{
	// TODO
	if ( this->m_pMyCounter != object.m_pMyCounter )
	{
		if ( this->m_pMyCounter )
		{
			this->m_pMyCounter->RemoveOwner();
		}
		this->m_pMyCounter = object.m_pMyCounter;
		if ( this->m_pMyCounter )
		{
			this->m_pMyCounter->AddOwner();
		}
	}
	return *this;
};
