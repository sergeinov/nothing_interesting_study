#pragma once
#include<vector>
#include<iostream>

template<typename T>void PrintVector(const std::vector<T>& v) 
{ 
	for ( size_t i = 0; i < v.size(); i++ )
	{
		std::cout << v[ i ] << " ";
	}
	std::cout << "\nSize: " << v.size() << "\nCapacity: " << v.capacity() << "\nMaxSize: " << v.max_size()<< std::endl;

};

template<typename T>void PrintVector(const std::vector<T*>& v)
{
	for ( size_t i = 0; i < v.size(); i++ )
	{
		std::cout << *v[ i ] << " ";
	}
	std::cout << "\nSize: " << v.size() << "\nCapacity: " << v.capacity() << "\nMaxSize: " << v.max_size() << std::endl;

};









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

