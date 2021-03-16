#pragma once
#include<iostream>
#include <queue>
#include<deque>
#include<map>
#include<set>

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
template<typename T> std::ostream& operator<<(std::ostream& os, const std::multiset<const T>& v)
{
	for ( auto it = v.begin(); it != v.end(); it++ )
	{
		os << "\n" << *it << std::endl;										// распечатываем  // для Map используется перегруженный operator<< для распечатки Pair используется
	}

	return os;

}
// распечатать пару ключ/значение
template<typename T, typename V> std::ostream& operator<<(std::ostream& os, const std::pair<const T, V>& v)
{
	os << "\n" << v.first << ": " << 
		v.second << std::endl;
	return os;	

}




//template<class M>
//void printMultiMap(const M& mmap)
//{
//	for ( auto& e : mmap )
//		std::cout << "{" << e.first << "," << e.second << "} ";
//	std::cout << '\n';
//}

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
	typename std::map<const char*, int>::iterator iter = m.begin();
	//auto iter = m.find(changeSurname);

	if ( iter != m.end() )			// если указывает на конец значит Ивановой нету в Map
	{
		A temp = (*iter).second;				// запомнить  зарплату

		m.erase(iter);							// удаляем старую пару

		m[ surname ] = temp;					// создаем Новую пару, с новой фамилией, со старым значением взятого из удаленной пары
	}

	bool temp = m.contains(changeSurname);		// contains из  с++20 стандарта. для поддержкив компилятор вставляем ключик /std:c++latest
	
}


// перевод слова
template<typename T, typename A, typename P> void myTranslater(const std::multimap<T, A, P>& m, const T& word)
{
	typename std::multimap<T, A, P>::const_iterator it1;
	typename std::multimap<T, A, P>::const_iterator it2;		// используем второй итератор для поиска всех ключей по заданному ключу

	std::cout << "\n" << "Слово: " << word << std::endl;
	
	it1 = m.lower_bound(word);		//  возвращается  указатель на слово
	it2 = m.upper_bound(word);		// возвращается указатель следующий адрес после последнего похожего слова

	if ( it1 == it2 )			// если слово не найдено выход
	{
		std::cout << "\n" << "Совпадений не найдено" << std::endl;
	}

	while ( it1 != it2 )		// проходим по диапазону  между it1 - it2
	{
		std::cout << "\n" << "перевод: " << ( *it1 ).second << std::endl;
		++it1;								// двигаемся по итератору к следующему слову	
	}


}