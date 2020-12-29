#pragma once

class MyString
{
public:
	MyString();
	MyString(const char* pName);

	~MyString();

	// метод получения значения
	const char* GetString() const;
	// метод меняет строку
	void SetNewString(const char* source);
private:
	char* m_pName;
};



