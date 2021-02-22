
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include"MyString.h"

/*
*   ������������
*/
MyString::MyString() : m_pName(nullptr) {};

MyString::MyString(const char* pName)
{
    if (pName)
    {
        int size = strlen(pName) + 1;
        m_pName = new char[size];
        memcpy(m_pName, pName, size);
        //strcpy(m_pName, pName);
    }
    else
    {
        pName = nullptr;
    }   
};

MyString::~MyString()                           // ����������
{
    delete[] m_pName;
};

MyString::MyString(const MyString& otherStr)    // ���������� �����������
{
    if (otherStr.m_pName)
    {
        // �������� ������ ��� ������ m_pStr � ��������  � ��� �������� ������������ pStr
        this->m_pName = new char[strlen(otherStr.m_pName) + 1];
        strcpy(this->m_pName, otherStr.m_pName);
    }
    else
    {
        this->m_pName = nullptr;
    }
};

MyString::MyString(MyString&& otherStr)         // ����������� ����������� move
{
    // TODO
    this->m_pName = otherStr.m_pName;
    otherStr.m_pName = nullptr;
};

/*
*   ����������
*/
//���������� ��������� ������������ =  ��� �������  ����: str1 = str2;
MyString& MyString::operator=(const MyString& otherStr)
{
    if (this != &otherStr)                       // �������� ��� ����������������
    {
        delete[] this->m_pName;                  // ����������� ���������� ���� ������
        if (otherStr.m_pName)
        {
            this->m_pName = new char[strlen(otherStr.m_pName) + 1];   // �������� ������
            strcpy(this->m_pName, otherStr.m_pName);                  // ��������
        }
        else
        {
            this->m_pName = nullptr;
        }     
    }
    return *this;                               // ��� ����������� ����������� ������������ ���������� �� ������ ����� �������
};

//���������� ��������� ������������ = ��� ���������� ������� ������ ����: = MyString("CCC");
MyString& MyString::operator=(MyString&& otherStr)
{
    // TODO
    if (this != &otherStr)
    {
        delete[] this->m_pName;             // ������ ��������� �� ������
        this->m_pName = otherStr.m_pName;   // ����������� ����� �� ����������  �������
        otherStr.m_pName = nullptr;         // ������� ����� � ���������� �������
    }
    return *this;
};

//���������� ��������� ������������ = ��� ������ ������ ����: = "programmer";
MyString& MyString::operator=(const char* otherStr)
{
    // TODO
    delete[] this->m_pName;
    if (otherStr)
    {
        this->m_pName = new char[strlen(otherStr) + 1];
        strcpy(this->m_pName, otherStr);
    }
    else
    {
        this->m_pName = nullptr;
    }
    return *this;
};

//���������� ��������� +
const MyString MyString::operator+(const MyString& RightObject)
{
    int size = 0;

    if (RightObject.m_pName)
    {
        if (this->m_pName)
        {
            size = strlen(RightObject.m_pName) + strlen(this->m_pName) + 1;     // ������ ��� ���� �����

            char* temp = new char[size];            // �������� ������ �� ��������� ����������
            strcpy(temp, this->m_pName);            // �������� �� ���������
            //  temp[0] = '\0';                     // � ������ ������ ���������� \0        
            strcat(temp, RightObject.m_pName);      // ������������ �����
            MyString str(temp);                     // ����� ������������ �����������
            delete[] temp;                          // �����������  ������
            return str;
        }
        else
        {
            return RightObject;
        }
        // ����������� �����������
        // ����������
    }
    return *this;
};

//���������� ��������� +=
const MyString& MyString::operator+=(const MyString& RightObject)
{
    /*
    -�������� ������ ��� ���� �����, �����
    -����������� � ����� ������ ������ ������,
    -����� strcat,
    -������� this->m_pName,
    -��������� ��������� m_pName = temp.
    */
    int size = 0;

    if (RightObject.m_pName)
    {
        if (this->m_pName)
        {
            size = strlen(RightObject.m_pName) + strlen(this->m_pName) + 1;     // ������ ��� ���� �����
            char* temp = new char[size];            // �������� ������ �� ��������� ����������
            strcpy(temp, this->m_pName);            // �������� �� ���������
               // temp[0] = '\0';                 // � ������ ������ ���������� \0        
                                                // ����� strcat ����� ����� ������ ��� ������������ ������ �����
            strcat(temp, RightObject.m_pName);      // ������������ �����
            delete[] this->m_pName;                 // ����������� ���������� ���� ������
            this->m_pName = temp;                   // ����������� ��������� ��������� �� ��������
        }
        else
        {
            return RightObject;
        }
    }
    return *this;
};

// �������� ���������� (���������� ��� ���� �����)
bool MyString::operator==(const char* str) const 
{
    // ��������� ���� ��������� ����� � ������ �������
    if (str)
    {
        return !strcmp(this->m_pName, str);
    }
    else
    {
        return false;
    }   
};

/*
*   ������
*/

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