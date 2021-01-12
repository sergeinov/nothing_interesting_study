
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

//  move  ����������� �����������
MyString::MyString(MyString&& str)
{
    // ��������
    this->m_pName = new char[strlen(str.m_pName) + 1];  // �������� ������
    strcpy(this->m_pName, str.m_pName);                 // ��������
    delete[] str.m_pName;                              // ������� ��������� ������
    str.m_pName = nullptr;
};

// ����������
MyString::~MyString()
{
	delete[] m_pName;
}

// ���������� �����������
MyString::MyString(const MyString& otherStr)
{
    if (otherStr.m_pName)
    {
        // �������� ������ ��� ������ m_pStr � ��������  � ��� �������� ������������ pStr
        m_pName = new char[strlen(otherStr.m_pName) + 1];
        strcpy(m_pName, otherStr.m_pName);
    }
    else
    {
        m_pName = 0;
    }
};

// ����� ��������� ��������
const char* MyString::GetString() const
{
    // �������� �� ������ ���������
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

// ����� ������ ������
void MyString::SetNewString(const char* source)
{
    delete[] m_pName;
    m_pName = new char[strlen(source) + 1];
    strcpy(m_pName, source);

}