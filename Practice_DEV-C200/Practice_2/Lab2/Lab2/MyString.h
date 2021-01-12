#pragma once

class MyString
{
public:
	MyString();
	MyString(const char* pName);
	// коструктор копирования
	MyString(const MyString& otherStr);
	~MyString();
	MyString(MyString&& str);		//  move  конструктор копирования
	// метод получения значения
	const char* GetString() const;
	// метод меняет строку
	void SetNewString(const char* source);


private:
	char* m_pName;
};



