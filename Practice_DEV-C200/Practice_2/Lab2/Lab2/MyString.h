#pragma once

class MyString
{
public:
	MyString();
	MyString(const char* pName);

	~MyString();

	// ����� ��������� ��������
	const char* GetString() const;

private:
	char* m_pName;
};



