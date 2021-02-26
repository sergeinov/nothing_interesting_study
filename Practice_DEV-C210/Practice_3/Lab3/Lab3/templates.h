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
			v[i] = v.erase(v.begin() + i);
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
	/*vector<T>::iterator itb = v1.begin();
	while ( itb != v.end )
	{
		if ( (*itb == *(itb + 1)) )
		{
			itb = v1.erase(itb);
		}
		else
		{
			++itb;
		}
	}*/
};

