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


std::ostream& operator<<(std::ostream& os, const List& list)    // распечатать список 
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

std::ifstream& operator>>(std::ifstream& iff, List& list)		// чтение списка из файла
{
	char ar[ 20 ];					// массив для считываемых данных
	iff >> ar;						// строка "список"
	int temp;
	iff >> temp;					// число количества в списке
	for ( size_t i = 0; i < temp; i++ )
	{
		int n1, n2, n3, n4;			// для записи  int значений
		double n5;					// для записи  double значений
		Shape::eColor n6 = {};		// переменная для считывания цвета

		iff >> ar;					// считываем название объекта
		if ( strcmp(ar, "Rect:") == 0 )
		{
			iff.ignore(10, ':');
			iff >> n1;
			iff.ignore(10, ':');
			iff >> n2;
			iff.ignore(10, ':');
			iff >> n3;				
			iff.ignore(10, ':');
			iff >> n4;
			iff.ignore(10, ':');
			iff.ignore(10, '\n');				// ? как пропустить строку // считывание  Area   - пропускаем 
			iff >> n6;				// eColor
			list.AddToEnd(Rect(n1, n1, n3, n4, n6));	// добавляем считанные данные в список
		}
		else if ( strcmp(ar, "Circle:") == 0 )		// ? пропускает последние два  объекта  после 3-го
		{
			iff.ignore(10, ':');
			iff >> n1;
			iff.ignore(10, ':');
			iff >> n2;
			iff.ignore(10, ':');
			iff >> n5;					// радиус
			iff >> n4;				// ? как пропустить строку // считывание  Area   - пропускаем 
			iff >> n6;					// eColor	// используется перегруженный оператор <<
			list.AddToEnd(Circle(n1, n2, n5, n6));
		}
	}

	return iff;
}

std::ifstream& operator>>(std::ifstream& iff2, Shape::eColor& color)		// для считывания текста для типа перечисления eColor
{
	char ar[ 20 ];
	iff2 >> ar;
	for ( size_t i = 1; i < sizeof(arr) / sizeof(arr[ 0 ]); i++ )
	{
		if ( strcmp(ar, arr[ i ]) == 0 )
		{
			color = static_cast< Shape::eColor >( i );
			break;
		}
	}
	return iff2;
};



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
	l.AddToEnd(Circle(8, 8, 10, Shape::YELLOW));
	//l.ClearList();


	//List l6;				// для теста   List& List::operator=(const List& otherList)	//Перегрузка оператора присваивания = для обьекта
	//l.AddToEnd(Circle(8, 8, 10, Shape::YELLOW));
	//l.AddToHead(Rect(1, 1, 4, 4, Shape::BLUE));
	//l.AddToEnd(Rect(6, 6, 8, 8, Shape::YELLOW));
	//l.AddToHead(Circle(2, 2, 4, Shape::GREEN));
	//l.AddToEnd(Circle(4, 4, 6, Shape::YELLOW));


	List l2 = l;		// конструктор копирования
	std::cout << "\n********Коструктор копирования:************" << std::endl;
	std::cout << "\nСписок l:" << std::endl;
	std::cout << "\nСписок l2:" << std::endl;
	std::cout << l2;			// распечатать список

	List l3;
	l3 = l2;					// оператор присваивание/ копирования
	//l6 = l2;					// для проверки виртуального  virtual Shape& operator=()
	std::cout << "\n************Присваивание:*****************" << std::endl;
	std::cout << "\nСписок l2:" << std::endl;
	std::cout << l2;
	std::cout << "\nСписок l3:" << std::endl;
	std::cout << l3;

	std::cout << "\n*********Сортировка по цвету:**************" << std::endl;
	l.Sort(Color);
	std::cout << "Вывод отсортированного списка:" << std::endl;
	std::cout << l;
	
	std::cout << "\n*********Сортировка по площади:**************" << std::endl;
	l.Sort(Area);
	std::cout << "Вывод отсортированного списка:" << std::endl;
	std::cout << l;

	stop

	std::cout << "\n*********Записать в файл:****************" << std::endl;
	std::cout << "\n ..........Loading...........\n" << std::endl;
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

	stop

	std::cout << "\n**********Очистить список list1:************" << std::endl;
	list1.ClearList();
	std::cout << "\nВывод списка list1:" << std::endl;
	std::cout << list1 << std::endl;			// распечатать список

	stop

	std::cout << "\n**********Удалить объекты:************" << std::endl;
	l.RemoveOne(Circle(4, 4, 6, Shape::YELLOW));
	std::cout << l;

	stop
	return 0;
}

