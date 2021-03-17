// Iter_Alg.cpp : Defines the entry point for the console application.
//
//���������. ����������� ���������. ���������.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include<iterator>				// ��� ������ � �����������
#include"Point.h"
#include"template.h"
#include"Rect.h"

//using namespace std;	
#define	  stop __asm nop


// Point
std::ostream& operator<<(std::ostream& os, const Point& place)	// ����������� ����������
{
	os << "\n����������:\n"
		<< "x = " << place.m_x
		<< "\n"
		<< "y = " << place.m_y;
	return os;
};

//// ���������  �������� �������� ������ point
//template<typename T> void changeValue(T& data)
//{
//	data = data + 2;
//}

int main()
{
	setlocale(LC_ALL, "Rus");
	///////////////////////////////////////////////////////////////////

		//������� 1. ���������

		//����������� ���������. ����������� set<Point>. ���������, ���
		//����� ����������� � ������ Point. �������� ������, �������� �������� 
		//�������� ������� ��������� set, �� ����������� �� ��������
	std::set<Point> mySet = { Point(1,1),Point(3,3),Point(12,12),Point(6,6),Point(10,10) };		// ����� �������� Set

	std::vector<Point> myVec(mySet.size());	// ! ������ ���������� � ������ ������ / ������� ���������� ������ ��� �������� ���������
	//std::vector<Point> myVec(mySet.size());	// ����� ��� ������� ������
	//myVec.reserve(mySet.size());		//  � ���� �� �������� // ����� ������
	//myVec.resize(mySet.size());		//  ��
	std::vector<Point> myVec2;
	myVec2.reserve(mySet.size());	// ����� ������

	std::copy(mySet.rbegin(), mySet.rend(), myVec.begin());		// �������� �� set  � vector, � �������� �������
																//  ? �� �������� ��� set / map
	std::copy(mySet.rbegin(), mySet.rend(), std::back_inserter(myVec2));

	stop;

	//��������� ���������. � ������� ostream_iterator �������� ����������
	//vector � set �� ����������� ������� �� �����.

	std::ostream_iterator<Point> iter(std::cout, " ");				// ������� ���������� - �������� ������ cout
	std::copy(mySet.begin(), mySet.end(), iter);					// �� ������ ����������� operator<<   ��� Point
	std::cout << "\n\n************" << std::endl;
	std::copy(myVec.begin(), myVec.end(), iter);					// ����� ������� �� ������� � ������� copy


	stop;

	//��������� �������. � ������� ������������ ���������:
	//back_inserter()
	//front_inserter()
	//inserter()
	//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
	//����� �� ���������� ������� ����� ������������ � ������ �����������.

	Point myArr[] = { Point(13, 13), Point(14, 14) };

	std::copy(myArr, myArr + 2, std::back_inserter(myVec));				// ����� insertor - push_back  ���  Vector
	//std::copy(myArr, myArr + 2, std::front_inserter(mySet));				// ����� insertor - front_back  ���  mySet
	std::for_each(myVec.begin(), myVec.end(), printElement<Point>);			// ����������� � ����������

	std::cout << "\n\n************" << std::endl;
	stop;

	std::copy(myArr, myArr + 2, std::inserter(mySet, mySet.begin()));	// ����� �������������. ���������� ��� �����������
	std::for_each(mySet.begin(), mySet.end(), printElement<Point>);			// ����������� � ����������
	stop;

	///////////////////////////////////////////////////////////////////

		//������� 2. ���������� ��������� (������������ ���� <algorithm>). ���������.
		// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
		//(������, vector, list...)
		//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
		//������������ �������� ���������
		//��������� : ������� ���������� ������� ���������� ��� ������

	std::set<int> mySet2 = { 1,2,3,4,5 };								// ����� �������� Set

	printContainer(mySet2);											// ��������� ������� ������ �����������

	stop;

	//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
	//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
	//��� ������) � �������� ��������� � ������� ����������� ���������
	std::cout << "\n\n�� �������� \"����������\" �� ��������� ��������..........." << std::endl;
	PrintAll(myVec2);
	changeValue<Point> temp(6);		// �������� �������
	std::for_each(myVec2.begin(), myVec2.end(), temp);		// �������� ������ ������
	std::cout << "\n\n����� �������� \"����������\" �� ��������� ��������..........." << std::endl;
	PrintAll(myVec2);

	stop;

	//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
	//��� ��������� �� ������� Point � ��������� ���������.

	std::vector<Point> myVec3 = { Point(1,1),Point(3,3),Point(12,12),Point(6,6),Point(10,10) };
	std::set<Point> myVec4 = { Point(1,1),Point(3,3),Point(12,12),Point(6,6),Point(10,10) };
	// ? �� ��������� � set
	std::vector<Point>::iterator itVec = find(myVec3.begin(), myVec3.end(), Point(3, 3));	// ����� �������� Point � ����������
	std::set<Point>::iterator itVec2 = find(myVec4.begin(), myVec4.end(), Point(14, 14));	// ����� �������� Point � ����������
	stop;
	
	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
	////�� ��������� �������� ��������� ������������������ �� �����������.
	//��� ������ ���� ���������� � ������ Point?
	// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
	//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!

	std::cout << "\n\n�� ����������...." << std::endl;
	PrintAll(myVec3);
	
	std::sort(myVec3.begin(), myVec3.end());
	std::cout << "\n����� ����������....." << std::endl;
	PrintAll(myVec3);
	stop;

	std::list<Point> myList = { Point(20,20),Point(30,30),Point(120,120),Point(60,60),Point(100,100) };
	myList.sort();					// ���������� ������� ������ ��� ������
	PrintAll(myList);
	stop;

	//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
	//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
	//[-n, +m].

	std::list<Point>::iterator iterList = std::find_if(myList.begin(), myList.end(), Case(5, 5));
	if ( iterList == myList.end() )
	{
		std::cout << "\nNo!!";
	}
	stop;

	std::list<Point>::iterator iterList2 = std::find_if(myList.begin(), myList.end(), [ n = 120, m = 120 ](const Point& p){return ( p.GetX() < n && p.GetY() > m ); });
	std::list<Point>::iterator iterList3 = std::find_if(myList.begin(), myList.end(), [ n = 120, m = 120 ](const auto& p){return ( p.GetX() < n && p.GetY() > m ); });

	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
	//���������� �������������� �� �������� ������ �� ������ ���������.
	






	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()
		std::string str = "HEllO";
		std::transform(str.begin(), str.end(), str.begin(), SomeCase());
		stop;
		std::transform(str.begin(), str.end(), str.begin(), [](char ch) { return toupper(ch); });
		stop;
		std::transform(str.begin(), str.end(), str.begin(), SomeCasefoo);
		stop;

		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������
	
		std::list<std::string> listStr = { "APPLE", "123", "LEMON" };
		std::set<std::string> setStr;
		std::transform(listStr.begin(), listStr.end(), std::inserter(setStr, setStr.begin()),
			[](const std::string& s)
			{
				std::string temp = s;
				std::transform(temp.begin(), temp.end(), temp.begin(), tolower);
				return temp;
			});
		stop;



		stop
	}
	
	{//copy_if
		//��� ������ � ���������� ���� string. � ������� copy_if() ���������
		//������� ������� ������, ������������ � ����� "�" ��� "�", ����� � "�"...
		//��� ���� ������� ����� � �������� ������� ������ �� �����!
		std::vector<std::string> vectStr = { "Ferrary", "Aar", "Bert"," Tret","Bger" };
		std::cout << std::endl;
		for ( char c = 'A'; c <= 'Z'; c++ )
		{
			int count = 0;		// ������� ������������ ��� ��������� ������ � �������.
			std::copy_if(vectStr.begin(), vectStr.end(), std::ostream_iterator<std::string>(std::cout, " "),
				[c, &count](const std::string& s)
				{
					if ( c == toupper(s[ 0 ]) )		// ���� ������ ����� ������� ������ � ������  'A'  == "F"
					{
						count++;	
						return true;		// ���������� true  � ����� ���������� � ������� �����   ostream_iterator
					} return false;
					//return c == toupper(s[ 0 ]);
				});
			if ( count )	// ���� � count ���-�� ���� 
			{
				std::cout << std::endl;
			}
			
		}

		stop;

		//��� multimap, ���������� ����: "����� - ���������� ���� � ������"
		//pair<string, int>. � ������� copy_if ����������� ��� map-�: ������ -
		//� ������, ����������� ������ ���������� ����, 2-�� - ��������.
		std::multimap<std::string, int> month {
			{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
			{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
			{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		};



		stop

		//������������ multimap � map-�, ��������� ���������� ���� ����� ������
		//�������, ��������� �������� ������ ���������� �� ������.
		//��� ����� ������� ������������� ��� ������ ����?


	
		stop
	}

	return 0;
}

