#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include"Header.h"
#include <list>
#include<ostream>
#include<fstream>
#include"WriterDeleter.h"
#include<stdio.h>
#include"human.h"

size_t SIZE;

void deleterFoo(std::string** str)
{
	for ( size_t i = 0; i < SIZE; i++ )
	{
		delete str[ i ];
	}
}

int main()
{
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	//Задание 1. unique_ptr
	{

		//1.а - обеспечьте корректное выполнение фрагмента
		{
			std::vector<std::string*> v = { new std::string("aa"), new std::string("bb"), new std::string("cc") };
			//Распечатайте все строки
			for ( const auto& i : v )
			{
				std::cout << *i << " ";
			}
			__asm nop

			for ( auto& i : v )
			{
				delete i;
			}
			//v.clear();
			__asm nop

		} //??? деструкторы для указателей

		//1.b - модифицируйте задание 1.а:
		 //обеспечьте посредством std::unique_ptr: 
		 //эффективное заполнение (вспомните про разные способы формирования std::unique_ptr), 
		 //безопасное хранение указателей на динамически создаваемые объекты std::string, 
		 //манипулирование,
		 //и освобождение ресурсов
		 //

		{
			//Распечатайте все строки
			std::vector<std::unique_ptr<std::string>> vec;
			//{ new std::string("aa"), new std::string("bb"), new std::string("cc") };
			vec.reserve(5);
			vec.push_back(std::unique_ptr<std::string>(new std::string("aa")));
			vec.push_back(std::make_unique<std::string>(std::string("bb")));
			vec.push_back(std::make_unique<std::string>("cc"));


			__asm nop
			//??? Уничтожение динамически созданных объектов?
		 //???

		//1.c - дополните задание 1.b добавьте возможность изменять хранящиеся строки
		 //следующим образом (например, добавить указанный суффикс: "AAA" -> "AAA_1")  
			for ( auto& i : vec )
			{
				*i += "_1";
			}


			__asm nop
		}

		{//1.d - динамический массив объектов	

		 //Создайте unique_ptr, который является оберткой для динамического массива
		 //с элементами std::string
		 //С помощью unique_ptr::operator[] заполните обернутый массив значениями
		 //Когда происходит освобождения памяти?
			int size = 10;
			std::unique_ptr<int[]> arr(new int[ size ]);
			for ( size_t i = 0; i < size; i++ )
			{
				arr[ i ] = i * 2;
				std::cout << arr[i] << " ";
			}

			__asm nop
		}

		{//1.e - массивы динамических объектов и пользовательская delete-функция (функтор)
		 //Задан стековый массив указателей на динамически созданные объекты
		 //Создайте unique_ptr для такого массива
		 //Реализуйте пользовательскую delete-функцию (функтор) для корректного 
		 //освобождения памяти

			std::string* arStrPtr[] = { new std::string("aa"), new std::string("bb"), new std::string("cc") };

			auto deleter = [ s = std::size(arStrPtr) ](std::string** str)
			{
				for ( size_t i = 0; i < s; i++ )
				{
					delete str[ i ];
				}
			};
			std::unique_ptr<std::string*, decltype( deleter )> arrStr(arStrPtr, deleter);

			
			__asm nop
		}

		{
			// форма с классом - функтор
			std::string* arStrPtr[] = { new std::string("aa"), new std::string("bb"), new std::string("cc") };

			std::unique_ptr<std::string*, Mydeleter> arrStr(arStrPtr, Mydeleter(std::size(arStrPtr)));	
		}

		{
			// через функцию - функтор
			std::string* arStrPtr[] = { new std::string("aa"), new std::string("bb"), new std::string("cc") };

			SIZE = std::size(arStrPtr);

			std::unique_ptr<std::string*, decltype( &deleterFoo )> arrStr(arStrPtr, deleterFoo);


			__asm nop
		}

		{//1.f Создайте и заполните вектор, содержащий unique_ptr для указателей на std::string
			//Посредством алгоритмя copy() скопируйте элементы вектора в пустой список с элементами 
			//того же типа
			//Подсказка: перемещающие итераторы и шаблон std::make_move_iterator
			std::vector<std::unique_ptr<std::string>> vec;

			vec.reserve(5);
			vec.push_back(std::unique_ptr<std::string>(new std::string("aa")));
			vec.push_back(std::make_unique<std::string>(std::string("bb")));
			vec.push_back(std::make_unique<std::string>("cc"));

			std::list<std::unique_ptr<std::string>> L;
			std::copy(std::make_move_iterator(vec.begin()), std::make_move_iterator(vec.end()), std::back_inserter(L));

			__asm nop

		}
		__asm nop

	}

	////////////////////////////////////////////////////////////////////////////////
	//Задание 2.shared_ptr + пользовательская delete-функция 

	//Реализовать возможность записи в файл данных (строчек) из разных источников 
	//(для упрощения пусть источниками являются два массива)
	//Так как все "писатели" будут по очереди записывать свои данные в один и тот же файл,
	//логично предоставить им возможность пользоваться одним и тем же указателем FILE* =>
	//безопасной оберткой для такого указателя является shared_ptr
	//а. Первый владелец должен открыть/создать файл для записи
	//б. Все остальные писатели должны присоединиться к использованию
	//в. Последний владелец указателя должен закрыть файл

	//Подсказка: имитировать порядок записи можно с помощью функции rand()
	
	{
	//например, источники данных:
	char ar1[] = "Writer1";
	char ar2[] = "Writer2";


	std::string path = "test.txt";
	std::ofstream fOut(path);
	//fOut.open(path, std::ofstream::app);
	WriterDeleter writer1(fOut);
	WriterDeleter writer2 = writer1;

	for ( int i = 0; i < 10; i++ )
	{
		if ( rand() & 1 )
		{
			writer1.toFile();
		}
		else
		{
			writer2.toFile();
		}
	}

	//"писатели":
	//Создать writer1, writer2
	/*std::shared_ptr<std::ofstream> writer1(&fOut, WriterDeleter("test.txt"));
	std::shared_ptr<std::ofstream> writer2 = writer1;*/

	

	//fputs(ar1, stdout);
	//fputs(ar2, stdout);

	//заданное число итераций случайным образом позволяем одному из "писателей" записать в файл
	//свою строчку
	//Подсказка: строчки удобно записывать в файл посредством функции fputs()


	__asm nop
	}//закрытие файла???

	
/***************************************************************/
//Задание 3.
	{
		//Дан массив элементов типа string
		std::string strings[] = {"abc", "123", "qwerty", "#$%"};
		//До завершения фрагмента строки должны существовать в единственном экземпляре.
		//Требуется обеспечить манипулирование строками а) без копирования и б) без изменения порядка
		//элементов в массиве!

		auto comp = [](const auto& a, const auto& b)		// компаратор для сортировки значений в set
		{
			return (*a < *b);
		};

		std::set<std::shared_ptr < std::string>, decltype( comp )> s(comp);		// set  для хранения  значений

		//В std::set "складываем" по алфавиту обертки для строк, которые содержат только буквы 
		for ( size_t i = 0; i < sizeof(strings) / sizeof(strings[0]); i++ )
		{
			auto temp = strings[ i ];
			int k = 0;
			bool flag = true;
			while ( temp[k] )
			{
				if ( !std::isalpha(temp[k]) )			//  определяет что символ буква
				{
					flag = false;
					break;
				}
				k++;
			}
			
			if ( flag )
			{
				s.insert(std::shared_ptr<std::string>(&strings[ i ], [](std::string*) { }));
			}
		}

		__asm nop
		/******************************************************************************************/

		//В std::vector "складываем" обертки для строк, которые содержат только цифры 
		//Выводим на экран
		//Находим сумму
		
		std::vector<std::shared_ptr < std::string>> vec;
	
		for ( size_t i = 0; i < sizeof(strings) / sizeof(strings[ 0 ]); i++ )
		{
			auto temp = strings[ i ];
			int k = 0;
			bool flag = true;
			while ( temp[ k ] )							// проходим по массиву
			{
				if ( !std::isdigit(temp[ k ]) )			//  определяет что символ число
				{
					flag = false;
					break;
				}
				k++;
			}
			if ( flag )
			{
				vec.push_back(std::shared_ptr<std::string>(&strings[ i ], [](std::string*) { }));

			}
		}

		__asm nop

		/******************************************************************************************/
		//сюда "складываем" обертки для строк, которые не содержат ни символов букв, ни символов цифр
		//и просто выводим
		std::vector<std::shared_ptr < std::string>> vec2;
		for ( size_t i = 0; i < sizeof(strings) / sizeof(strings[ 0 ]); i++ )
		{
			auto temp = strings[ i ];
			int k = 0;
			bool flag = true;
			while ( temp[ k ] )							// проходим по массиву
			{
				if ( (std::isalpha(temp[ k ])) || (std::isdigit(temp[ k ])) )			//  определяет что ги буква ни число
				{
					flag = false;
					break;
				}
				k++;
			}
			if ( flag )
			{
				vec2.push_back(std::shared_ptr<std::string>(&strings[ i ], [](std::string*) { }));

			}
		}

		__asm nop
	}

	
/******************************************************************************************/
//Задание 4. 
	{
		//Дано:
		std::string ar[] = {"my","Hello", "World"};
		std::vector < std::shared_ptr<std::string>> v = {std::make_shared<std::string>("good"), std::make_shared<std::string>("bye")};
		
		//а) Требуется добавить в вектор обертки для элементов массива, НЕ копируя элементы массива! 
		v.reserve(std::size(ar) + v.size());	// выделяем память
		for ( auto& i : ar )					// проходим по массиву
		{
			v.push_back(std::shared_ptr<std::string>(&i, [](const std::string*) { }));		// добавляем в обертку из массива данные
		}

		//б) Отсортировать вектор по алфавиту и вывести на экран
		std::sort(v.begin(), v.end(), [](auto& x, auto& y) { return *x < *y; });			// сортируем

		__asm nop

		//в) Обеспечить корректное освобождение памяти
		 // deleter  в виде  лямбда [](const std::string*) { }  обеспечивает корректное удаление памяти.  


	}// вызываются деструкторы вектора после закрывающейся скобки


	/***************************************************************/
		//Задание 5. shared_ptr и weak_ptr
		//Создаем генеалогическое дерево посредством класса human. В классе хранятся:
		//имя - string
		//возможно признак: жив или уже нет...
		//родители - shared_ptr (родители не всегда известны...)
		//дети - контейнер из weak_ptr (чтобы избежать циклических зависимостей)

		//Методы класса human:
		//конструктор - для инициализации имени и признака
		//конструктор копирования, оператор присваивания, move ???
		//статический метод child() - 
		//				должен создать создать и вернуть обертку для родившегося человека
		//				+ сформировать все связи ребенка с родителями и наоборот

		//Ввести возможность распечатать генеалогическое дерево для указанного индивидума

	{
		//История должна с кого-то начинаться => "Жили-были дед да баба, например, Адам и Ева"
		//(то есть на самом деле два деда и две бабы):


		std::shared_ptr<human> grandM1(new human("Eva"));
		std::shared_ptr<human> grandF2(new human("Adam"));
		auto first = human::childCreate("First", grandM1, grandF2);

		//childCreate();
		//у них появились дети - child():


		//а у детей в свою очередь свои дети:


		//...
		__asm nop
	}





	__asm nop

}