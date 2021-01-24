#pragma once
#include"Pair.h"

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
	// конструктор копирования не обходим, когда есть динамически выделенная память
	Base(const Base& bd);
	Base(Base&& bd);

	//перезагрузка
	Base& operator=(const Base& bd); // оптимизированный
	Base& operator=(Base&& bd);
	MyData& operator[](const char* key);
	int deletePair(const char* key);	// удаление сотрудника из базы
	
	//friend ostream& operator<<(osream& os, const Base& bd);
};

