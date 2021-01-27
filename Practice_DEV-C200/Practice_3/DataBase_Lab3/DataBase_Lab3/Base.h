#pragma once
#include"Pair.h"
#include<iostream>

class Base
{
private:
	Pair* pBase;		// указатель на базу
	size_t count;		// количество сотрудников
	size_t capacity;	// размер базы
public:
	//конструкторы
	Base();
	~Base();
	Base(const Base& bd); // конструктор копирования необходим, когда есть динамически выделенная память
	Base(Base&& bd);

	//перезагрузки
	Base& operator=(const Base& bd);	// оптимизированный оператор присваивания
	Base& operator=(Base&& bd);			// оператор перемещения move
	MyData& operator[](const char* key);
	friend std::ostream& operator<<(std::ostream& os, const Base& bd);

	// методы
	void deletePair(const char* key);	// удаление сотрудника из базы	
	
};

