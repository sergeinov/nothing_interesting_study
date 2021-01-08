#pragma once

class MyString
{
private:
	char* m_pName;
public:
	//конструкторы
	MyString();
	MyString(const char* pName);
	// деструктор
	~MyString();

	// конструктор копирования
	MyString(const MyString& otherStr);

	// метод получения значения
	const char* GetString() const;
	// метод меняет строку
	void SetNewString(const char* source);

	//Перегрузка оператора присваивания =
	MyString& operator=(const MyString& otherStr);

};



