#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<initializer_list>

template<typename T>class MyVector
{
	std::vector<T> v;		// ������ ��������
	T beginArr{};			// �������� �������� ��
	T endArr{};				// ������� �������� ��

public:
	MyVector() = default;
	MyVector(const T& begin, const T& end, std::initializer_list<T> values);

	// ������
	void Add(std::initializer_list<T> values);		// ��������� �������� � ������
	void Delete(std::initializer_list<T> values);	// ������� �������� �� �������
	void Sort(bool val);					// ��������� ������. true - �� �����������  false - �� ��������
	void clearValues();								// ������� ��� �������� � �������
};



//**********************************************************************//
// ����������

template<typename T>
inline MyVector<T>::MyVector(const T& begin, const T& end, std::initializer_list<T> values) : beginArr(begin), endArr(end)
{
	v.reserve(values.size());			// ������� ������ ������ �� ������ ���������������
	for ( auto& i : values )			// ���� �� �������
	{
		// ���� ������ � ��������  begin->end
		if ( (i >= beginArr) && (i <= endArr)  )
		{
			// ���� ��� ��� � � �������
			if ( std::find(v.begin(), v.end(), i) == v.end() )
			{
				v.push_back(i);
			}
		}
	}
}

template<typename T>
inline void MyVector<T>::Add(std::initializer_list<T> values) 
{
	v.reserve(values.size() + v.size());					// ������� ������ ������ �� 1 �������
	for ( const auto& i : values )
	{
		// ���� ������ � �������� ����� begin->end
		if ( ( i >= beginArr ) && ( i <= endArr ) )
		{
			// ���� ��� ��� � �������, �� ���������
			if ( std::find(v.begin(), v.end(), i) == v.end() )
			{				 	
				v.push_back(i);					// ��������� ������� 
			}
		}
	}
	v.shrink_to_fit();
}

template<typename T>
inline void MyVector<T>::Delete(std::initializer_list<T> values)
{
	for ( auto& i : values )
	{
		auto temp = std::find(v.begin(), v.end(), i);		// ���� ���� �� �������� � �������
		if ( temp != v.end() )								// ��������� �������, ��� �������� ����
		{
			v.erase(temp);									//  ������� �� ������ ��������� ��������� ��������
		}
	}
}

template<typename T>
inline void MyVector<T>::Sort(bool val)
{
	//if ( val )
	//{
	//	std::sort(v.begin(), v.end(), std::less<T>());			// ���������� �� �����������
	//}
	//else
	//{
	//	std::sort(v.begin(), v.end(), std::greater<T>());		// ���������� �� ��������
	//	/*std::sort(v.begin(), v.end(),
	//		[](int a, int b)
	//		{
	//			return a > b;
	//		});*/	
	//}
	std::sort(v.begin(), v.end(), [val](int a, int b)
			{
				if ( val )
				{
					return a > b;
				}
				return a < b;
			});
}

template<typename T>
inline void MyVector<T>::clearValues()
{
	v.clear();							// ����� cler ������� �������� �������
}


