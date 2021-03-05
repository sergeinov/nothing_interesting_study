#pragma once
#include<iostream>
#include <queue>
#include<deque>
#include<map>

template<typename T> const typename T::value_type& topAll(const T& adapter)
{
	return adapter.top();
}

//template<typename T> const typename T::value_type& topAll(const T& adapter)
//{
//	return *(adapter.top());
//}

template<typename T, typename C> const T& topAll(const std::queue<T, C>& adapter)
{
	return adapter.front();
}

template<typename A>void PrintAdapter(A a)
{
	if ( a.empty() )
	{
		std::cout << "\nEmpty!!!" << std::endl;
	}

	while ( !a.empty() )
	{
		std::cout << topAll(a) << " ";
		
		a.pop();
	}
	std::cout << std::endl;
}

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
	std::cout << "\n" << typeid( T ).name() << std::endl;				// вывод типа контейнера
	std::cout << typeid( typename T::value_type ).name() << std::endl;	//  вывод  имени контейнера

	for ( it = data.begin(); it != data.end(); it++ )
	{
		std::cout << *it << " ";										// распечатываем  // для Map используется перегруженный operator<< для распечатки Pair используется
	}

	std::cout << std::endl;
}



 // распечатать map 
template<typename T, typename A, typename P> void PrintMap(const std::map<T, A, P>& m)
{
	typename std::map<T, A, P>::const_iterator it = m.begin();
	//auto it = m.begin();
	while ( it != m.end() )
	{
		std::cout << "\n" << (*it).first << ": " << (*it).second << std::endl;
		++it;
	}
}

// сменить ключ-Фамилию
template<typename T, typename A, typename P> void changeKeyName(std::map<T, A, P>& m, const T& changeSurname , const T& surname)
{
	typename std::map<const char*, int>::iterator iter;
	//auto iter = m.find(changeSurname);

	if ( iter != m.end() )			// если указывает на конец значит Ивановой нету в Map
	{
		A temp = (*iter).second;				// запомнить  зарплату

		m.erase(iter);							// удаляем старую пару

		m[ surname ] = temp;					// создаем Новую пару, с новой фамилией, со старым значением взятого из удаленной пары
	}
}