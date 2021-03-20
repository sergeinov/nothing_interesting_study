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


template<typename T> T& NegateAll( T& data)
{
	for ( auto& i : data )
	{
		-i;
	}
	return data;
}


template<typename T> void absSort(T& data)
{
	sort(std::begin(data), std::end(data), 
		[] (const auto& a, const auto& b)
		{
			if ( abs(a) == abs(b) ) 
			{ 
				return a < b; 
			}
			return abs(a) < abs(b);
		});
}