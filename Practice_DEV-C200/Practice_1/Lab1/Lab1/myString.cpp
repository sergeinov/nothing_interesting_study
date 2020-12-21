
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "myString.h"
using namespace std;

// ����������� ������������.
MyString::MyString(const char* pStr)
{
	
	// �������� ������ ��� ������ m_pStr � ��������  � ��� �������� ������������ pStr
	m_pStr = new char[strlen(pStr) + 1];
	strcpy(m_pStr, pStr);
};

// ����������� �����������.
MyString::~MyString()
{
	// ������� ��������� �� �������
	delete[] m_pStr;
};

// ���������� �����������
MyString::MyString(const MyString& otherStr)
{
	// �������� ������ ��� ������ m_pStr � ��������  � ��� �������� ������������ pStr
	m_pStr = new char[strlen(otherStr.m_pStr) + 1];
	strcpy(m_pStr, otherStr.m_pStr);
};

// ������� ������ ������
void MyString::SetNewString(char* source)
{
	m_pStr = new char[strlen(source) + 1];
	strcpy(m_pStr, source);
}
