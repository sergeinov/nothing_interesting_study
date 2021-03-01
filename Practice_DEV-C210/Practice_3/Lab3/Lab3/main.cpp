//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������

#include <iostream>
#include<list>
#include <vector>
#include"Point.h"
#include"templates.h"
#include"MyString.h"
#include <deque>


#pragma warning(disable: 4786)


using namespace std;	

#define	  stop __asm nop

// MyString
std::ostream& operator<<(std::ostream& os, const MyString& RightObject)
{
	os << RightObject.m_pName;

	return os;
};

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
	setlocale(LC_ALL, "Russian");
	// ��������� ����������� ���������� vector 

//////////////////////////////////////////////////////////////////////
	//�������� ��������. 

	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 
	
	vector<int> vInt;
	size_t n = vInt.size();
	
	stop
	//���������������� ��������� ��������, ��������� - ��� �� ���������
	//���� ���� ��������������, - ���������
	vInt.push_back(5);
	vInt.front() = 1;				// 1 // front  ���������� ������ �� ������ ������� // ���������� *c.begin()
	stop

	//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	//size(), capacity(), max_size() � �������� �������� ���������. 
	for ( size_t i = 1; i < 5; i++ )
	{
		vInt.push_back(i * 5);
		PrintVector(vInt);
		std::cout << std::endl;
	}
	stop
	//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
	//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
	//������� ��� "���������" � �������� ��������� �� �������.



	//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	//��������� ��������� � ������� ���������� ���� �������. ��� �����
	//������������������� �������� �������?
	vector<double> doubleVector(10);			//  0  0  0  0  0
	PrintVector(doubleVector);
	stop;

	//������ �������� ���� MyString � ��������� �������� - 5 ���������
	//� �������������� ������� �������� ������� "A"
	//C ������� ������� at() � ����� � ������� ���������
	//�������������� []  �������� �������� �����-���� ���������.
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. 
	vector<MyString> str(5, "A");
	try
	{
		str.at(3) = "C";
		str.at(5) = "B";	// Exception thrown at 0x76A746D2 in Lab3.exe: Microsoft C++ exception: std::out_of_range at memory location 0x0137F500.
	}
	catch ( std::out_of_range& ) { };
	
	str[ 4 ] = "D";
	PrintVector(str);
	stop;

	//str[ 5 ] = "F";			// ���������� �������� �  out_of_range at memory
	

	stop
	//������ ������������ - vDouble3, ������� �������� ������ ���������
	// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
	//����� ������� � �������������������!

	double dMas [] = { 3, 4, 5, 10, 11, 15, 16 };
	//PrintVector(dMas);
	vector<double>vDouble3(dMas, (dMas + sizeof(dMas) / sizeof(double)));
	PrintVector(vDouble3);
	stop;

	//������ ������������ - vDouble4, ������� �������� ������ ���������
	// [�� 2, �� 5) ������� vDouble3. 

	vector<double>vDouble4(vDouble3.begin() + 2, vDouble3.begin() + 5);
	PrintVector(vDouble4);
	stop;

	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?
	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).
	vector<Point> point1(3);			//  ����� ������������ �� ���������

	vector<Point> point2(5, Point(1,1));	// ����� ������������ � ��������������
	PrintVector(point2);					// const
	/*for ( size_t i = 0; i < point2.size(); i++)
	{
		std::cout << point2[ i ] << " ";
	}*/

	stop;

	//������ ���������� �� Point - vpPoint � ��������� �������� 5
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	{
		vector<Point*>vpPoint(5);
		for ( size_t i = 0; i < vpPoint.size(); i++ )
		{
			vpPoint[ i ] = new Point(i, i);
		}
	//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
		//�) ������������� ����� ��������� �������
		//�) ��� ���������� operator<< ��� Point*

		std::cout << "\n\nVector ���������� vpPoint" << std::endl;
		// ��������
		PrintVector(vpPoint);
		stop;
		std::cout << "�������� Point" << std::endl;

		// ������� ����������� ��������� Point
		for ( size_t i = 0; i < vpPoint.size(); i++ )
		{
			delete vpPoint[ i ];
		}
		stop;
	}//����� �������������� �������� ����� ����������� ��� ������ �������?		// ����� ������� ��������� �������

	stop
		///////////////////////////////////////////////////////////////////////
		//�������������� ������.
		//���������, ������ �� ����� ����������� ���� ��������?

		{
		size_t n = 10;
		vector<int> v(n);
		v.resize(n/2);
		if ( v.capacity() == n ); // !true  // �� ������ �����
		stop
		}
		

		
		{
		int n = 10;
		size_t m = 10;
		vector<int> v(n);	// 10 ���������
		v.reserve(m);		//  ��������������� ������
		if ( v.capacity() == m ); // !true
		stop
		}
		

		
		{
		vector<int> v(3,5);
		v.resize(4,10); //��������?	// 5  5  5  10  - Capacity 4	Size - 4
		v.resize(5); //��������?		// 5  5  5  10  0 - Capacity 6  Size - 5
		stop
		}
		

	//�������� ��� "������" ������� � ����������
	//������ (�� ������ � ���� �� ����) ����. 
	//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
	//��� ���������� � ������� push_back.
	//������ ������ ������ ��������� ���������� ����������� push_back.
	//
	//�������� ������, ������� �������� � �������� ���������

		vector<int> vInt1;
		vInt1.reserve(5);		//  ��������������� ������
		vInt1.push_back(1);
		vInt1.push_back(2);
		vInt1.push_back(3);
		vInt1.push_back(4);
		vInt1.push_back(5);
		PrintVector(vInt1);		// 1  2  3  4  5 - Capacity 5  Size - 5

		vector<int> vInt2;
		vInt2.push_back(10);
		vInt2.push_back(20);
		vInt2.push_back(30);
		vInt2.push_back(40);
		vInt2.push_back(50);
		PrintVector(vInt2);		// 0  0  0  0  0 - Capacity 6  Size - 5
	
		stop;


	//!!! shrink_to_fit - ���������� ������� �������.
	//��� ������ ������� �� ����������� ������� ��������� ��������� �������
	//�� size.

		// � ������� ������ ���� ��������  void swap(vector<Type, Allocator>& x);
		// ��� ������ ��� �� ������������ ������ ���������� ����������
		// !vInt2.swap(vector<int>(vInt2));

		// ����������� ��� ����� Capacity
		vInt2.reserve(10);					// ����������� ������
		PrintVector(vInt2);
		vInt2.shrink_to_fit();				// ������� capacity
		PrintVector(vInt2);
		stop;
	

	//�������� "����������� �������" - ������� ��������
	//����� ���������� ������ int ar[] = {11,2,4,3,5};
	//�������� ������ �������� ��������� �������:
	//������ vv[0] - �������� 11 ��������� �� ��������� 11
	//vv[1] - �������� 2,2,
	//vv[2] - �������� 4,4,4,4
	//vv[3] - 3,3,3
	// vv[5] - 5,5,5,5,5

	//������������ ���������� ������ ����������� ������� �� �������
		int ar[] = { 11,2,4,3,5 };
		vector<vector<int>>vv;
		vv.resize(5);
		for ( size_t i = 0; i < (sizeof(ar) / sizeof(ar[0])); i++ )
		{
			vv[ i ].assign(ar[ i ], ar[ i ]);		// void assign(size_type count, const Type& value);	
													// ���������� ����� �������� -11, �������� ��������, ������������ � ������ - 11
													// ���������� ����� �������� - 2, �������� ��������, ������������ � ������ - 2
													// ���������� ����� �������� - 4, �������� ��������, ������������ � ������ - 4
													// ���������� ����� �������� - 3, �������� ��������, ������������ � ������ - 3
													// ���������� ����� �������� - 5, �������� ��������, ������������ � ������ - 5
		}
		// �����������  // ������ ������� operator<<  ��� ���������� vector
		std::cout << vv << std::endl;
		stop;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//������� �������� ������������������ insert().
		//� ������ vChar2 �������� � ������ ������� ������ ������ ���
		//�������, ��� � ������� ������ ��� ���.
		const char* ch= "N";
		bool flag = true;

		vector<char>vChar2 = {'a', 'b', 'c', 'v'};
		MyAdd(vChar2, 'r');
		PrintVector(vChar2);
		stop;
		vector<string> vString = { "Hello", "World", "!" };
		MyAdd(vString, string("!"));
		PrintVector(vString);
		stop;
		
	
	//�������� ����� ������ ��������� ������� vChar2 ����� 'W'	
//		const char* ch2 = "W";
//		itb = vChar2.begin();
//		//vChar2.reserve(20);
//
//		for ( size_t i = 0; i < size + 1; i++ )
//		{
//			itb = vChar2.insert(itb, ch2);		// ���� �� ��������� ����� �� ����� �������� ���������
//			itb += 2;
//		}
//		PrintVector(vChar2);
//
//		stop;
//
/////////////////////////////////////////////////////////////////////
//	//�������� �������, ������� ������ ������� ������ ������������� ������������������.
//	//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
//		vChar2.push_back("A");
//		vChar2.push_back("A");
//		vChar2.push_back("A");
	vector<char>vChar3 = { 'a','b','b','c','v','v','v','v','x','b' };
	DeleteSameElements(vChar3);
	PrintVector(vChar3);
	stop;

		///////////////////////////////////////////////////////////////////

	//�������� �������� ������������������ erase()
	//�������� ������� �������� �� ������ ������� ���� ������ 
	//��������: ���� - "qwerrrrty12222r3", ����� - "qwerty123"
	vector<char>vChar4 = { 'a','b','b','c','v','v','v','v','x','b'};
	DeleteSameElementsWithErase(vChar4);	// TODO
	PrintVector(vChar4);
	stop;


	///////////////////////////////////////////////////////////////////
	//�������� ����� ������ ����� �������, ����� ��� �������� �����
	//������� ��������� ������ �� ��������� ����� ��������, �� �����������
	//���� �� � �������� �������

	vector<int> vInt4(vInt1.rbegin(), vInt1.rend());
	/*for ( vector<int>::reverse_iterator itb = vInt1.rbegin(); itb != vInt1.rend(); ++itb )
	{
		vInt4.push_back(*itb);
	}*/
	PrintVector(vInt4);
	stop;


	///////////////////////////////////////////////////////////////////

		// ! ������� 1. ������. ��������, ����������� ��� �������.
		//�������� ������ ������ �� ��������� Point - ptList1 � ���������
		//��� ���������� � ������� ������� push_back(),
		//push_front, insert()

		list<Point> ptList1;			
		/*list <int> :: iterator itb = list1.begin();
		advance(itb, 5);*/
		ptList1.push_back(Point(1,1));
		ptList1.push_back(Point(2, 2));
		ptList1.push_front(Point(3, 3));
		ptList1.push_front(Point(4, 4));
		ptList1.insert(ptList1.end(), ( Point(5, 5) ));	 //  ��������� ������� ��� ���������� ��������� ��� �������� ��������� � ��������� ��������� � ������.
		

	//�������� ������ �������, ������� ����� �������� ��������
	//������ ���������� �� ������. ��������� ������ ������� �� �����������
	//vector � list. ��������� - �������� �� ������� ��� ����������.
		std::cout << "\nptList1" << std::endl;
		PrintAll(ptList1);			// ��� ������ ���������������� ����� ����� ������������� operator<<
		stop;

	//�������� ����� �� ������� "�����������" - reverse()

		ptList1.reverse();

		std::cout << "\nreverse  ptList1" << std::endl;
		PrintAll(ptList1);
		stop;

	//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
	//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
	//�� � �������� ������� 

		list<Point> ptList2(ptList1.rbegin(), ptList1.rend());
		//list<Point>::iterator it12 = ptList1.begin();
		//ptList2.splice(ptList2.end(), ptList1, it12, ptList1.end());

		std::cout << "\nptList2 ����� ������� ��������� ���� Point" << std::endl;
		PrintAll(ptList2);

		stop;
	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������
		ptList1.sort();			//  ��������� �� ����������� (operator<)  // ��� ���������������� ������� ����� ����������� operator<

		std::cout << "\nsort  ptList1" << std::endl;
		PrintAll(ptList1);
		stop;

		ptList2.sort();

		std::cout << "\nsort  ptList2" << std::endl;
		PrintAll(ptList2);
		stop;


	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� � ������ �������.

		ptList1.merge(ptList2);		// ��������� ������������
		std::cout << "merge  ptList1" << std::endl;
		PrintAll(ptList1);
		// � ptList2  �����
	
		stop;

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ������ ���� ����������� � ������ Point?

	ptList1.remove(Point(1,1));							// ��� Point ����������� operator=
	std::cout << "remove  Point(1,1) ptList1" << std::endl;
	PrintAll(ptList1);
	stop;

	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if(). 

	ptList1.push_front(Point(-4, -4));
	PrintAll(ptList1);
	ptList1.remove_if(NegPoint);
	std::cout << "remove_if -  negative value ptList1" << std::endl;
	PrintAll(ptList1);
	stop;

	//���������� �� ������ ������ ������������� ������ - unique(). 

	ptList1.unique();
	std::cout << "unique -  value ptList1" << std::endl;
	PrintAll(ptList1);

	stop;

///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������
	vector<Point> point5(5, Point(3, 3));			// ����� ������������ � ��������������
	PrintVector(point5);					


	//deque<Point, vector<Point>> pDeque;
	deque<Point> pDeque;
	pDeque.assign(point5.begin(), point5.end());
	std::cout << "\ndeque ->" << std::endl;
	PrintAll(pDeque);

	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'

	deque<MyString> pDeque;
	pDeque.push_front("I");
	pDeque.push_back("am");
	pDeque.push_back("Aliss");
	pDeque.insert(pDeque.end(), "Grett");

	std::cout << "\ndeque ->" << std::endl;
	PrintAll(pDeque);

	std::cout << "\ndeque -> ��������" << std::endl;
	DeleteElemForDeque(pDeque);
	PrintAll(pDeque);

	return 0;
}

