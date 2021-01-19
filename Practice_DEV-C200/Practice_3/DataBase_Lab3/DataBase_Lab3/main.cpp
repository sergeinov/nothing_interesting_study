#include <iostream>
#include<tchar.h>
#include"MyString.h"
#include"MyData.h"
#include"Base.h"

#define	  stop __asm nop

// глобальные методы перегрузки операторов

int _tmain(int argc, _TCHAR* argv[])
{
	//Реализуйте:
	//добавление сотрудников в базу
	//исключение
	//вывод информации о конкретном сотруднике
	//вывод всей (или интересующей) информации о всех сотрудниках

	Base myBase;	//создание пустой базы
	//myBase["Ivanov"] = MyData(MALE, 28, <остальные данные>);	//если Ivanov-а в базе еще нет, то
	//														//добавление, если уже есть, то замена его реквизитов
	//myBase["Petrova"] = MyData(FEMALE, 22, <остальные данные>);	//добавление сотрудника в базу
	//myBase["Borisov"] = MyData(MALE, 35, <остальные данные>);		//добавление сотрудника в базу

	//myBase.deletePair("Borisov");			// удаление сотрудника

	//std::cout << myBase["Petrova"];		// вывод информации об одном сотруднике
	//std::cout << myBase;					//вывод информации обо всех сотрудниках

	//Base db = myBase;						// конструктор копирования
	//myBase =  db;							// оператор присваивания
	//Base db2 = move(db)					// семантика перемещение move
	//db = move(db2);


	return 0;
}