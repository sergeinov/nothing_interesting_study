#pragma once
#include<iostream>
#include <queue>
#include<deque>
#include<map>

template<typename T> const typename T::value_type& topAll(const T& adapter)
{
	return adapter.top();
}

//template<typename T> const typename T::value_type& topAll(const T& adapter)
//{
//	return *(adapter.top());
//}

template<typename T, typename C> const T& topAll(const std::queue<T, C>& adapter)
{
	return adapter.front();
}

template<typename A>void PrintAdapter(A a)
{
	if ( a.empty() )
	{
		std::cout << "\nEmpty!!!" << std::endl;
	}

	while ( !a.empty() )
	{
		std::cout << topAll(a) << " ";
		
		a.pop();
	}
	std::cout << std::endl;
}

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
	std::cout << "\n" << typeid( T ).name() << std::endl;				// ����� ���� ����������
	std::cout << typeid( typename T::value_type ).name() << std::endl;	//  �����  ����� ����������

	for ( it = data.begin(); it != data.end(); it++ )
	{
		std::cout << *it << " ";										// �������������  // ��� Map ������������ ������������� operator<< ��� ���������� Pair ������������
	}

	std::cout << std::endl;
}



 // ����������� map 
template<typename T, typename A, typename P> void PrintMap(const std::map<T, A, P>& m)
{
	typename std::map<T, A, P>::const_iterator it = m.begin();
	//auto it = m.begin();
	while ( it != m.end() )
	{
		std::cout << "\n" << (*it).first << ": " << (*it).second << std::endl;
		++it;
	}
}

// ������� ����-�������
template<typename T, typename A, typename P> void changeKeyName(std::map<T, A, P>& m, const T& changeSurname , const T& surname)
{
	typename std::map<const char*, int>::iterator iter;
	//auto iter = m.find(changeSurname);

	if ( iter != m.end() )			// ���� ��������� �� ����� ������ �������� ���� � Map
	{
		A temp = (*iter).second;				// ���������  ��������

		m.erase(iter);							// ������� ������ ����

		m[ surname ] = temp;					// ������� ����� ����, � ����� ��������, �� ������ ��������� ������� �� ��������� ����
	}
}