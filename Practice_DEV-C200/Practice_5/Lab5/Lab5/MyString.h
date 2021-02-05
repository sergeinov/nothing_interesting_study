#pragma once

class Counter;		// �������� ��������������� ����������
class MyString
{
private:
	Counter* m_pMyCounter;		// ��������� �� ���� Counter

	//static Counter* ExistCounter(const char* str);

public:

	/*
	*	������������
	*/
	MyString(const char* str);
	MyString(const MyString& object);	// ����������� �����������
	MyString(MyString&& otherStr);			// ����������� �����������
	~MyString();
	/*
	*	������
	*/
	const char* GetString() const;	// ����� ��������� ��������
	void SetNewString(const char* source);	// ����� ������ ������

	/*
	*	����������
	*/
	MyString& operator=(const MyString& object);	// ���������� �
	//friend std::ostream& operator<<(std::ostream& out, const MyString& RightObject);	// ���������� ��������� << 
};

