#pragma once
#include<iostream>
#include <queue>
#include<deque>
#include <map>

template<typename T> const typename T::value_type& topAll(const T& adapter)
{
	return adapter.top();
}

template<typename T> const T& topAll(const std::queue<T>& adapter)
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
	
}


// ����������� ����� ���������
template<typename T> void PrintAll(const T& data)
{
	typename T::const_iterator it;										// ���������� ��������
	//typename T::value_type type = typename T::value_type();					// ��� ����������
	std::cout << "\n" << typeid( T ).name() << std::endl;						// ����� ���� ����������
	std::cout << typeid( typename T::value_type ).name() << std::endl;	//  �����  ����� ����������

	for ( it = data.begin(); it != data.end(); it++ )
	{
		std::cout << *it << " ";										// �������������
	}

	std::cout << std::endl;
}



// ����������� map / multimap
template<typename T, typename A> void PrintAll(const std::map<T, A>& m)
{
	typedef map<T, A>::iterator it = m.begin();
	while ( it != m.end() )
	{
		std::cout << "\n" << (*it).first << ": " << (*it).second << std::endl;
		++it;
	}
}