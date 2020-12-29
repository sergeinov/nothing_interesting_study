
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

// деструктор
MyString::~MyString()
{
	delete[] m_pName;
}

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