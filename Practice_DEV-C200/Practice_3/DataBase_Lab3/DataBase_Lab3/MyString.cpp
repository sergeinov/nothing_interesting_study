
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
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

//���������� ��������� ������������ =
MyString& MyString::operator=(const MyString& otherStr)
{
    if (this != &otherStr)                       // �������� ��� ����������������
    {
        delete[] this->m_pName;                  // ����������� ���������� ���� ������
        m_pName = new char[strlen(otherStr.m_pName) + 1];   // �������� ������
        strcpy(m_pName, otherStr.m_pName);      // ��������
    }
    return *this;                               // ��� ����������� ����������� ������������ ���������� �� ������ ����� �������
};

//���������� ��������� +
const MyString& MyString::operator+(const MyString& RightObject)
{
    if (RightObject.m_pName)
    {
        strcat(this->m_pName, RightObject.m_pName);      // ������������ �����
    }
    return *this;
};

//���������� ��������� +=
const MyString& MyString::operator+=(const MyString& RightObject)
{
    int size = 0;

    if (RightObject.m_pName)
    {
        size = strlen(RightObject.m_pName) + strlen(this->m_pName) + 1;     // ������ ��� ���� �����
        char* temp = new char[size];            // �������� ������ �� ��������� ����������

        // �������� �� ������ ������ ������ ��������
        if (m_pName)
        {
            strcpy(temp, this->m_pName);            // �������� �� ���������
        }

        strcat(temp, RightObject.m_pName);      // ������������ �����
        delete[] this->m_pName;                 // ����������� ���������� ���� ������
        this->m_pName = temp;                         // ����������� ��������� ��������� �� ��������
    }
    return *this;
};