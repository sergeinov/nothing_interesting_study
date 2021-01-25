#include "Base.h"
#include<string.h>
#include<iostream>

// конструкторы
Base::Base() : count(0), capacity(2), pBase(new Pair[2]) {}; 
Base::~Base() { delete[] pBase; };


Base::Base(const Base& bd) : count(bd.count), capacity(bd.count)	// конструктор копирования
{
	if (count == 0)
	{
		this->pBase = nullptr;
	}
	else {
		this->pBase = new Pair[count];
		for (size_t i = 0; i < count; i++)
		{
			this->pBase[i] = bd.pBase[i];
		}
	}
	
};
Base::Base(Base&& bd): count(bd.count), capacity(bd.count), pBase(bd.pBase)	// конструктор перемещения
{
	bd.pBase = nullptr;
	bd.count = 0;
	bd.capacity = 0;
};

// перезагрузка

Base& Base::operator=(const Base& bd)	// оператор присваивания
{
	if (this != &bd)                       // проверка для самоприсваивания
	{
		delete[] this->pBase;                  // освобождаем предидущий блок памяти
		this->pBase = bd.pBase;
		this->count = bd.count;
		this->capacity = bd.capacity;
	}
	return *this;
};

MyData& Base::operator[](const char* key)
{
	// проверка есть ли в базе такой ключ-имя
	for (size_t i = 0; i < this->count; i++)
	{
		if (this->pBase[i].key == key)
		{
			// возвращаем ссылку на текущие данные MyData			
			return this->pBase[i].data;			
												
		}	
	}

	// добавление новый ключ в базу
	if (this->capacity <= this->count)
	{
		// добавляем резерв памяти в базе
		// перераспределяем память
		this->capacity++;
		Pair* p = new Pair[capacity];
		for (size_t i = 0; i < this->count; i++)
		{
			p[i] = std::move(this->pBase[i]);				// оператор перемещения по умолчанию
		}
		delete[] this->pBase;
		this->pBase = p;
	}
	// добавляем ключ
	this->pBase[this->count].key = key;			// работает перегруженный  MyString operator=
	this->count++;								// увеличиваем количество ключей в базе
	return this->pBase[this->count - 1].data;	// возвращаем ссылку MyData на данные предидущего count 
												// вернется ссылка на MyData по умолчанию
};

// методы

// удалить сотрудника
void Base::deletePair(const char* key)
{

};