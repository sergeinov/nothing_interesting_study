// Механизм RTTI
//

#include <iostream>
//#include<typeinfo>
#include<crtdbg.h> // для поиска утечек 
#include<fstream>
#include"List.h"
#include"Circle.h"
#include"Rect.h"

#define stop __asm nop

std::ostream& operator<<(std::ostream& os, const List& list)	// ! Done     // распечатать список 
{
	if ( list.m_size != 0 )
	{
		os << "\nСписок: \n";
		Node* p = list.Head.pNext;
		//p->pNext;
		os << list.m_size << std::endl;
		for ( size_t i = 0; i < list.m_size; i++ )
		{
			/*os <<*/ p->figure->Print(os) << std::endl;
			p = p->pNext;
		}

		return os;
	}
	else
	{
		os << "\nСписок пуст!!";
	}

	return os;
}

std::ifstream& operator>>(std::ifstream& iff, List& list)		// чтение из файла
{
	// TODO

	return iff;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	// можно проверку поставить в начало программы и не надо будет беспокоится где программа заканчивается 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	List l;
	l.AddToHead(Rect(1, 1, 4, 4, Shape::BLUE));
	l.AddToHead(Circle(2, 2, 4, Shape::GREEN));
	l.AddToEnd(Circle(4, 4, 6, Shape::YELLOW));
	l.AddToEnd(Rect(6, 6, 8, 8, Shape::YELLOW));
	//l.ClearList();

	List l2 = l;		// конструктор копирования
	std::cout << "\n********Коструктор копирования:************" << std::endl;
	std::cout << "\nСписок l2:" << std::endl;
	std::cout << l2;			// распечатать список

	List l3;
	l3 = l2;				// присваивание
	std::cout << "\n************Присваивание:*****************" << std::endl;
	std::cout << "\nСписок l2:" << std::endl;
	std::cout << l2;
	std::cout << "\nСписок l3:" << std::endl;
	std::cout << l;

	std::cout << "\n*********Сортировка по цвету:**************" << std::endl;
	l.Sort(Color);
	std::cout << "Вывод отсортированного списка:" << std::endl;
	std::cout << l;
	
	std::cout << "\n*********Сортировка по цвету:**************" << std::endl;
	l.Sort(Area);
	std::cout << "Вывод отсортированного списка:" << std::endl;
	std::cout << l;

	stop

	std::cout << "\n*********Записать в файл:****************" << std::endl;
	std::ofstream listOut("in.txt");	// открыть файл
	listOut << l;						// записать список в файл	// используется перегруженный std::ostream& operator<<(std::ostream& os, const List& list)
	listOut.close();

	stop

	std::cout << "\n******Считать из файла**********" << std::endl;
	std::ifstream fout("in.txt");
	List list1;
	fout >> list1;				// считываем и записываем в список list1
	fout.close();
	std::cout << "\nВывод списка list1 из файла:" << std::endl;
	std::cout << list1;			// распечатать список


	std::cout << "\n**********Очистить список list1:************" << std::endl;
	list1.ClearList();
	std::cout << "\nВывод списка list1:" << std::endl;
	std::cout << list1;			// распечатать список
	stop



	std::cout << "\n**********Удалить объекты:************" << std::endl;
	l.RemoveOne(Circle(1, 1, 4, Shape::GREEN));
	std::cout << l;

	stop
	return 0;
}

