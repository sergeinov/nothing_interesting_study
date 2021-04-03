#pragma once
#include<iostream>

class MyString
{
private:
	char* m_pName;
public:
	/*
	*	������������
	*/
	MyString();
	MyString(const char* pName);			// ����������� � �����������

	~MyString();							// ����������

	MyString(const MyString& otherStr);		// ����������� �����������
	MyString(MyString&& otherStr);			// ����������� ����������� move

	/*
	*	������
	*/
	const char* GetString() const;	// ����� ��������� ��������
	void SetNewString(const char* source);	// ����� ������ ������

	/*
	*	����������
	*/
	MyString& operator=(const MyString& otherStr);		//���������� ��������� ������������ = ��� �������
	MyString& operator=(const char* otherStr);			// ��� ������ ������ ����   = "programmer";
	MyString& operator=(MyString&& otherStr);			//	��� ���������� ������� ������
	bool operator==(const char* str) const;

	friend std::ostream& operator<<(std::ostream& out, const MyString& RightObject);	// ���������� ��������� << 
	const MyString operator+(const MyString& RightObject);								//���������� ��������� +
	const MyString& operator+=(const MyString& RightObject);							//���������� ��������� +=
};




