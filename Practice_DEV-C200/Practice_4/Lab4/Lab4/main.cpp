// Цель - с помощью классов реализовать список объектов типа Circle 
// Через однородный двухсвязный список

#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include<iostream>
#include"List.h"
#include<fstream>


#define stop _asm nop

static const char* arr[] = { "", "RED", "YELLOW", "GREEN", "BLACK" };

std::ostream& operator<<(std::ostream& os, Point& place)	// распечатать координаты
{
	os << "\nКоординаты:\n" 
		<< "x = " << place.m_x 
		<< "\n" 
		<< "y = " << place.m_y;
	return os;
}; 

std::ostream& operator<<(std::ostream& os, Circle& object)	// распечатать объект
{
	os << "\nКруг: " << object.point 
		<< "\nЦвет: " << arr[object.color]
		<< "\nРадиус: " << object.m_radius << "\n";
	return os;
};

//std::ostream& operator<<(std::ostream& os, Node& node)		// вывод одного элемента списка Node
//{
//	os << node.m_Data;
//	
//	return os;
//}; 

std::ostream& operator<<(std::ostream& os, const List& list)	// распечатать список
{
	if ( list.m_size != 0 )
	{
		os << "\nСписок: \n";
		Node* p = list.Head.pNext;
		//p->pNext;
		os << list.m_size << std::endl;
		for ( size_t i = 0; i < list.m_size; i++ )
		{
			//os << m_Data;
			os << p->m_Data;
			p = p->pNext;
		}

		return os;
	}
	else
	{
		os << "\nСписок пуст!!";
	}
		
	
};

std::ifstream& operator>>(std::ifstream& iff, List& list)		// считать списка из файла
{
	char ar[ 20 ];
	iff >> ar;		// строка "список"
	int temp;
	iff >> temp;	// число
	for ( size_t i = 0; i < temp; i++ )
	{
		iff >> ar;		// "круг"	
		iff >> ar;		// "координаты"

		int n1, n2;	// для записи значений
		double n4;
		Circle::eColor n3 = {};

		iff.ignore(10, '=');
		iff >> n1;
		iff.ignore(10, '=');
		iff >> n2;
		iff.ignore(10, ':');
		iff >> n3;
		iff.ignore(10, ':');
		iff >> n4;
		
		list.AddToEnd(Circle(n4, n1, n2, n3));
	}
	return iff;
};

std::ifstream& operator>>(std::ifstream& iff2, Circle::eColor& color)		// для считывания текста для типа перечисления eColor
{
	char ar[ 20 ];
	iff2 >> ar;
	for ( size_t i = 1; i < sizeof(arr) / sizeof(arr[ 0 ]); i++ )
	{
		if ( strcmp(ar, arr[ i ]) == 0 )
		{
			color = static_cast< Circle::eColor >( i );
			break;
		}
	}
	return iff2;
};
	

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");

	Circle c1(2, 3, 3, Circle::eColor::GREEN);
	Circle c2(4, 8, 8, Circle::eColor::RED);
	Circle c3(1, 4, 4, Circle::eColor::RED);
	List list1;

	list1.AddToHead(c1);	// добавить в начало списка
	list1.AddToEnd(c2);		// добавить в конец списка
	list1.AddToEnd(c3);

	std::cout << "Объект c1" << std::endl;
	std::cout << c1;			// распечатать параметры объекта
	std::cout << "\nОбъект c2" << std::endl;
	std::cout << c2;			// распечатать параметры объекта
	std::cout << "\nСписок list1:" << std::endl;
	std::cout << list1;			// распечатать список

	List list2 = list1;		// конструктор копирования
	std::cout << "\n********Коструктор копирования:************" << std::endl;
	std::cout << "\nСписок list2:" << std::endl;
	std::cout << list2;			// распечатать список

	List list3;
	list3 = list2;				// присваивание
	std::cout << "\n************Присваивание:*****************" << std::endl;
	std::cout << "\nСписок list2:" << std::endl;
	std::cout << list2;
	std::cout << "\nСписок list3:" << std::endl;
	std::cout << list3;


	list3 = std::move(list2);	// оператор перемещения  move
	std::cout << "\n*********Оператор перемещения  move:**************" << std::endl;
	std::cout << "\nСписок list2:" << std::endl;
	std::cout << list2;
	std::cout << "\nСписок list3:" << std::endl;
	std::cout << list3;

	// сортировка
	std::cout << "\n*********Сортировка:**************" << std::endl;
	list3.SortList(list3);
	std::cout << "Вывод:" << std::endl;
	std::cout << list3;

	// записать в файл
	std::cout << "\n*********Записать в файл:****************" << std::endl;
	std::ofstream listOut("int.txt");	// открыть файл
	listOut << list3;					// записать список в файл	// используется перегруженный std::ostream& operator<<(std::ostream& os, const List& list)
	listOut.close();					// закрыть файл

	// Удалить объекты:
	std::cout << "\n**********Удалить объекты:************" << std::endl;
	std::cout << "\nУдаление c1 - " << list3.RemoveOne(c1);		// удалить объект
	std::cout << list3;
	std::cout << "\nУдаление c2 - " << list3.RemoveOne(c2);		// удалить объект
	std::cout << list3;

	std::cout << "\n********** Удалить все объекты:********" << std::endl;
	int deleteTemp = list3.RemoveAll(c1);		// удалить все объекты
	std::cout << list3;			// распечатать список
	std::cout << "\nВ списке: " << deleteTemp << std::endl;


	// считать из файла
	std::cout << "\n******Считать из файла**********" << std::endl;
	std::ifstream fout("int.txt");
	List list4;
	fout >> list4;				// считываем и записываем в список list3
	fout.close();
	std::cout << "\nВывод списка из файла:" << std::endl;
	std::cout << list4;			// распечатать список

	stop

	return 0;
}