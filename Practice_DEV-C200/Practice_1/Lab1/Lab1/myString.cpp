
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "myString.h"
using namespace std;

// Определение конструктора.
MyString::MyString() { m_pStr = nullptr; };

MyString::MyString(const char* pStr)
{
	
	// выделяем память под строку m_pStr и копируем  в нее параметр конструктора pStr
	m_pStr = new char[strlen(pStr) + 1];
	strcpy(m_pStr, pStr);
};

// Определение деструктора.
MyString::~MyString()
{
	// удаляем указатель со строкой
	delete[] m_pStr;
};

// коструктор копирования
MyString::MyString(const MyString& otherStr)
{
	if (otherStr.m_pStr)
	{
		// выделяем память под строку m_pStr и копируем  в нее параметр конструктора pStr
		m_pStr = new char[strlen(otherStr.m_pStr) + 1];
		strcpy(m_pStr, otherStr.m_pStr);
	}
	else
	{
		m_pStr = 0;
	}
};

// функция меняет строку
void MyString::SetNewString(const char* source)
{
	delete[] m_pStr;
	m_pStr = new char[strlen(source) + 1];
	strcpy(m_pStr, source);

}
