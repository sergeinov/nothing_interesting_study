#pragma once
#include<vector>
#include<iostream>


// распечатать вектор
template<typename T>void PrintVector(const std::vector<T>& v)		
{ 
	for ( size_t i = 0; i < v.size(); i++ )
	{
		std::cout << v[ i ] << " ";
	}
	std::cout << "\nSize: " << v.size() << "\nCapacity: " << v.capacity() << "\nMaxSize: " << v.max_size()<< std::endl;

};

// распечатать вектор указателей
template<typename T>void PrintVector(const std::vector<T*>& v)		
{
	for ( size_t i = 0; i < v.size(); i++ )
	{
		std::cout << *v[ i ] << " ";
	}
	std::cout << "\nSize: " << v.size() << "\nCapacity: " << v.capacity() << "\nMaxSize: " << v.max_size() << std::endl;

};

//  способ
// vector<vector<T>> - печать для  двумерного вектора
//template<typename T>std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> vv)
//{
//	for ( size_t i = 0; i < vv.size(); i++ )
//	{
//		for ( size_t j = 0; j < vv[ i ].size(); j++ )
//		{
//			os << vv[ i ][ j ] << " ";
//		}
//		os << std::endl;	
//	}
//	return os;
//}

//  работает для одномерных и двумерных векторов
template<typename T>std::ostream& operator<<(std::ostream& os, const std::vector<T>& vv)	// vector<vector<T>> -печать для  двумерного вектора
{
	for ( size_t i = 0; i < vv.size(); i++ )
	{
		os << vv[ i ] << " ";					//  при одномерном массиве будет печатать значения
												// при двумерном инстанцируется - вызывается второй раз на уровне <<   и печатает значения как для одномерного массива
		/*
		* // не подходящий способ
		for ( size_t j = 0; j < vv[ i ].size(); j++ )
		{
			os << vv[ i ][ j ] << " ";
		}*/	
	}
	os << std::endl;
	return os;
}

// функция добавляет значение, если нет в векторе
template<typename T> void MyAdd(std::vector<T>& v, const T& data)	
{
	for ( size_t i = 0; i < v.size(); i++ )
	{
		if ( v[i] == data )				// проверяем есть ли значение в векторе
		{
			return;
		}
	}
	v.insert(v.begin(), data);			// добавляем  в начало
}


// распечатать любой контейнер
template<typename T> void PrintAll(const T &data)		
{
	typename T::const_iterator it;										// переменная итератор
	//typename T::value_type type = typename T::value_type();					// тип контейнера
	std::cout << typeid( T ).name() << std::endl;						// вывод типа контейнера
	std::cout << typeid( typename T::value_type ).name() << std::endl;	//  вывод  имени контейнера

	for ( it = data.begin(); it != data.end(); it++ )
	{
		std::cout << *it << " ";										// распечатываем
	}

	std::cout << std::endl;
}


// удаляет только повторяющиеся последовательности.
//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"
template<typename T>void DeleteSameElements(std::vector<T>& v)		
{
	typename std::vector<T>::iterator it = v.begin();
	while ( it != v.end() )
	{
		typename std::vector<T>::iterator first = it;		// переменная на начало вектора
		typename std::vector<T>::iterator last = it + 1;	// переменая и на следующий элемент

		while ( last != v.end() )			//  
		{
			if ( *first == *last )		// сравниваем значения
			{
				last++;					// если равно увеличиваем итератор дальше
			}
			else
			{
				break;
			}
		}
		if ( last != it + 1 )	
		{
			it = v.erase(first, last);		// удаляем диапазон.
		}
		else
		{
			++it;						// увеличиваем  начальный адрес вектора
		}
	}
};


//	 функция удаления из любого вектора всех дублей 
//Например: было - "qwerrrrty12222r3", стало - "qwerty123"
template<typename T>void DeleteSameElementsWithErase(std::vector<T>& v1)
{

	typename std::vector<T>::iterator it1 = v1.begin();
	while ( it1 != (v1.end()) )
	{
		typename std::vector<T>::iterator first = it1;		// переменная на начало вектора
		typename std::vector<T>::iterator last = it1 + 1;	// переменая и на следующий элемент

		while ( last != v1.end())			//  от следующего элемента до конца vector
		{
			if ( *first == *last )			// сравниваем значения
			{
				it1 = v1.erase(first);		// удаляем значение.	
			}
			else
			{
				last++;					//  увеличиваем итератор дальше
			}
		}

		it1++;						// увеличиваем итератор цикла

	}
};


