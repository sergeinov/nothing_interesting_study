#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<initializer_list>

template<typename T>class MyVector
{
	std::vector<T> v;
	T beginArr{};
	T endArr{};

public:
	MyVector() = default;

	MyVector(const T& begin, const T& end, std::initializer_list<T> values);
};

template<typename T>
inline MyVector<T>::MyVector(const T& begin, const T& end, std::initializer_list<T> values) : beginArr(begin), endArr(end)
{
	v.reserve(values.size());			// создает память
	for ( auto& i : values )
	{
		// если входит в диапазон  begin->end
		if ( (i >= beginArr) && (i <= endArr)  )
		{
			// если есть уже в векторе
			if ( std::find(v.begin(), v.end(), i) == v.end() )
			{
				v.push_back(i);
			}
		}
	}
}
