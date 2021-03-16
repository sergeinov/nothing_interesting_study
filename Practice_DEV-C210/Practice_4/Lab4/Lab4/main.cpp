// ���������� STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include"template.h"
#include"Point.h"
#include"Case.h"

#include <iostream>

using namespace std;

#define stop __asm nop

// Point
std::ostream& operator<<(std::ostream& os, const Point& place)	// ����������� ����������
{
	os << "\n����������:\n"
		<< "x = " << place.m_x
		<< "\n"
		<< "y = " << place.m_y;
	return os;
};

// Point ���������� ���  Point*
std::ostream& operator<<(std::ostream& os, const Point* place)
{
	os << "\n����������:\n"
		<< "x = " << place->m_x
		<< "\n"
		<< "y = " << place->m_y;
	return os;
}

// ������� ������� ��� list  remove_if
bool NegPoint(const Point& object) 
{
	return ( object.m_x < 0 && object.m_y < 0 );
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
	//��������� ��������
	
	queue<int, list<int>> myQueue;
	myQueue.push(4);
	myQueue.push(6);
	PrintAdapter(myQueue);
	stop;


	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 
	vector<int> vInt = { 1, 2, 3, 4, 5 };
	stack<int, std::vector<int>> st(vector<int>(vInt.rbegin(), vInt.rend()));	// ������� ����� ������, �����������  vector<int>(vInt.rbegin(), vInt.rend())

	PrintAdapter(st);
	stop;

	stack<int, std::vector<int>> st2(vInt);
	PrintAdapter(st2);
	stop;



	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?
	
	{
		queue<Point, deque<Point>> q1;
		q1.push(Point(5, 5));
		q1.push(Point(1, 1));
		q1.push(Point(8, 8));
		Point& fr = q1.front();
		Point& bk = q1.back();
		PrintAdapter(q1);

		fr = Point(2, 2);
		bk = Point(4, 4);
		PrintAdapter(q1);

		while ( !q1.empty() )
		{
			q1.pop();
		};

		PrintAdapter(q1);
	}

	queue<Point*, deque<Point*>> q1;
	q1.push(new Point(5, 5));
	q1.push(new Point(1, 1));
	q1.push(new Point(8, 8));
	Point* fr = q1.front();
	Point* bk = q1.back();
	*fr = Point(9, 9);
	*q1.back() = Point(10, 10);

	//PrintAdapter(q1);

	while ( !q1.empty() )
	{
		delete q1.front();
		q1.pop();
	}


	stop;

	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?
	const char* ar[] = { "Bool", "is", "also", "important" };
	priority_queue<const char*, std::vector<const char*>, Case> pr(ar, (ar + sizeof(ar) / sizeof(ar[0])));

	PrintAdapter(pr);		// �� �����������	// ��� ��������� ������������ ������  � ������������ �����  "return x < y"
							// ������� �������� Case, ������� ���������� ������ ������� ������, ����� ������� �����������
	
	stop;




	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	//�) ���������� �������� ����� ��������...
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������
	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)

	set<Point> mySet = { Point(1,1),Point(3,3),Point(12,12),Point(6,6),Point(10,10) };

	PrintAll(mySet);
	stop;

	set<Point>::iterator it = mySet.begin();
	//*it = Point(22, 22);					// ! set ������������ ������ ��� ������

	set<int> mySet2 = { 1,2,3,4,5 };			// 1, 2, 3, 4, 5
	mySet2.insert(2);							// 1, 2, 3, 4, 5		// ����� ������������
	PrintAll(mySet2);

	set<int> mySet3 = { 5,4,3,2,1 };			// 1, 2, 3, 4, 5		// ���������������
	PrintAll(mySet3);

	int arr5[] = { 1, 2, 3, 6, 7 };
	mySet3.insert(arr5, arr5 + 5);				// 1, 2, 3, 4, 5, 6, 7		// ����� ������������
	PrintAll(mySet3);	

	//set<int, greater<int>> mySet4(arr5, arr5 + ( sizeof(arr5) / sizeof(arr5[ 0 ])));
	set<int, greater<int>> mySet4(arr5, arr5 + 5 );			// ���������� ������ ����������
	PrintAll(mySet4);

	stop;


	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset 
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	//�) ������������ ����������

	pair<const char*, int> pr1("�������", 20000);

	map<const char*, int , Case> mp;
	// 3 ������� ����������
	mp.insert(pr1);
	mp.insert(pair<const char*, int>("�������", 15000));
	mp[ "������" ] = 40000;

	PrintMap(mp);
	stop;
	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")
	const char* temp1 = "�������";
	const char* temp2 = "�������";
	//changeKeyName(mp, "�������","�������");		// �� �������� 
	changeKeyName(mp, temp1, temp2);

	stop;



	//�) ����������� ����� �������� ������ � ���������� ���� string.
	//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
	//��������� ������������� �� �������� ������ �
	//���������� ���������� ������ ������ � �������
	// ������:  map -> ����/�������� ->  "Green"  2

	vector<string> vString = { "Green", "Yellow", "Blue", "Pink", "Black","Green" };
	map<string, int> mp2;
	vector<string>::iterator iter1 = vString.begin(), iter2 = vString.end();		// ���������
	while ( iter1 != iter2 )
	{
		mp2[ *iter1 ]++;			// ���� ��� � Map �������, ������� "Green" - �������� 0....."Yellow" = 0 ....."Blue" 0
									//  � ���������� ����� �� ��������, ����� �� ������ ++
									//  � Pair ����������  -  "Green"  1
									// ����� ���������� ������ ������� ������ Pair ����������  -  "Green" = 2
		++iter1;
	}
	PrintAll(mp2);
	stop;


	//�) 
	//����� ������:
	const char* words[] = {"Abba", "Alfa", "Beta", "Beauty"};
	//�������� map, � ������� ������ ����� ����� ��������������� ������������ 
	//��������������� ������������� ����, ������������ � ���� �����.
	//���������: �� ����� ������� ����� ����� � ��� �� ������
	
	//'A' -  "Abba" "Alfa"
	//'B' -  "Beauty" "Beta"  ...
		//...
	map<char, set<string>> mp3;
	for ( size_t i = 0; i < sizeof(words) / sizeof(words[0]); i++ )
	{
		mp3[ words[ i ][ 0 ] ].insert(words[ i ]);	//T& operator[]( const Key& key );
													// ���������� ������ �� ��������, ������� ������������ � ������, ������������� �����, 
													// �������� �������, ���� ����� ���� ��� �� ����������.
													// � insert  ��������� �������� � .second
	}
	
	PrintAll(mp3);


	//�)
	//�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
	//��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
	//������� ����� �������������
	//���� ������ ���� ������ ���� ����������� �� ������
	//
	//������ 
	const char* words2[] = { "Ivanov", "Petrov", "Ivanov", "Petrov", "Grechkin", "Holol", "Abdulov", "Bregin" };
	map<size_t, multiset<string>> mp4;

	for ( size_t i = 1; i < (sizeof(words2) / sizeof(words2[ 0 ]) + 1); i++ )
	{
		mp3[ i ].insert(words2[ i ]);				//T& operator[]( const Key& key );
													// ���������� ������ �� ��������, ������� ������������ � ������, ������������� �����, 
													// �������� �������, ���� ����� ���� ��� �� ����������.
													// � insert  ��������� �������� � .second
	}
	PrintAll(mp4);
	stop;

	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����
	//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
	//		���������� ����� ������������ ������ lower_bound() � upper_bound()

	std::pair <std::string, std::string> p1 = make_pair("attitude", "���������");
	std::pair <std::string, std::string> p2 = make_pair("attitude", "�������");
	std::pair <std::string, std::string> p3 = make_pair("order", "�������");
	std::pair <std::string, std::string> p4 = make_pair("order", "�����");
	std::pair <std::string, std::string> p5 = make_pair("order", "������");
	std::pair <std::string, std::string> p6 = make_pair("denote", "��������");
	std::pair <std::string, std::string> p7 = make_pair("denote", "���������");

	std::multimap<std::string, std::string> mMap;
	mMap.insert(p1);
	mMap.insert(p2);
	mMap.insert(p3);
	mMap.insert(p4);
	mMap.insert(p5);
	mMap.insert(p6);
	mMap.insert(p7);

	PrintAll(mMap);
	string word = "order";
	myTranslater(mMap, word);
   

  stop

	return 0;
}

