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



