#pragma once

class MyString
{
public:
	MyString();
	MyString(const char* pName);
	// ���������� �����������
	MyString(const MyString& otherStr);
	~MyString();
	MyString(MyString&& str);		//  move  ����������� �����������
	// ����� ��������� ��������
	const char* GetString() const;
	// ����� ������ ������
	void SetNewString(const char* source);


private:
	char* m_pName;
};



