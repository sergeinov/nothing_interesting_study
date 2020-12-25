
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include"MyString.h"

// ������������
MyString::MyString()
{
	m_pName = nullptr;
};
MyString::MyString(const char* pName)
{
	m_pName = new char[strlen(pName) + 1];
	strcpy(m_pName, pName);
};

// ����������
MyString::~MyString()
{
	delete[] m_pName;
}

// ����� ��������� ��������
const char* MyString::GetString() const
{
    if (m_pName)
    {
        return m_pName;
    }
    else
    {
        return "empty...";
    }
};