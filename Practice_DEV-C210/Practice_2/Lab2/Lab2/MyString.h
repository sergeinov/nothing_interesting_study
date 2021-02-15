#pragma once
class MyString
{
private:
	char* m_pStr;
public:
	/*
	*	������������
	*/
	MyString();
	MyString(const char* m_pStr);			// ����������� � �����������

	~MyString();							// ����������

	MyString(const MyString& otherStr);		// ����������� �����������
	MyString(MyString&& otherStr);			// ����������� ����������� move

	/*
	*	������
	*/
	//const char* GetString() const;	// ����� ��������� ��������
	//void SetNewString(const char* source);	// ����� ������ ������

	/*
	*	����������
	*/
	MyString& operator=(const MyString& otherStr);		//���������� ��������� ������������ = ��� �������
	MyString& operator=(MyString&& otherStr);
};

