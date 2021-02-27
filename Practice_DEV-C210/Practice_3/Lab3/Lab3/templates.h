#pragma once
#include<vector>
#include<iostream>

template<typename T>void PrintVector(const std::vector<T>& v)		// распечатать вектор
{ 
	for ( size_t i = 0; i < v.size(); i++ )
	{
		std::cout << v[ i ] << " ";
	}
	std::cout << "\nSize: " << v.size() << "\nCapacity: " << v.capacity() << "\nMaxSize: " << v.max_size()<< std::endl;

};

template<typename T>void PrintVector(const std::vector<T*>& v)		// распечатать указателей
{
	for ( size_t i = 0; i < v.size(); i++ )
	{
		std::cout << *v[ i ] << " ";
	}
	std::cout << "\nSize: " << v.size() << "\nCapacity: " << v.capacity() << "\nMaxSize: " << v.max_size() << std::endl;

};

// vector<vector<T>> - печать для  двумерного вектора
template<typename T>std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> vv)
{
	for ( size_t i = 0; i < vv.size(); i++ )
	{
		for ( size_t j = 0; j < vv[ i ].size(); j++ )
		{
			os << vv[ i ][ j ] << " ";
		}
		os << std::endl;	
	}
	return os;
}


template<typename T> void PrintAll(const T &data)		// распечатать любой контейнер
{
	typename T::const_iterator it;									// переменная итератор
	typename T::value_type type = typename T::value_type();					// тип контейнера
	// for ( auto = data.begin(); auto != data.end(); p++ )
	for ( it = data.begin(); it != data.end(); it++ )
	{
		std::cout << *it << " ";
	}

	std::cout << type << std::endl;
	std::cout << std::endl;
}





template<typename T>void DeleteSameElements(const std::vector<T>& v)
{
	int size = v.size();
	for ( size_t i = 0; i < size; i++ )
	{
		if ( v[i] == v[i+1] )
		{
			v[i] = v.erase(v.begin());
			size = v.size();
		}
	}
	//while ( v1)
	//{
	//	if ( ( *v1 == *( v1 + 1 ) ) )
	//	{
	//		delete v1;
	//	}
	//	else
	//	{
	//		++v1;
	//	}
	//}
};


template<typename T>void DeleteSameElementsWithErase(const std::vector<T>& v1)
{

	typename std::vector<T>::const_iterator itb = v1.begin();		// ? зачем typename
	while ( itb != v1.end() )
	{
		if ( (*itb == *(itb + 1)) )
		{
			itb = v1.erase(itb);
		}
		else
		{
			++itb;
		}
	}
};

