#pragma once
class MyString
{
private:
	char* m_pStr;
public:
	/*
	*	конструкторы
	*/
	MyString();
	MyString(const char* m_pStr);			// конструктор с параметрами

	~MyString();							// деструктор

	MyString(const MyString& otherStr);		// конструктор копирования
	MyString(MyString&& otherStr);			// конструктор перемещения move

	/*
	*	методы
	*/
	//const char* GetString() const;	// метод получения значения
	//void SetNewString(const char* source);	// метод меняет строку

	/*
	*	перегрузки
	*/
	MyString& operator=(const MyString& otherStr);		//Перегрузка оператора присваивания = для обьекта
	MyString& operator=(MyString&& otherStr);
};

