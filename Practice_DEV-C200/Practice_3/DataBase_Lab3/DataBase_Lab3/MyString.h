#pragma once
#include<iostream>

class MyString
{
private:
	char* m_pName;
public:
	/*
	*	конструкторы
	*/
	MyString();
	MyString(const char* pName);			// конструктор с параметрами

	~MyString();							// деструктор

	MyString(const MyString& otherStr);		// конструктор копирования
	MyString(MyString&& otherStr);			// конструктор перемещения move

	/*
	*	методы
	*/
	const char* GetString() const;	// метод получения значения
	void SetNewString(const char* source);	// метод меняет строку

	/*
	*	перегрузки
	*/
	MyString& operator=(const MyString& otherStr);		//Перегрузка оператора присваивания = для обьекта
	MyString& operator=(const char* otherStr);			// для строки справа типа   = "programmer";
	MyString& operator=(MyString&& otherStr);			//	для временного обьекта справа
	bool operator==(const char* str) const;

	friend std::ostream& operator<<(std::ostream& out, const MyString& RightObject);	// Перегрузка оператора << 
	const MyString operator+(const MyString& RightObject);								//Перегрузка оператора +
	const MyString& operator+=(const MyString& RightObject);							//Перегрузка оператора +=
};




