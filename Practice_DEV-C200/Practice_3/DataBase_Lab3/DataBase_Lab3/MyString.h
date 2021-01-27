#pragma once
#include<iostream>

class MyString
{
private:
	char* m_pName;
public:

	//������������
	MyString();
	MyString(const char* pName);  // ����������� � �����������
	~MyString();	// ����������
	MyString(const MyString& otherStr);	// ����������� �����������
	//MyString(MyString&& object);		// ����������� ����������� move

	// ���������� 
	MyString& operator=(const MyString& otherStr);	//���������� ��������� ������������ = ��� �������
	//MyString& operator=(MyString&& other);		//	��� ���������� ������� ������
	//MyString& operator=(const char* str);		    // ��� ������ ������ "programmer"
	bool operator==(const char* str) const;
	friend std::ostream& operator<<(std::ostream& os, const MyString& RightObject); // ���������� ��������� << 
																					// ��� ������ m_job � ��� ���������� � MyData std::ostream& operator<<(std::ostream& os, const MyData& data)
	const MyString operator+(const MyString& RightObject); //���������� ��������� +
	const MyString& operator+=(const MyString& RightObject); //���������� ��������� +=

	// ������
	const char* GetString() const;	// ����� ��������� ��������
	void SetNewString(const char* source);	// ����� ������ ������
};




