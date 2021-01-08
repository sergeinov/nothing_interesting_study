#pragma once

class MyString
{
private:
	char* m_pName;
public:
	//������������
	MyString();
	MyString(const char* pName);
	// ����������
	~MyString();

	// ����������� �����������
	MyString(const MyString& otherStr);

	// ����� ��������� ��������
	const char* GetString() const;
	// ����� ������ ������
	void SetNewString(const char* source);

	//���������� ��������� ������������ =
	MyString& operator=(const MyString& otherStr);

};



