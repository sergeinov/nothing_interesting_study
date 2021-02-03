// Цель - с помощью классов реализовать список объектов типа Circle 
// Через однородный двухсвязный список

#include <tchar.h>
#include<iostream>
#include"List.h"


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

std::ostream& operator<<(std::ostream& os, Node& node)		// вывод одного элемента списка Node
{
	os << node.m_Data;
	
	return os;
}; 

std::ostream& operator<<(std::ostream& os, List& list)	// распечатать список
{
		Node* p = &list.Head;	


		os << "\nСписок: \n";
		
		for (size_t i = 0; i < list.m_size; i++)
		{
			if (p)
			{
				
			}
			
		}
		
		return os;
	
};
	

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");

	Circle c1(2, 3, 3, Circle::eColor::GREEN);
	Circle c2(4, 6, 6, Circle::eColor::RED);
	List list;

	list.AddToHead(c1);
	list.AddToEnd(c2);

	std::cout << c1;

	std::cout << list;

	list.RemoveOne(c1);
	std::cout << c1;

	list.RemoveAll(c2);
	std::cout << list;

	return 0;
}