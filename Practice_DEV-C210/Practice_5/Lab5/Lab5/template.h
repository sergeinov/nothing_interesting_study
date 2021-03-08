#pragma once
#include<iostream>



// распечатать пару ключ/значение
template<typename T, typename V> std::ostream& operator<<(std::ostream& os, const std::pair<const T, V>& v)
{
	os << "\n" << v.first << ": " << v.second << std::endl;
	return os;
}

// распечатать любой контейнер
template<typename T> void PrintAll(const T& data)
{
	typename T::const_iterator it;										// переменная итератор
	//typename T::value_type type = typename T::value_type();					// тип контейнера
	std::cout << "\n\n" << typeid( T ).name() << std::endl;				// вывод типа контейнера
	std::cout << typeid( typename T::value_type ).name() << std::endl;	//  вывод  имени контейнера

	for ( it = data.begin(); it != data.end(); it++ )
	{
		std::cout << *it << " ";										// распечатываем  // для Map используется перегруженный operator<< для распечатки Pair используется
	}

	std::cout << std::endl;
}

// Print предикат
template<typename T> void printElement(const T& element)
{
	std::cout << "\n" << element << " ";		// распечатать элемент
}

//void PrintInt(int value)
//{
//	std::cout << value << std::endl;
//}
//
// распечатать любой контейнер через  for_each
template<typename T> void printContainer(const T& value)
{
	std::for_each(
		value.begin(), 
		value.end(), 
		printElement<T>);
}


// через лямбда функции
//template<typename T> void printContainer(const T& v)
//{
//	std::for_each(
//		v.begin(),
//		v.end(),
//		[](int value) { std::cout << value << " "; }
//	);
//}


// изменение  значений входящих данных
template<typename T> void changeValue(T& data)
{
	
}