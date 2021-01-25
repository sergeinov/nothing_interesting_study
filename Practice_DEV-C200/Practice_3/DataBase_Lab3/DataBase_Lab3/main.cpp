#include <iostream>
#include<tchar.h>
//#include"MyString.h"
#include"MyData.h"
#include"Base.h"

#define	  stop __asm nop

// глобальные методы перегрузки операторов

// MyString
std::ostream& operator<<(std::ostream& os, const MyString& RightObject)
{
	os << RightObject.m_pName;
	return os;
};

// MyData
std::ostream& operator<<(std::ostream& os, const MyData& data)
{
	// нужен перегруженный оператор<<  для MyString (для вывода << data.m_job)
	os << "sex = " << (data.sex == data.MALE ? "MALE\n" : data.sex == data.FEMALE ? "FEMALE\n" : "UNDEF\n")
		<< "age = " << data.m_age << "\n"  << "job = " << data.m_job << "\n"
		<< "salary = " << data.m_salary << "\n";
	return os;
};

// Pair
std::ostream& operator<<(std::ostream& os, const Pair& pair)
{
	// нужен перегруженный оператор<<  для MyData
};

// Base
std::ostream& operator<<(std::ostream& os, const Base& bd)
{
	// нужен перегруженный оператор<<  для Pair
	for (size_t i = 0; i < bd.count; i++)
	{
		
		//os << bd.pBase[i].
	}

	return os;
};

int _tmain(int argc, _TCHAR* argv[])
{
	//Реализуйте:
	//добавление сотрудников в базу
	//исключение
	//вывод информации о конкретном сотруднике
	//вывод всей (или интересующей) информации о всех сотрудниках

	Base myBase;	//создание пустой базы
	myBase["Ivanov"] = MyData(MyData::Sex::MALE, 28, "Programmer", 150000);			//если Ivanov-а в базе еще нет, то
																		//добавление, если уже есть, то замена его реквизитов
	myBase["Petrova"] = MyData(MyData::Sex::FEMALE, 22, "HR" , 80000);				//добавление сотрудника в базу
	myBase["Borisov"] = MyData(MyData::Sex::MALE, 35, "Designer" , 100000);		//добавление сотрудника в базу
	myBase["Borisov"] = MyData(MyData::Sex::MALE, 35, "Middle Designer", 150000);	//изменение данных сотрудника в базе

	myBase.deletePair("Borisov");				// удаление сотрудника

	std::cout << myBase["Petrova"];			// вывод информации об одном сотруднике, существующего в базе
	std::cout << myBase["Petrova"];			// вывод информации об одном сотруднике, которого нет в базе
	std::cout << myBase;						//вывод информации обо всех сотрудниках

	//Base db = myBase;							// конструктор копирования
	//myBase =  db;								// оператор присваивания
	//Base db2 = move(db)						// семантика перемещение move
	//db = move(db2);


	return 0;
}