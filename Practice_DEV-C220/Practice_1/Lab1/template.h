#pragma once
#include<iostream>
#include<map>
#include<set>
#include<iterator>

// ����������� ��������� ����� range for
template<typename T> void PrintAnyCont(const T& data)
{
	for (const auto& i : data)
	{
		std::cout << i << " ";
	}
	std::cout  << std::endl;
}

// ���������� �������� ������ ������������ ������  string ��� ������� "���������"  ��������
inline std::string operator-(std::string s)
{
	for ( auto& i : s )
	{
		if ( islower(i) )
		{
			i = toupper(i);
		}
		else
		{
			i = tolower(i);
		}		
	}
	return s;
}

// ������� ��� "���������" ����� �������� ������������������
//����: {1, -2, 5}, �����: {-1, 2, -5})
//��������� �������� ���� std::string ����� ��������� "aBc1" -> "AbC1"
template<typename T> void NegateAll( T& data)
{
	for ( auto& i : data )
	{
		i = -i;
	}
}

// ������ ��������� ���  ���������� �� �������� ��� ����� �������������/������������� �����
template<typename T> void absSort(T& data)
{
	std::sort(std::begin(data), std::end(data), 
		[] (const auto& a, const auto& b)
		{
			//if ( abs(a) == abs(b) ) 
			//{ 
			//	return a < b; 
			//}
			return abs(a) < abs(b);
		});
}



//���������� ������, ������ ������� �������� �������� ������ ��������� ���� 
//������������������� ������ ����� � � ���������� ������� ����.
template<typename T, typename A> auto SumCont(const T& data, const A& data2)
{
	// decltype   ��������� ��� �������� � ������� ��������� �� ���� �����������
	std::vector<decltype( *( std::begin(data) ) + *( std::begin(data2) ) )> v
	(
		std::max(std::size(data), std::size(data2))			// �������������� ������  ���������� �������� �� ���� ���������� �����������
	);

	std::copy(std::begin(data), std::end(data), v.begin());		// �������� �� ������� ���������� � ������ v

	// �������������� �� ����� ������������������ � ������ ��������� ����� �� ���� ����������� v  �  data2
	std::transform(std::begin(data2), std::end(data2), v.begin(), v.begin(), [](const auto& x, const auto& y)
		{
			return x + y;		// ���������� 
		});

	return v;
}


//������� ������ "���������" �������� �������� ������������������ � ��� ������ ���������� 
template<typename T, typename C, typename A, typename P> void Separate(const T& data,  C& data2, A& data3,  P pred)
{
	//typedef decltype( *std::begin(data) ) value_type;		// ������ ���� ������ � �����������

	// ���� ���� ��������� �� ������������ ������
	if ( (typeid(T::value_type) == typeid(C::value_type)) && (typeid( T::value_type ) == typeid( A::value_type )) )
	{
		for ( const auto& i : data )
		{
			// ����� ������ �� ������ �� ������. ������ � � ������������������, �������� � �

			if ( pred( i ) )
			{
				//inserter(data2, data2.begin())  = i;
				data2.insert(data2.end(), i);
			}
			else
			{
				//inserter(data3, data3.begin()) = i;
				data3.insert(data3.end(), i);
			}
		}
	}

}


///  ������� 10

enum COLOR: unsigned char { GREEN, YELLOW };
enum DAYS: unsigned char {MONDAY, TUESDAY };

template <typename T> std::map<std::string, T> mp;

template <typename T> T stringToEnum(const std::string& str)
{
	return mp<T>.at(str);
}

template <typename T> const std::string& enumToString(T _enums)
{
	for ( auto& [key, value] : mp<T> )
	{
		if ( value == _enums )
		{
			return key;
		} 
	}
	throw "Not found";
}