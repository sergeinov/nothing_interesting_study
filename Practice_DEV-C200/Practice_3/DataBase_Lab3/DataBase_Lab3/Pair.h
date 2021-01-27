#pragma once
//#include "MyString.h"
#include "MyData.h"
#include<iostream>

class Pair
{
private:
	MyString key;		// ключ - фамилия
	MyData data;		// данные о сотруднике
//public:
	// конструкторы
	Pair();
	Pair(const char* key, const MyData& data);

	// методы
	bool operator==(const char* key) const;		// для проверки есть ли в базе уже

	// перегрузки
	friend std::ostream& operator<<(std::ostream& os, const Pair& pair);

	friend class Base;
};

