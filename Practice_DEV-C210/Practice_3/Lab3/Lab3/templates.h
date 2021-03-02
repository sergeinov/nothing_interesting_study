#pragma once
#include<vector>
#include<iostream>


// ����������� ������
template<typename T>void PrintVector(const std::vector<T>& v)		
{ 
	for ( size_t i = 0; i < v.size(); i++ )
	{
		std::cout << v[ i ] << " ";
	}
	std::cout << "\nSize: " << v.size() << "\nCapacity: " << v.capacity() << "\nMaxSize: " << v.max_size()<< std::endl;

};

// ����������� ������ ����������
template<typename T>void PrintVector(const std::vector<T*>& v)		
{
	for ( size_t i = 0; i < v.size(); i++ )
	{
		std::cout << *v[ i ] << " ";
	}
	std::cout << "\nSize: " << v.size() << "\nCapacity: " << v.capacity() << "\nMaxSize: " << v.max_size() << std::endl;

};

//  ������
// vector<vector<T>> - ������ ���  ���������� �������
//template<typename T>std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> vv)
//{
//	for ( size_t i = 0; i < vv.size(); i++ )
//	{
//		for ( size_t j = 0; j < vv[ i ].size(); j++ )
//		{
//			os << vv[ i ][ j ] << " ";
//		}
//		os << std::endl;	
//	}
//	return os;
//}

//  �������� ��� ���������� � ��������� ��������
template<typename T>std::ostream& operator<<(std::ostream& os, const std::vector<T>& vv)	// vector<vector<T>> -������ ���  ���������� �������
{
	for ( size_t i = 0; i < vv.size(); i++ )
	{
		os << vv[ i ] << " ";					//  ��� ���������� ������� ����� �������� ��������
												// ��� ��������� �������������� - ���������� ������ ��� �� ������ <<   � �������� �������� ��� ��� ����������� �������
		/*
		* // �� ���������� ������
		for ( size_t j = 0; j < vv[ i ].size(); j++ )
		{
			os << vv[ i ][ j ] << " ";
		}*/	
	}
	os << std::endl;
	return os;
}

// ������� ��������� ��������, ���� ��� � �������
template<typename T> void MyAdd(std::vector<T>& v, const T& data)	
{
	for ( size_t i = 0; i < v.size(); i++ )
	{
		if ( v[i] == data )				// ��������� ���� �� �������� � �������
		{
			return;
		}
	}
	v.insert(v.begin(), data);			// ���������  � ������
}


// ����������� ����� ���������
template<typename T> void PrintAll(const T &data)		
{
	typename T::const_iterator it;										// ���������� ��������
	//typename T::value_type type = typename T::value_type();					// ��� ����������
	std::cout << typeid( T ).name() << std::endl;						// ����� ���� ����������
	std::cout << typeid( typename T::value_type ).name() << std::endl;	//  �����  ����� ����������

	for ( it = data.begin(); it != data.end(); it++ )
	{
		std::cout << *it << " ";										// �������������
	}

	std::cout << std::endl;
}


// ������� ������ ������������� ������������������.
//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
template<typename T>void DeleteSameElements(std::vector<T>& v)		
{
	typename std::vector<T>::iterator it = v.begin();
	while ( it != v.end() )
	{
		typename std::vector<T>::iterator first = it;		// ���������� �� ������ �������
		typename std::vector<T>::iterator last = it + 1;	// ��������� � �� ��������� �������

		while ( last != v.end() )			//  
		{
			if ( *first == *last )		// ���������� ��������
			{
				last++;					// ���� ����� ����������� �������� ������
			}
			else
			{
				break;
			}
		}
		if ( last != it + 1 )	
		{
			it = v.erase(first, last);		// ������� ��������.
		}
		else
		{
			++it;						// �����������  ��������� ����� �������
		}
	}
};


//	 ������� �������� �� ������ ������� ���� ������ 
//��������: ���� - "qwerrrrty12222r3", ����� - "qwerty123"
template<typename T>void DeleteSameElementsWithErase(std::vector<T>& v1)
{

	typename std::vector<T>::iterator it1 = v1.begin();
	while ( it1 != (v1.end()) )
	{
		typename std::vector<T>::iterator first = it1;		// ���������� �� ������ �������
		typename std::vector<T>::iterator last = it1 + 1;	// ��������� � �� ��������� �������

		while ( last != v1.end())			//  �� ���������� �������� �� ����� vector
		{
			if ( *first == *last )			// ���������� ��������
			{
				it1 = v1.erase(first);		// ������� ��������.	
			}
			else
			{
				last++;					//  ����������� �������� ������
			}
		}

		it1++;						// ����������� �������� �����

	}
};


