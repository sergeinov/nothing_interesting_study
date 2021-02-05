#pragma once

class Counter;		// неполное предварительное обьявление
class MyString
{
private:
	Counter* m_pMyCounter;		// указатель на свой Counter

	//static Counter* ExistCounter(const char* str);

public:

	/*
	*	конструкторы
	*/
	MyString(const char* str);
	MyString(const MyString& object);	// конструктор копирования
	MyString(MyString&& otherStr);			// конструктор перемещения
	~MyString();
	/*
	*	методы
	*/
	const char* GetString() const;	// метод получения значения
	void SetNewString(const char* source);	// метод меняет строку

	/*
	*	перегрузки
	*/
	MyString& operator=(const MyString& object);	// перегрузка п
	//friend std::ostream& operator<<(std::ostream& out, const MyString& RightObject);	// Перегрузка оператора << 
};

