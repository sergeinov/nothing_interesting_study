#include "Base.h"
#include<string.h>

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

};