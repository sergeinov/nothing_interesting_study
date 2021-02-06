// Цель - с помощью классов реализовать список объектов типа Circle 
// Через однородный двухсвязный список

#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include<iostream>
#include"List.h"
#include<fstream>


#define stop _asm nop

std::ostream& operator<<(std::ostream& os, Point& place)	// распечатать координаты
{
	os << "\nКоординаты:\n" << "x = " << place.m_x << ", " << "y = " << place.m_y;
	return os;
}; 

std::ostream& operator<<(std::ostream& os, Circle& object)	// распечатать объект
{
	os << "\nКруг: " << object.point << "\nЦвет: " << object.color << "\nРадиус: " << object.m_radius << "\n";
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

std::ifstream& operator>>(std::ifstream& iff, List& list)		// вывод списка из файла
{
	char ar[ 20 ];
	iff >> ar;
	int temp;
	iff >> temp;
	for ( size_t i = 0; i < temp; i++ )
	{
		iff >> ar;
		iff >> ar;
		int n1, n2, n3, n4;
		iff.ignore(10, '=');
		iff >> n1;

		//........
		
		list.AddToEnd(Circle(n1, n2, n3, static_cast<Circle::eColor>(n4)));
	}
	return iff;
};
	

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");

	Circle c1(2, 3, 3, Circle::eColor::GREEN);
	Circle c2(4, 6, 6, Circle::eColor::RED);
	List list1;

	list1.AddToHead(c1);	// добавить в начало списка
	list1.AddToEnd(c2);		// добавить в конец списка

	List list2 = list1;		// конструктор копирования

	List list3;
	list3 = list2;
	std::cout << "*****" << std::endl;
	std::cout << list3;
	std::cout << "*****" << std::endl;
	std::cout << list2;
	//list3 = std::move(list2);	// оператор перемещения  move

	std::cout << c1;			// распечатать параметры объекта

	std::cout << list3;			// распечатать список

		// записать в файл
	std::ofstream listOut("int.txt");
	listOut << list3;					// вывести список
	listOut.close();					// закрыть файл

	list3.RemoveOne(c1);		// удалить объект
	std::cout << c1;

	list3.RemoveAll(c2);		// удалить объект
	std::cout << list3;			// распечатать список



	// считать из файла
	std::ifstream fout("int.txt");
	//fout >> list3;
	fout.close();

	return 0;
}