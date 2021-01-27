#pragma once
#include<iostream>

class MyString
{
private:
	char* m_pName;
public:

	//конструкторы
	MyString();
	MyString(const char* pName);  // конструктор с параметрами
	~MyString();	// деструктор
	MyString(const MyString& otherStr);	// конструктор копирования
	//MyString(MyString&& object);		// конструктор перемещения move

	// перегрузки 
	MyString& operator=(const MyString& otherStr);	//Перегрузка оператора присваивания = для обьекта
	//MyString& operator=(MyString&& other);		//	для временного обьекта справа
	//MyString& operator=(const char* str);		    // для строки справа "programmer"
	bool operator==(const char* str) const;
	friend std::ostream& operator<<(std::ostream& os, const MyString& RightObject); // Перегрузка оператора << 
																					// для вывода m_job в при перегрузке в MyData std::ostream& operator<<(std::ostream& os, const MyData& data)
	const MyString operator+(const MyString& RightObject); //Перегрузка оператора +
	const MyString& operator+=(const MyString& RightObject); //Перегрузка оператора +=

	// методы
	const char* GetString() const;	// метод получения значения
	void SetNewString(const char* source);	// метод меняет строку
};




