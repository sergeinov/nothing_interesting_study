#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include"MyString.h"

/*
*   ������������
*/
MyString::MyString() : m_pStr(nullptr) { };

MyString::MyString(const char* Str)
{
    if ( Str )
    {
        int size = strlen(Str) + 1;
        m_pStr = new char[ size ];
        memcpy(m_pStr, Str, size);
        //strcpy(m_pName, pName);
    }
    else
    {
        Str = nullptr;
    }
};

MyString::~MyString()                           // ����������
{
    delete[] m_pStr;
};

MyString::MyString(const MyString& otherStr)    // ���������� �����������
{
    if ( otherStr.m_pStr )
    {
        this->m_pStr = new char[ strlen(otherStr.m_pStr) + 1 ];
        strcpy(this->m_pStr, otherStr.m_pStr);
    }
    else
    {
        this->m_pStr = nullptr;
    }
};

MyString::MyString(MyString&& otherStr)         // ����������� ����������� move
{
    this->m_pStr = otherStr.m_pStr;
    otherStr.m_pStr = nullptr;
};

/*
*   ����������
*/
MyString& MyString::operator=(const MyString& otherStr)     //���������� ��������� �����������
{
    if ( this != &otherStr )                       // �������� ��� ����������������
    {
        delete[] this->m_pStr;                      // ����������� ���������� ���� ������
        if ( otherStr.m_pStr )
        {
            this->m_pStr = new char[ strlen(otherStr.m_pStr) + 1 ];   // �������� ������
            strcpy(this->m_pStr, otherStr.m_pStr);                  // ��������
        }
        else
        {
            this->m_pStr = nullptr;
        }
    }
    return *this;                               // ��� ����������� ����������� ������������ ���������� �� ������ ����� �������
}

MyString& MyString::operator=(MyString&& otherStr)
{
    if ( this != &otherStr )
    {
        delete[] this->m_pStr;
        m_pStr = otherStr.m_pStr;
        otherStr.m_pStr = nullptr;
    }
    return *this;
}


/*
*   ������
*/
