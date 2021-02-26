//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������

#include <iostream>
#include<list>
#include <vector>
#include"Point.h"
#include"templates.h"
#include"MyString.h"


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
	//������������ ���������� ������ ����������� ������� �� �������
		int ar[] = { 11,2,4,3,5 };
		vector<vector<int>>vv;
		vv.resize(11);
		for ( size_t i = 0; i < 3; i++ )
		{
			vv[ i ].assign(ar[ i ], ar[ i ]);
		}
		
		//std::cout << vv << std::endl;
		stop;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//������� �������� ������������������ insert().
		//� ������ vChar2 �������� � ������ ������� ������ ������ ���
		//�������, ��� � ������� ������ ��� ���.
		const char* ch= "N";
		bool flag = true;

		
		vector<const char*>vChar2;
		vChar2.push_back("A");
		vChar2.push_back("B");
		vChar2.push_back("D");
		vChar2.push_back("C");
		
		int size = vChar2.size();
		vector<const char*>::iterator itb = vChar2.begin();
		//vector<const char*>::iterator ite = vChar2.end();

		// ��������� ������
		for ( size_t i = 0; i < size; i++ )
		{
			// �������, ��� ���� � ������� ������
			if ( vChar2[i] == ch )
			{
				flag = false;
				std::cout << "���� ����� ������ - " << ch << std::endl;
				break;
			}
		}
		if ( flag )
		{
			vChar2.insert(itb, ch);
		}
		// �����������
		PrintVector(vChar2);
	
	//�������� ����� ������ ��������� ������� vChar2 ����� 'W'	
		const char* ch2 = "W";
		itb = vChar2.begin();
		//vChar2.reserve(20);

		for ( size_t i = 0; i < size + 1; i++ )
		{
			itb = vChar2.insert(itb, ch2);		// ���� �� ��������� ����� �� ����� �������� ���������
			itb += 2;
		}
		PrintVector(vChar2);

		stop;

///////////////////////////////////////////////////////////////////
	//�������� �������, ������� ������ ������� ������ ������������� ������������������.
	//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
		vChar2.push_back("A");
		vChar2.push_back("A");
		vChar2.push_back("A");
	// ! �� ����
	//DeleteSameElements(vChar2);
	PrintVector(vChar2);
	stop;

		///////////////////////////////////////////////////////////////////

	//�������� �������� ������������������ erase()
	//�������� ������� �������� �� ������ ������� ���� ������ 

	//DeleteSameElementsWithErase(vChar2);
	PrintVector(vChar2);
	stop


		///////////////////////////////////////////////////////////////////
			//�������� ����� ������ ����� �������, ����� ��� �������� �����
			//������� ��������� ������ �� ��������� ����� ��������, �� �����������
			//���� �� � �������� �������
		vector<int> vInt4;
		for ( vector<int>::reverse_iterator itb = vInt1.rbegin(); itb != vInt1.rend(); ++itb )
		{
			vInt4.push_back(*itb);
		}
		PrintVector(vInt4);
		stop;



	///////////////////////////////////////////////////////////////////

		// ! ������� 1. ������. ��������, ����������� ��� �������.
		//�������� ������ ������ �� ��������� Point - ptList1 � ���������
		//��� ���������� � ������� ������� push_back(),
		//push_front, insert()

		list<int> list1;
		//list <int> :: iterator itb = list1.begin();
		//advance(itb, 5);
		list1.push_back(1);
		list1.push_back(2);
		list1.push_front(4);
		list1.push_front(3);
		list1.insert(list1.end(), 10);


	//�������� ������ �������, ������� ����� �������� ��������
	//������ ���������� �� ������. ��������� ������ ������� �� �����������
	//vector � list. ��������� - �������� �� ������� ��� ����������.
		PrintAll(list1);
		stop;

	//�������� ����� �� ������� "�����������" - reverse()
		list1.reverse();
		PrintAll(list1);
		stop;
	//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
	//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
	//�� � �������� ������� 



	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������


	


	stop

	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� � ������ �������.

	
	stop

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ������ ���� ����������� � ������ Point?
	

	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if(). 


	//���������� �� ������ ������ ������������� ������ - unique(). 

	stop

///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������



	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'




	return 0;
}