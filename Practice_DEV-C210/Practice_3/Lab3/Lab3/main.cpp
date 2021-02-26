//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

#include <iostream>
#include<list>
#include <vector>
#include"Point.h"
#include"templates.h"
#include"MyString.h"


#pragma warning(disable: 4786)


using namespace std;	

#define	  stop __asm nop

// MyString
std::ostream& operator<<(std::ostream& os, const MyString& RightObject)
{
	os << RightObject.m_pName;

	return os;
};

// Point
std::ostream& operator<<(std::ostream& os, const Point& place)	// распечатать координаты
{
	os << "\nКоординаты:\n"
		<< "x = " << place.m_x
		<< "\n"
		<< "y = " << place.m_y;
	return os;
};

// Point перегрузка для  Point*
std::ostream& operator<<(std::ostream& os, const Point* place)
{
	os << "\nКоординаты:\n"
		<< "x = " << place->m_x
		<< "\n"
		<< "y = " << place->m_y;
	return os;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 
	
	vector<int> vInt;
	size_t n = vInt.size();
	
	stop
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте
	vInt.push_back(5);
	vInt.front() = 1;				// 1 // front  возвращает ссылку на первый элемент // эквивалент *c.begin()
	stop

	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	for ( size_t i = 1; i < 5; i++ )
	{
		vInt.push_back(i * 5);
		PrintVector(vInt);
		std::cout << std::endl;
	}
	stop
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.



	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?
	vector<double> doubleVector(10);			//  0  0  0  0  0
	PrintVector(doubleVector);
	stop;

	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 
	vector<MyString> str(5, "A");
	try
	{
		str.at(3) = "C";
		str.at(5) = "B";	// Exception thrown at 0x76A746D2 in Lab3.exe: Microsoft C++ exception: std::out_of_range at memory location 0x0137F500.
	}
	catch ( std::out_of_range& ) { };
	
	str[ 4 ] = "D";
	PrintVector(str);
	stop;

	//str[ 5 ] = "F";			// прерывание дебагера о  out_of_range at memory
	

	stop
	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!

	double dMas [] = { 3, 4, 5, 10, 11, 15, 16 };
	//PrintVector(dMas);
	vector<double>vDouble3(dMas, (dMas + sizeof(dMas) / sizeof(double)));
	PrintVector(vDouble3);
	stop;

	//вектор вещественных - vDouble4, который является копией элементов
	// [от 2, до 5) вектора vDouble3. 

	vector<double>vDouble4(vDouble3.begin() + 2, vDouble3.begin() + 5);
	PrintVector(vDouble4);
	stop;

	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).
	vector<Point> point1(3);			//  вызов конструктора по умолчанию

	vector<Point> point2(5, Point(1,1));	// вызов конструктора с инициализацией
	PrintVector(point2);					// const
	/*for ( size_t i = 0; i < point2.size(); i++)
	{
		std::cout << point2[ i ] << " ";
	}*/

	stop;

	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{
		vector<Point*>vpPoint(5);
		for ( size_t i = 0; i < vpPoint.size(); i++ )
		{
			vpPoint[ i ] = new Point(i, i);
		}
	//Подсказка: для вывода на печать значений скорее всего Вам понадобится
		//а) специализация Вашей шаблонной функции
		//б) или перегрузка operator<< для Point*

		std::cout << "\n\nVector указателей vpPoint" << std::endl;
		// печатаем
		PrintVector(vpPoint);
		stop;
		std::cout << "Удаление Point" << std::endl;

		// удаляем динамически созданный Point
		for ( size_t i = 0; i < vpPoint.size(); i++ )
		{
			delete vpPoint[ i ];
		}
		stop;
	}//Какие дополнительные действия нужно предпринять для такого вектора?		// будут удалены указатели вектора

	stop
		///////////////////////////////////////////////////////////////////////
		//Резервирование памяти.
		//Подумайте, всегда ли верны приведенные ниже проверки?

		{
		size_t n = 10;
		vector<int> v(n);
		v.resize(n/2);
		if ( v.capacity() == n ); // !true  // не всегда верно
		stop
		}
		

		
		{
		int n = 10;
		size_t m = 10;
		vector<int> v(n);	// 10 элементов
		v.reserve(m);		//  зарезервировано памяти
		if ( v.capacity() == m ); // !true
		stop
		}
		

		
		{
		vector<int> v(3,5);
		v.resize(4,10); //значения?	// 5  5  5  10  - Capacity 4	Size - 4
		v.resize(5); //значения?		// 5  5  5  10  0 - Capacity 6  Size - 5
		stop
		}
		

	//Создайте два "пустых" вектора с элементами
	//любого (но одного и того же типа) типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов

		vector<int> vInt1;
		vInt1.reserve(5);		//  зарезервировано памяти
		vInt1.push_back(1);
		vInt1.push_back(2);
		vInt1.push_back(3);
		vInt1.push_back(4);
		vInt1.push_back(5);
		PrintVector(vInt1);		// 1  2  3  4  5 - Capacity 5  Size - 5

		vector<int> vInt2;
		vInt2.push_back(10);
		vInt2.push_back(20);
		vInt2.push_back(30);
		vInt2.push_back(40);
		vInt2.push_back(50);
		PrintVector(vInt2);		// 0  0  0  0  0 - Capacity 6  Size - 5
	
		stop;


	//!!! shrink_to_fit - Уменьшение емкости вектора.
	//Для любого вектора из предыдущего задания требуется уменьшить емкость
	//до size.

		// с помощью обмена двух векторов  void swap(vector<Type, Allocator>& x);
		// при обмене для не используемой памяти вызывается деструктор
		// !vInt2.swap(vector<int>(vInt2));

		// увеличиваем для теста Capacity
		vInt2.reserve(10);					// резервируем память
		PrintVector(vInt2);
		vInt2.shrink_to_fit();				// убирает capacity
		PrintVector(vInt2);
		stop;
	

	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2,
	//vv[2] - содержит 4,4,4,4
	//vv[3] - 3,3,3
	//Распечатайте содержимое такого двухмерного вектора по строкам
		int ar[] = { 11,2,4,3,5 };
		vector<vector<int>>vv;
		vv.resize(11);
		for ( size_t i = 0; i < 3; i++ )
		{
			vv[ i ].assign(ar[ i ], ar[ i ]);
		}
		
		//std::cout << vv << std::endl;
		stop;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//Вставка элемента последовательности insert().
		//В вектор vChar2 вставьте в начало вектора символ только при
		//условии, что в векторе такого еще нет.
		const char* ch= "N";
		bool flag = true;

		
		vector<const char*>vChar2;
		vChar2.push_back("A");
		vChar2.push_back("B");
		vChar2.push_back("D");
		vChar2.push_back("C");
		
		int size = vChar2.size();
		vector<const char*>::iterator itb = vChar2.begin();
		//vector<const char*>::iterator ite = vChar2.end();

		// вставляем символ
		for ( size_t i = 0; i < size; i++ )
		{
			// проверк, что есть в векторе символ
			if ( vChar2[i] == ch )
			{
				flag = false;
				std::cout << "Есть такой символ - " << ch << std::endl;
				break;
			}
		}
		if ( flag )
		{
			vChar2.insert(itb, ch);
		}
		// распечатаем
		PrintVector(vChar2);
	
	//Вставьте перед каждым элементом вектора vChar2 букву 'W'	
		const char* ch2 = "W";
		itb = vChar2.begin();
		//vChar2.reserve(20);

		for ( size_t i = 0; i < size + 1; i++ )
		{
			itb = vChar2.insert(itb, ch2);		// если не принимать адрес мы можем потерять указатель
			itb += 2;
		}
		PrintVector(vChar2);

		stop;

///////////////////////////////////////////////////////////////////
	//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"
		vChar2.push_back("A");
		vChar2.push_back("A");
		vChar2.push_back("A");
	// ! не знаю
	//DeleteSameElements(vChar2);
	PrintVector(vChar2);
	stop;

		///////////////////////////////////////////////////////////////////

	//Удаление элемента последовательности erase()
	//Напишите функцию удаления из любого вектора всех дублей 

	//DeleteSameElementsWithErase(vChar2);
	PrintVector(vChar2);
	stop


		///////////////////////////////////////////////////////////////////
			//Создайте новый вектор таким образом, чтобы его элементы стали
			//копиями элементов любого из созданных ранее векторов, но расположены
			//были бы в обратном порядке
		vector<int> vInt4;
		for ( vector<int>::reverse_iterator itb = vInt1.rbegin(); itb != vInt1.rend(); ++itb )
		{
			vInt4.push_back(*itb);
		}
		PrintVector(vInt4);
		stop;



	///////////////////////////////////////////////////////////////////

		// ! Задание 1. Списки. Операции, характерные для списков.
		//Создайте пустой список из элементов Point - ptList1 и наполните
		//его значениями с помощью методов push_back(),
		//push_front, insert()

		list<int> list1;
		//list <int> :: iterator itb = list1.begin();
		//advance(itb, 5);
		list1.push_back(1);
		list1.push_back(2);
		list1.push_front(4);
		list1.push_front(3);
		list1.insert(list1.end(), 10);


	//Напишите шаблон функции, которая будет выводить элементы
	//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
	//vector и list. Подсказка - хотелось бы увидеть тип контейнера.
		PrintAll(list1);
		stop;

	//Сделайте любой из списков "реверсивным" - reverse()
		list1.reverse();
		PrintAll(list1);
		stop;
	//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
	//копией вектора элементов типа Point, но значения элементов списка располагались
	//бы в обратном порядке 



	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка


	


	stop

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит с каждым списком.

	
	stop

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подумайте: что должно быть перегружено в классе Point?
	

	//Исключение элемента из списка, удовлетворяющего заданному условию:
	//любая из координат отрицательна - remove_if(). 


	//Исключение из списка подряд расположенных дублей - unique(). 

	stop

///////////////////////////////////////////////////////////////////
	//Задание 2.Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать



	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'




	return 0;
}