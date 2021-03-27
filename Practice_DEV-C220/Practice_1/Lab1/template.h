#pragma once
#include<iostream>
#include<map>
#include<set>
#include<iterator>

// распечатать контейнер через range for
template<typename T> void PrintAnyCont(const T& data)
{
	for (const auto& i : data)
	{
		std::cout << i << " ";
	}
	std::cout  << std::endl;
}

// перегрузка унарного минуса стандартного класса  string для функции "отрицания"  значений
inline std::string operator-(std::string s)
{
	for ( auto& i : s )
	{
		if ( islower(i) )
		{
			i = toupper(i);
		}
		else
		{
			i = tolower(i);
		}		
	}
	return s;
}

// функция для "отрицания" любых значений последовательности
//было: {1, -2, 5}, стало: {-1, 2, -5})
//изменение объектов типа std::string может выглядеть "aBc1" -> "AbC1"
template<typename T> void NegateAll( T& data)
{
	for ( auto& i : data )
	{
		i = -i;
	}
}

// шаблон предиката для  сортировки по значению без учета отрицательное/положительное число
template<typename T> void absSort(T& data)
{
	std::sort(std::begin(data), std::end(data), 
		[] (const auto& a, const auto& b)
		{
			//if ( abs(a) == abs(b) ) 
			//{ 
			//	return a < b; 
			//}
			return abs(a) < abs(b);
		});
}



//возвращает вектор, каждый элемент которого является суммой элементов двух 
//последовательностей РАЗНОЙ длины и с элементами РАЗНОГО типа.
template<typename T, typename A> auto SumCont(const T& data, const A& data2)
{
	// decltype   вычисляет тип векктора с помощью выражения из двух контейнеров
	std::vector<decltype( *( std::begin(data) ) + *( std::begin(data2) ) )> v
	(
		std::max(std::size(data), std::size(data2))			// инициализируем вектор  наибольшим размером из двух параметров контейнеров
	);

	std::copy(std::begin(data), std::end(data), v.begin());		// копируем из первого контейнера в вектор v

	// трансформируем из одной последовательности в другую прибавляя числа из двух контейнеров v  и  data2
	std::transform(std::begin(data2), std::end(data2), v.begin(), v.begin(), [](const auto& x, const auto& y)
		{
			return x + y;		// складываем 
		});

	return v;
}


//Функция должна "разложить" значения заданной последовательности в два пустых контейнера 
template<typename T, typename C, typename A, typename P> void Separate(const T& data,  C& data2, A& data3,  P pred)
{
	//typedef decltype( *std::begin(data) ) value_type;		// узнаем типа данных в контейнерах

	// если типы совпадают то раскладываем вектор
	if ( (typeid(T::value_type) == typeid(C::value_type)) && (typeid( T::value_type ) == typeid( A::value_type )) )
	{
		for ( const auto& i : data )
		{
			// делим вектор на четные не четные. Четные в С последовательность, нечетные в А

			if ( pred( i ) )
			{
				//inserter(data2, data2.begin())  = i;
				data2.insert(data2.end(), i);
			}
			else
			{
				//inserter(data3, data3.begin()) = i;
				data3.insert(data3.end(), i);
			}
		}
	}

}


///  задание 10

enum COLOR: unsigned char { GREEN, YELLOW };
enum DAYS: unsigned char {MONDAY, TUESDAY };

template <typename T> std::map<std::string, T> mp;

template <typename T> T stringToEnum(const std::string& str)
{
	return mp<T>.at(str);
}

template <typename T> const std::string& enumToString(T _enums)
{
	for ( auto& [key, value] : mp<T> )
	{
		if ( value == _enums )
		{
			return key;
		} 
	}
	throw "Not found";
}