#pragma once
#include<iostream>



// ����������� ���� ����/��������
template<typename T, typename V> std::ostream& operator<<(std::ostream& os, const std::pair<const T, V>& v)
{
	os << "\n" << v.first << ": " << v.second << std::endl;
	return os;
}

// ����������� ����� ���������
template<typename T> void PrintAll(const T& data)
{
	typename T::const_iterator it;										// ���������� ��������
	//typename T::value_type type = typename T::value_type();					// ��� ����������
	std::cout << "\n\n" << typeid( T ).name() << std::endl;				// ����� ���� ����������
	std::cout << typeid( typename T::value_type ).name() << std::endl;	//  �����  ����� ����������

	for ( it = data.begin(); it != data.end(); it++ )
	{
		std::cout << *it << " ";										// �������������  // ��� Map ������������ ������������� operator<< ��� ���������� Pair ������������
	}

	std::cout << std::endl;
}

// Print ��������
template<typename T> void printElement(const T& element)
{
	std::cout << "\n" << element << " ";		// ����������� �������
}

//void PrintInt(int value)
//{
//	std::cout << value << std::endl;
//}
//
// ����������� ����� ��������� �����  for_each
template<typename T> void printContainer(const T& value)
{
	std::for_each(
		value.begin(), 
		value.end(), 
		printElement<T>);
}


// ����� ������ �������
//template<typename T> void printContainer(const T& v)
//{
//	std::for_each(
//		v.begin(),
//		v.end(),
//		[](int value) { std::cout << value << " "; }
//	);
//}


// ���������  �������� �������� ������
template<typename T> void changeValue(T& data)
{
	
}