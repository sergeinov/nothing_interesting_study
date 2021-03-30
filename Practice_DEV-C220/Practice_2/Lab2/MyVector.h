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
	v.reserve(values.size());			// ������� ������
	for ( auto& i : values )
	{
		// ���� ������ � ��������  begin->end
		if ( (i >= beginArr) && (i <= endArr)  )
		{
			// ���� ���� ��� � �������
			if ( std::find(v.begin(), v.end(), i) == v.end() )
			{
				v.push_back(i);
			}
		}
	}
}
