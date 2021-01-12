
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include"MyString.h"

// конструкторы
MyString::MyString()
{
	m_pName = nullptr;
};
MyString::MyString(const char* pName)
{
	m_pName = new char[strlen(pName) + 1];
	strcpy(m_pName, pName);
};

//  move  конструктор копирования
MyString::MyString(MyString&& str)
{
    // копируем
    this->m_pName = new char[strlen(str.m_pName) + 1];  // выделяем память
    strcpy(this->m_pName, str.m_pName);                 // копируем
    delete[] str.m_pName;                              // удаляем временный объект
    str.m_pName = nullptr;
};

// деструктор
MyString::~MyString()
{
	delete[] m_pName;
}

// коструктор копирования
MyString::MyString(const MyString& otherStr)
{
    if (otherStr.m_pName)
    {
        // выделяем память под строку m_pStr и копируем  в нее параметр конструктора pStr
        m_pName = new char[strlen(otherStr.m_pName) + 1];
        strcpy(m_pName, otherStr.m_pName);
    }
    else
    {
        m_pName = 0;
    }
};

// метод получения значения
const char* MyString::GetString() const
{
    // проверка на пустой указатель
    if (!this)
    {
        return "NULL...";
    }

    if (m_pName)
    {
        return m_pName;
    }
    else
    {
        return "empty...";
    }
};

// метод меняет строку
void MyString::SetNewString(const char* source)
{
    delete[] m_pName;
    m_pName = new char[strlen(source) + 1];
    strcpy(m_pName, source);

}