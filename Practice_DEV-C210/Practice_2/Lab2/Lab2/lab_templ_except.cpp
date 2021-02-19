//Исключения

//Шаблоны: 
	//		шаблоны функций,
	//		шаблоны классов,


#include <tchar.h>
#include<iostream>
//#include <stdexcept>
#include"Template.h"
#include"MyString.h"
#include"MyStack.h"
#include "MyStack2.h"
//#include"MyArrayError.h"
//#include"MyEmptyStack.h"

#define stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");


////////////////////////////////////////////////////////////////////////////
	//Тема. Шаблоны функций.
	//Создайте шаблон функции перестановки местами двух
	//значений - Swap(). Проверьте работоспособность созданного
	//шаблона с помощью приведенного ниже фрагмента кода.
	//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.

	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);


	//Подсказка 2: подумайте, что нужно реализовать, для того,
	//			чтобы следующий вызов работал с объектами MyString
	//			не только корректно, но и эффективно
	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	//Swap("ABS", "DCB");


/////////////////////////////////////////////////////////////////////
	
	//Тема. Шаблоны классов.
	//Задание 1.
	//Создайте шаблон класса MyStack для хранения элементов любого типа T.
	//Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
	//			для хранения последовательно расположенных в памяти элементов
	//			является массив, 
	//			2.для задания максимального размера стека может быть использован
	//			параметр-константа шаблона
	//			3.обязательными операциями со стеком являются "push" и "pop". Для
	//			того, чтобы гарантировать корректное выполнение этих операций 
	//			хорошо было бы генерировать исключение в аварийной ситуации
	//			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
	//			мог читать/изменять значения только тех элементов, которые он формировал

	MyStack<int, 5> stack;
	try
	{
		stack.push(5);
		stack.push(10);
		stack.push(15);
		std::cout << stack << std::endl;

		int res = stack.pop();
		std::cout << stack << std::endl;

		stop

		int res2 = stack.pop();
		std::cout << stack << std::endl;

		stop

		int res3 = stack[ 0 ];
		std::cout << "Значение по индексу: "<<res3 << std::endl;

		stop

		std::cout << "Массив:" << std::endl;
		std::cout << stack << std::endl;

		stop
	}
	catch(MyStackFullError& error){

		std::cout << "My stack is full! Current size is" << error.GetSize() << std::endl;
	}
	catch ( MyArrayError& error )
	{
		std::cout << "Index out of range! " << "Current: " << error.m_wrong_Index << " Must be >= 0  or " << error.m_MaxIndex << std::endl;

	}
	catch(MyEmptyStack& error)
	{
		std::cout << "Stack is empty: " << error.m_number << std::endl;

	}
	catch ( ... )
	{
		std::cout << "Something wrong" << std::endl;
	}
	


	//С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
	//стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
	//push() и pop(), operator[]




	//Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы 
	//для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
	//Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
	//пользователь
	{
		std::cout << "\n**************Задание 2***********" << std::endl;

		MyStack2<int> list;

		list.push(3);
		list.push(5);
		list.push(22);
		std::cout << "\nСписок!\n" << std::endl;
		for ( size_t i = 0; i < list.GetSize(); i++ )
		{
			std::cout << list[ i ] << " ";
		}

		stop

		std::cout << "\n\nУдаляем элемент сверху списка!\n" << std::endl;
		list.pop();
		for ( size_t i = 0; i < list.GetSize(); i++ )
		{
			std::cout << list[ i ] << " ";
		}

		std::cout << "\n\nУдаляем список!\n" << std::endl;
		list.clear();
		for ( size_t i = 0; i < list.GetSize(); i++ )
		{
			std::cout << list[ i ] << " ";
		}


	}



	

	return 0;
}

