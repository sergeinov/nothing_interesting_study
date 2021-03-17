// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include<iterator>				// для работы с итераторами
#include"Point.h"
#include"template.h"
#include"Rect.h"

//using namespace std;	
#define	  stop __asm nop


// Point
std::ostream& operator<<(std::ostream& os, const Point& place)	// распечатать координаты
{
	os << "\nКоординаты:\n"
		<< "x = " << place.m_x
		<< "\n"
		<< "y = " << place.m_y;
	return os;
};

//// изменение  значений входящих данных point
//template<typename T> void changeValue(T& data)
//{
//	data = data + 2;
//}

int main()
{
	setlocale(LC_ALL, "Rus");
	///////////////////////////////////////////////////////////////////

		//Задание 1. Итераторы

		//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
		//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
		//являются копиями элементов set, но упорядочены по убыванию
	std::set<Point> mySet = { Point(1,1),Point(3,3),Point(12,12),Point(6,6),Point(10,10) };		// набор значений Set

	std::vector<Point> myVec(mySet.size());	// ! нельзя копировать в пустой вектор / создаем достаточно памяти для принятия диапазона
	//std::vector<Point> myVec(mySet.size());	// можно так создать память
	//myVec.reserve(mySet.size());		//  с этим не работает // сырая память
	//myVec.resize(mySet.size());		//  ок
	std::vector<Point> myVec2;
	myVec2.reserve(mySet.size());	// сырая память

	std::copy(mySet.rbegin(), mySet.rend(), myVec.begin());		// копируем из set  в vector, в обратном порядке
																//  ? не работает для set / map
	std::copy(mySet.rbegin(), mySet.rend(), std::back_inserter(myVec2));

	stop;

	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.

	std::ostream_iterator<Point> iter(std::cout, " ");				// создаем переменную - итератор вывода cout
	std::copy(mySet.begin(), mySet.end(), iter);					// не забыть перегрузить operator<<   для Point
	std::cout << "\n\n************" << std::endl;
	std::copy(myVec.begin(), myVec.end(), iter);					// вывод вектора на консоль с помощью copy


	stop;

	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.

	Point myArr[] = { Point(13, 13), Point(14, 14) };

	std::copy(myArr, myArr + 2, std::back_inserter(myVec));				// вызов insertor - push_back  для  Vector
	//std::copy(myArr, myArr + 2, std::front_inserter(mySet));				// вызов insertor - front_back  для  mySet
	std::for_each(myVec.begin(), myVec.end(), printElement<Point>);			// распечатать с предикатом

	std::cout << "\n\n************" << std::endl;
	stop;

	std::copy(myArr, myArr + 2, std::inserter(mySet, mySet.begin()));	// более универсальный. подходящий для контейнеров
	std::for_each(mySet.begin(), mySet.end(), printElement<Point>);			// распечатать с предикатом
	stop;

	///////////////////////////////////////////////////////////////////

		//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.
		// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
		//(массив, vector, list...)
		//С помощью алгоритма for_each в любой последовательности с элементами любого типа
		//распечатайте значения элементов
		//Подсказка : неплохо вызываемую функцию определить как шаблон

	std::set<int> mySet2 = { 1,2,3,4,5 };								// набор значений Set

	printContainer(mySet2);											// шаблонная функция печати контейнеров

	stop;

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката
	std::cout << "\n\nДо измените \"координаты\" на указанное значение..........." << std::endl;
	PrintAll(myVec2);
	changeValue<Point> temp(6);		// создание объекта
	std::for_each(myVec2.begin(), myVec2.end(), temp);		// предикат шаблон класса
	std::cout << "\n\nПосле измените \"координаты\" на указанное значение..........." << std::endl;
	PrintAll(myVec2);

	stop;

	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.

	std::vector<Point> myVec3 = { Point(1,1),Point(3,3),Point(12,12),Point(6,6),Point(10,10) };
	std::set<Point> myVec4 = { Point(1,1),Point(3,3),Point(12,12),Point(6,6),Point(10,10) };
	// ? не сработало с set
	std::vector<Point>::iterator itVec = find(myVec3.begin(), myVec3.end(), Point(3, 3));	// поиск элемента Point с значениями
	std::set<Point>::iterator itVec2 = find(myVec4.begin(), myVec4.end(), Point(14, 14));	// поиск элемента Point с значениями
	stop;
	
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!

	std::cout << "\n\nДо сортировки...." << std::endl;
	PrintAll(myVec3);
	
	std::sort(myVec3.begin(), myVec3.end());
	std::cout << "\nПосле сортировки....." << std::endl;
	PrintAll(myVec3);
	stop;

	std::list<Point> myList = { Point(20,20),Point(30,30),Point(120,120),Point(60,60),Point(100,100) };
	myList.sort();					// сортировка методом класса для списка
	PrintAll(myList);
	stop;

	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].

	std::list<Point>::iterator iterList = std::find_if(myList.begin(), myList.end(), Case(5, 5));
	if ( iterList == myList.end() )
	{
		std::cout << "\nNo!!";
	}
	stop;

	std::list<Point>::iterator iterList2 = std::find_if(myList.begin(), myList.end(), [ n = 120, m = 120 ](const Point& p){return ( p.GetX() < n && p.GetY() > m ); });
	std::list<Point>::iterator iterList3 = std::find_if(myList.begin(), myList.end(), [ n = 120, m = 120 ](const auto& p){return ( p.GetX() < n && p.GetY() > m ); });

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
	






	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()
		std::string str = "HEllO";
		std::transform(str.begin(), str.end(), str.begin(), SomeCase());
		stop;
		std::transform(str.begin(), str.end(), str.begin(), [](char ch) { return toupper(ch); });
		stop;
		std::transform(str.begin(), str.end(), str.begin(), SomeCasefoo);
		stop;

		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
	
		std::list<std::string> listStr = { "APPLE", "123", "LEMON" };
		std::set<std::string> setStr;
		std::transform(listStr.begin(), listStr.end(), std::inserter(setStr, setStr.begin()),
			[](const std::string& s)
			{
				std::string temp = s;
				std::transform(temp.begin(), temp.end(), temp.begin(), tolower);
				return temp;
			});
		stop;



		stop
	}
	
	{//copy_if
		//Дан вектор с элементами типа string. С помощью copy_if() требуется
		//вывести сначала строки, начинающиеся с буквы "А" или "а", затем с "Б"...
		//При этом порядок строк в исходном векторе менять не нужно!
		std::vector<std::string> vectStr = { "Ferrary", "Aar", "Bert"," Tret","Bger" };
		std::cout << std::endl;
		for ( char c = 'A'; c <= 'Z'; c++ )
		{
			int count = 0;		// счетчик используется для красивого вывода в консоль.
			std::copy_if(vectStr.begin(), vectStr.end(), std::ostream_iterator<std::string>(std::cout, " "),
				[c, &count](const std::string& s)
				{
					if ( c == toupper(s[ 0 ]) )		// если символ равен первому сиволу в строке  'A'  == "F"
					{
						count++;	
						return true;		// возвращаем true  и слово печатается в консоль через   ostream_iterator
					} return false;
					//return c == toupper(s[ 0 ]);
				});
			if ( count )	// если в count что-то есть 
			{
				std::cout << std::endl;
			}
			
		}

		stop;

		//Дан multimap, содержаций пары: "месяц - количество денй в месяце"
		//pair<string, int>. С помощью copy_if сформируйте ДВА map-а: первый -
		//с парами, содержащими четное количество дней, 2-ой - нечетное.
		std::multimap<std::string, int> month {
			{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
			{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
			{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		};



		stop

		//Распечатайте multimap и map-ы, используя написанный вами ранее шаблон
		//функции, выводящей элементы ЛЮБОГО контейнера на печать.
		//Что нужно сделать дополнительно для вывода пары?


	
		stop
	}

	return 0;
}

