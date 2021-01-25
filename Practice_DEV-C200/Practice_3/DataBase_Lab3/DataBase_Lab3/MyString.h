#pragma once
#include<iostream>

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
	MyString(MyString&& object);		// конструктор move

	// метод получения значения
	const char* GetString() const;
	// метод меняет строку
	void SetNewString(const char* source);

	//Перегрузка оператора присваивания =
	MyString& operator=(const MyString& otherStr);	// для обьекта

	MyString& operator=(MyString&& other);		//	для временного обьекта справа
	MyString& operator=(const char* str);		// для строки справа "programmer"
	bool operator==(const char* str) const;

	// Перегрузка оператора << 
	// для вывода m_job в при перегрузке в MyData std::ostream& operator<<(std::ostream& os, const MyData& data)
	friend std::ostream& operator<<(std::ostream& os, const MyString& RightObject);

	//Перегрузка оператора +
	const MyString operator+(const MyString& RightObject);

	//Перегрузка оператора +=
	const MyString& operator+=(const MyString& RightObject);
};




