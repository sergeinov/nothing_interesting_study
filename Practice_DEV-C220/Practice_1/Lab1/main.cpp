//Практика 1:
// enum class
// initializer_list и универсальные списки инициализации
// auto
// decltype
// lambda 
// template variable

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
#include <set>
#include"template.h"
#include"String.h"
#include <list>
#include <deque>


std::ostream& operator<<(std::ostream& out, const String& s) 
{ 
	return out << s.str;
};

// задание 10
// специализации
template <> std::map<std::string, COLOR> mp<COLOR> { {"GREEN", COLOR::GREEN }, {"YELLOW", COLOR::YELLOW}};
template <> std::map<std::string, DAYS> mp<DAYS> { {"MONDAY", DAYS::MONDAY}, {"TUESDAY", DAYS::TUESDAY}};


int main()
{
	//Задание 1. 
	{
		enum class months { January, February, March/*...*/ };
		enum class weekDays { Monday, Tuesday /*...*/ };

		months m = months::January;			// область видимости
		//а) уберите проблемы (это значит, что КОМПИЛЯТОР не
		//должен позволять программисту осуществлять опасные
		//сравнения!)
		// Проблемы в сравнении  разных типов enum
		// После с++17 появилось возможность добавить в перечисление class

		// if (m == Monday)	// ошибка
		// if ( m == weekDays::Monday ) // ошибка d сравнении  разных типов enum
		if ( static_cast< weekDays >(m) == weekDays::Monday )		// приведение типа months -> weekDays
		{ 
			/*...*/ 
		}

		//б) оптимизируйте использование памяти
		{
			enum class months : unsigned char { January, February, March/*...*/ };
			months year[] = { months::January, months::February, months::March };

			size_t n = sizeof(year); // !  3  Без оптимизации // 12

			__asm nop
		}
	}


/**********************************************************/
	//Задание 2. Создайте и с помощью списка инициализации
	//заполните значениями вектор с элементами - string
	//С помощью range-based for преобразуйте все буквы в 	
	//верхний регистр а остальные символы должны остаться
	//неизменными
	{
		std::vector<std::string> vect{"robot3", "car1", "plane12", "bus34"};
		for ( auto& i : vect )
		{
			for ( auto& j : i )
			{
				j = toupper(j);
			}
		}
		for ( const auto& i : vect )
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		__asm nop
	}


/**********************************************************/
	///Задание 3. Создайте и заполните значениями
	//map таким образом, чтобы он содержал в качестве ключа
	//букву, а в качестве значения отсортированную по 
	//алфавиту совокупность слов (string), начинающихся с
	//этой буквы
	
	//3а. Проинициализируйте map "вручную" посредством списка инициализации
	//С помощью range-based for и structured binding
 	//распечатайте содержимое, например: A: any, apple, away
	{
		//const char* words[] = { "Abba", "Alfa", "Beta", "Beauty" };
		std::map<char, std::set<std::string>> mp = { 
													{'W', {"Wer", "Was"}},
													{'A', {"Art"," Apple"} } 
													};
		for ( const auto& [ letter, word ] : mp)
		{
			std::cout << letter << ":";
			for ( const auto& i : word )
			{
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}
		
		//PrintAll(mp);
		__asm nop
	}

	//3б. Создайте пустой map и используйте заданный массив
	//для выполнения задания.
	//С помощью range-based for и structured binding
	//распечатайте содержимое, например: A: any, apple, away
	{
		//дано (например):
		const char* s[] = { "yong", "away", "bar", "any", "son", "apple" };
		std::map<char, std::set<std::string>> mp2;
		for ( const auto i : s )
		{
			mp2[ tolower(i[ 0 ]) ].insert(i);
		}
		// печатаем
		for ( const auto& [letter, word] : mp2 )
		{
			std::cout << static_cast<char>(toupper(letter)) << ":";
			for ( const auto& i : word )
			{
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}


		__asm nop
	}


/*********************************************************/
	//Задание 4. создать функцию для вывода на печать
	//элементов последовательностей, заданных ниже:
	{
		std::vector<double> vd = { 1.1,2.2,3.3 };
		PrintAnyCont(vd);

		std::string s("abc");
		PrintAnyCont(s);

		int ar[] = { 1, 2, 3 };
		PrintAnyCont(ar);

		std::initializer_list<int> il{ 3,4,5 };
		PrintAnyCont(il);		

		__asm nop
	}


/********************************************************/
	///Задание 5. 	
	//Cоздать функцию для "отрицания" значений, например:
	//было: {1, -2, 5}, стало: {-1, 2, -5})
	//изменение объектов типа std::string может выглядеть "aBc1" -> "AbC1"
	//элементов последовательностей, заданных ниже:

	//  перегрузить operator-  для string/  Для изменения использовать tolower/toupper
	{
		std::cout << "\n" << "Negative convertor:" << std::endl;
		std::vector<double> vd{ 1.1,2.2,3.3 };
		NegateAll(vd);
		PrintAnyCont(vd);

		std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
		NegateAll(ls);
		PrintAnyCont(ls);

		int ar[]{ 1, 2, 3 };
		NegateAll(ar);
		PrintAnyCont(ar);

		__asm nop

	}

	
/********************************************************/
	//Задание 6. Реализовать функцию сортировки по модулю
	//элементов последовательностей, заданных ниже
	//Собственно для сортировки можно использовать обобщенный
	//алгоритм sort(), а для задания условия - лямбда-функцию
	{
		std::cout << "\n" << "Sort:" << std::endl;
		std::vector<double> vd = { -3.3,  2.2, -1.1 };
		absSort(vd);
		PrintAnyCont(vd);
		__asm nop

		int ar[] = { -3, 2, -1 };
		absSort(ar);
		PrintAnyCont(ar);
		__asm nop
	}


/********************************************************/
	//Задание 7.
	//Напишите функцию, которая будет формировать и
	//возвращать вектор, каждый элемент 
	//которого является суммой элементов двух 
	//последовательностей РАЗНОЙ длины
	//и с элементами РАЗНОГО типа.

	//Подсказка 1: так как последовательности могут быть
	//разной длины, логично сделать размер результирующего
	//вектора максимальным из двух
	 
	//Подсказка 2: подумайте о возможности использования
	//алгоритмов copy() и transform(), в котором 
	//трансформирующее действие удобно в свою очередь
	//задавать лямбда-функцией

	//например:
	{
		std::cout << "\n" << "Sort:" << std::endl;

		std::vector<int> v{ 1,2,3,4 };
		std::list<double> lt{ 1.1, 2.2, 3.3, 4.4, 5.5 };

		auto resultVector = SumCont(v, lt);
		PrintAnyCont(resultVector);

		std::list<int> ll{ 1, 2, 3, 4, 5, 6, 7, 8 };
		double ar[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		auto resultVector2 = SumCont(ar, ll);
		PrintAnyCont(resultVector2);

		std::set<std::string> s{ "abc", "qwerty", "my"};
		std::deque<const char*> d{ "111", "22" };
		auto resultVector3 = SumCont(s, d);
		PrintAnyCont(resultVector3);

		__asm nop
	}


/********************************************************/	
	//Задание 8. Реализуйте функцию, которая принимает следующие параметры:	
	//сформированную последовательность любого типа с элементами любого типа, 
	//два (пустых) контейнера любого типа из vector, list, deque, set 
	//с элементами того же типа, что и у сформированной последовательности 

	//Функция должна "разложить" значения заданной последовательности в два пустых контейнера 
	//согласно заданному условию. Условие задать лябда-функцией
	//Исходная последовательность при этом не меняется
	{
		std::cout << "\n" << "Separate:" << std::endl;
		////Например:
		std::vector<int> v{ 1,2,3,4,5 };
		std::list<int> l; //сюда четные
		std::deque<int> d; //а сюда нечетные
		Separate(v, l, d, [](auto num) 
			{
				return  num % 2;
			});

		PrintAnyCont(l);
		PrintAnyCont(d);
		__asm nop
	}


/********************************************************/
	//Задание 9. C помощью алгоритма for_each()!!! 
	//(а не count_if()) посчитать сколько букв в верхнем
	//регистре.
	//  Использовать лямбда функцию
	{
		char s[] = "Hello World!";


		//for_each

		int count = 0;
		auto result = std::for_each(s, std::end(s), [&count] (char v)
			{ 
				if ( isupper(v) )		// проверка функцией, что буква Большая
				{
					count++;			// считаем сколько букв
				}
			});
		
		std::cout <<  "\n" << "count: " << count << std::endl;
		__asm nop
	}


/********************************************************/
	//Задание 10. Реализовать конвертацию enum в строковое представление  - enumToString
	// и наоборот - stringToEnum

	//Подсказки: 
	//***********
	//1. Соответствующие именованным константам строки все равно нужно где-то хранить =>
	//1.1 Именованные константы в перечислении должны быть уникальными => соответствующие строки
	//тоже должны быть уникальными, => уникальные строки могут быть использованы в качестве
	//ключа в std::map
	
	//1.2 а вот значения (соответствующие именованым константам)
	//могут быть любыми и даже могут повторяться (упрощаем задачу, считая, что значения НЕ повторяются) 
	//=> подходит контейнер std::map<string,<значение> >
	
	//1.3 Согласно стандарту С++11 переменные перечислимого типа могут быть разного размера и типа,
	//а хотелось бы обеспечить универсальную конвертацию 
	
	//***********
	//2. Так как типы перечислений разные, то enumToString и stringToEnum должны быть шаблонными
	//2.1 Пользователь может ошибиться или злонамеренно передать в функции значения, которым
	//   ничего не соответствует => защита!
	//2.2 В функциях enumToString и stringToEnum (в зависимости от типа перечисления) нужно будет
	//   анализировать соответствующий используемому типу перечисления контейнер
	
	//***********
	//3. Чтобы действия с map<string, <значение> > не зависили от типа перечисления, подумайте над использованием
	//шаблонной переменной (в частности вспомните о возможности специялизации шаблонной переменной)
	

	//***********

	{
	//Например:

		COLOR c1;
		try {
			c1 = stringToEnum<COLOR>("GREEN");
		}
		catch (...)
		{
			std::cout << "Pair undefined" << std::endl;
		}
		std::string Str;
		try
		{
			Str = enumToString(c1);
		}
		catch ( const char* )
		{
			std::cout << "error" << std::endl;
		}


		__asm nop
	}

	return 0;
}