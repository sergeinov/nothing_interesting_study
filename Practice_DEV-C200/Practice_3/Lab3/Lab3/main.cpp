// Темы:
// Перегрузка операторов.
// Встроенные объекты 

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку
#include<iostream>
#include <tchar.h>
#include"MyString.h"
#include "Point.h"

#define	  stop __asm nop

// перегрузка оператора -=
Point& operator-=(Point& leftObject, const int value)
{
	leftObject.m_x = leftObject.m_x - value;
	leftObject.m_y = leftObject.m_y - value;
	return leftObject;		// возврат ссылки существующего обьекта
};
Point& operator-=(Point& leftObject, Point& RightObject)
{
	// c временным обьектом Point temp; не получается  pt2 -= pt1 -= pt3;
	// приходится менять значение  leftObject
	leftObject.m_x = leftObject.m_x - RightObject.m_x;
	leftObject.m_y = leftObject.m_y - RightObject.m_y;
	return leftObject;			// возврат ссылки существующего обьекта
};

// перегрузка оператора +
Point& operator+(const int value, Point& RightObject)
{
	RightObject.m_x += value;
	RightObject.m_y += value;
	return RightObject;			// возврат ссылки существующего обьекта
};

// перегрузка оператора - 
Point operator-(Point& leftObject, const int value)
{
	// тут с временным обьектом Point temp; можно 
	Point temp;
	temp.m_x = leftObject.m_x - value;
	temp.m_y = leftObject.m_y - value;
	return temp;		// вызов конструктор копирования Point(const Point& other);
};
Point operator-(Point& leftObject, Point& RightObject)
{
	Point temp;
	temp.m_x = leftObject.m_x - RightObject.m_x;
	temp.m_y = leftObject.m_y - RightObject.m_y;
	return temp;		// вызов конструктор копирования Point(const Point& other);
};

// Перегрузка оператора << 
//если вы попытаетесь возвратить std::ostream по значению, то получите ошибку компилятора. 
//Это случится из-за того, что std::ostream запрещает свое копирование.
std::ostream& operator<<(std::ostream& out, const MyString& RightObject)
{
	out << "m_pName: " << RightObject.m_pName;
	return out;
};

int _tmain(int argc, _TCHAR* argv[])
{
//////////////////////////////////////////////////////////////////////


	//Задание 1.Перегрузка операторов.

	//Подключите к проекту файлы MyString.cpp и MyString.h
	//класса MyString, разработанного Вами на предыдущем занятии
	//9a. Перегрузите оператор присваивания для класса MyString
	//Проверьте корректность работы перегруженного оператора

	{
		MyString s1("AAA"), s2;
		s2=s1;		// MyString& operator=();
		//s2.operator=(s1);
		s1="CCC";	// MyString(параметры) -> MyString& operator=() -> ~MyString(); 
		//s1.operator=("CCC");
		s2= MyString("tmp"); // MyString(параметры) -> MyString& operator=() -> ~MyString();
		//s2.operator=(MyString("tmp"));
		s1=s1;			// MyString& operator=();
		//s1.operator=(s1);
		stop
	}




	//2.Создайте класс Point, который будет содержать координаты
	//"точки". Объявите конструктор (конструкторы) класса   

	//2b. "Перегрузите" оператор += так, чтобы при выполнении
	//операции типа pt2+=pt1; складывались
	//одноименные переменные объектов pt1 и pt2, а сумма
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2+=1; обе переменные объекта pt2 увеличивались на
	// указанное значение
	//a) с помощью метода класса (оператор +=)
	//б) с помощью глобальной функции (оператор -=)
	//Проверьте корректность работы перегруженного оператора
	{
		//(оператор +=)
		Point pt1(1, 1);
		Point pt2(2, 2);
		pt2+=pt1;		//pt2 = {m_x=3 m_y=3 }// вызов Point::operator+=(const Point& other)
		//pt2.operator+=(pt1);
		pt2+=1;			//pt2 = {m_x=4 m_y=4 }	
		//pt2.operator+=(1);
		Point pt3(3, 3);
		pt2+=pt1+=pt3;	//pt2 = {m_x=8 m_y=8 } // вызов Point::operator+=(const Point& other)
		//pt2.operator+=(pt1.operator+=(pt3));
		stop
		//(оператор -= ) // с помощью глобальной функции
		pt2 -= pt1;		//pt2 = {m_x=4 m_y=4 }
		pt2 -= 1;		//pt2 = {m_x=3 m_y=3 }
		pt2 -= pt1 -= pt3;	//pt2 = {m_x=2 m_y=2 }
		stop
	}

	//Задание 2c. Перегрузите оператор +/- 
	//a)с помощью методов класса (оператор +)
	//б) с помощью  глобальных функций (оператор -)
	//так, чтобы любая из закомментированных строк
	//кода выполнялась корректно
	{
		Point pt1(1, 1);
		Point pt2(2, 2);
		Point pt3;

		// (оператор +)
		pt3 = pt1 + 5;
		//pt3.operator+(pt1 + 5);
		pt3 = 2 + pt1;		 // только с помощью глобальной функции
		pt3 = pt1 + pt2;
		//pt3.operator+(pt1 + pt2);

		// (оператор - )
		pt3 = pt1 - 5;
		pt3 = pt1 - pt2;
		//pt3.operator+(pt1 - pt2);
		stop

			//Задание 1d. Перегрузите унарный оператор +/- 
		// путаницы между отрицательным унарным оператором (-) и бинарным оператором (-) нету.
		// т.к. они имеют разное количество параметров
		pt3 = -pt1;
		//pt3.operator-();	// как написать функциональную форму??
		pt3 = +pt1;
		//pt3.operator+();
		
		stop

	// Почему нет вызова деструкторов?
	}


	//Задание 2d. Перегрузите оператор << (вывода в поток) для
	//класса MyString таким образом, чтобы при выполнении приведенной строки
	//на экран было выведено:
	//contents:  "QWERTY"

	// перегрузка возможна только глобальной функцией. Т.к операнд слева библиотечная функция
	{
		MyString s("QWERTY");
		std::cout << s << std::endl;
		stop
	}

	//Задание 2e*. Перегрузите операторы + и += для класса MyString таким образом,
  //чтобы происходила конкатенация строк
	{
		MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
		s3  = s1 + s2;
		s4 += s1;
		stop
	}

	//Задание 3. Разработать "базу данных" о сотрудниках посредством ассоциативного
	//массива. Ключом является фамилия (ключ в задании уникален, поэтому нескольких Ивановых
	//в базе быть не может), а данными: пол, возраст, должность, зарплата...
	//Реализуйте:
	//добавление сотрудников в базу
	//исключение
	//вывод информации о конкретном сотруднике
	//вывод всей (или интересующей) информации о всех сотрудниках
	//Например:
/*
		BD bd;	//создание пустой базы
		bd["Ivanov"] = Data(30,MALE,<остальные данные>);	//если Ivanov-а в базе еще нет, то
						//добавление, если уже есть, то замена его реквизитов
		std::cout<<bd;	//вывод информации обо всех сотрудниках

*/
	
	return 0;
}//endmain

