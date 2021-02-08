// ���� - � ������� ������� ����������� ������ �������� ���� Circle 
// ����� ���������� ����������� ������

#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include<iostream>
#include"List.h"
#include<fstream>


#define stop _asm nop

static const char* arr[] = { "", "RED", "YELLOW", "GREEN", "BLACK" };

std::ostream& operator<<(std::ostream& os, Point& place)	// ����������� ����������
{
	os << "\n����������:\n" 
		<< "x = " << place.m_x 
		<< "\n" 
		<< "y = " << place.m_y;
	return os;
}; 

std::ostream& operator<<(std::ostream& os, Circle& object)	// ����������� ������
{
	os << "\n����: " << object.point 
		<< "\n����: " << arr[object.color]
		<< "\n������: " << object.m_radius << "\n";
	return os;
};

//std::ostream& operator<<(std::ostream& os, Node& node)		// ����� ������ �������� ������ Node
//{
//	os << node.m_Data;
//	
//	return os;
//}; 

std::ostream& operator<<(std::ostream& os, const List& list)	// ����������� ������
{
	if ( list.m_size != 0 )
	{
		os << "\n������: \n";
		Node* p = list.Head.pNext;
		//p->pNext;
		os << list.m_size << std::endl;
		for ( size_t i = 0; i < list.m_size; i++ )
		{
			//os << m_Data;
			os << p->m_Data;
			p = p->pNext;
		}

		return os;
	}
	else
	{
		os << "\n������ ����!!";
	}
		
	
};

std::ifstream& operator>>(std::ifstream& iff, List& list)		// ������� ������ �� �����
{
	char ar[ 20 ];
	iff >> ar;		// ������ "������"
	int temp;
	iff >> temp;	// �����
	for ( size_t i = 0; i < temp; i++ )
	{
		iff >> ar;		// "����"	
		iff >> ar;		// "����������"

		int n1, n2;	// ��� ������ ��������
		double n4;
		Circle::eColor n3 = {};

		iff.ignore(10, '=');
		iff >> n1;
		iff.ignore(10, '=');
		iff >> n2;
		iff.ignore(10, ':');
		iff >> n3;
		iff.ignore(10, ':');
		iff >> n4;
		
		list.AddToEnd(Circle(n4, n1, n2, n3));
	}
	return iff;
};

std::ifstream& operator>>(std::ifstream& iff2, Circle::eColor& color)		// ��� ���������� ������ ��� ���� ������������ eColor
{
	char ar[ 20 ];
	iff2 >> ar;
	for ( size_t i = 1; i < sizeof(arr) / sizeof(arr[ 0 ]); i++ )
	{
		if ( strcmp(ar, arr[ i ]) == 0 )
		{
			color = static_cast< Circle::eColor >( i );
			break;
		}
	}
	return iff2;
};
	

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");

	Circle c1(2, 3, 3, Circle::eColor::GREEN);
	Circle c2(4, 8, 8, Circle::eColor::RED);
	Circle c3(1, 4, 4, Circle::eColor::RED);
	List list1;

	list1.AddToHead(c1);	// �������� � ������ ������
	list1.AddToEnd(c2);		// �������� � ����� ������
	list1.AddToEnd(c3);

	std::cout << "������ c1" << std::endl;
	std::cout << c1;			// ����������� ��������� �������
	std::cout << "\n������ c2" << std::endl;
	std::cout << c2;			// ����������� ��������� �������
	std::cout << "\n������ list1:" << std::endl;
	std::cout << list1;			// ����������� ������

	List list2 = list1;		// ����������� �����������
	std::cout << "\n********���������� �����������:************" << std::endl;
	std::cout << "\n������ list2:" << std::endl;
	std::cout << list2;			// ����������� ������

	List list3;
	list3 = list2;				// ������������
	std::cout << "\n************������������:*****************" << std::endl;
	std::cout << "\n������ list2:" << std::endl;
	std::cout << list2;
	std::cout << "\n������ list3:" << std::endl;
	std::cout << list3;


	list3 = std::move(list2);	// �������� �����������  move
	std::cout << "\n*********�������� �����������  move:**************" << std::endl;
	std::cout << "\n������ list2:" << std::endl;
	std::cout << list2;
	std::cout << "\n������ list3:" << std::endl;
	std::cout << list3;

	// ����������
	std::cout << "\n*********����������:**************" << std::endl;
	list3.SortList(list3);
	std::cout << "�����:" << std::endl;
	std::cout << list3;

	// �������� � ����
	std::cout << "\n*********�������� � ����:****************" << std::endl;
	std::ofstream listOut("int.txt");	// ������� ����
	listOut << list3;					// �������� ������ � ����	// ������������ ������������� std::ostream& operator<<(std::ostream& os, const List& list)
	listOut.close();					// ������� ����

	// ������� �������:
	std::cout << "\n**********������� �������:************" << std::endl;
	std::cout << "\n�������� c1 - " << list3.RemoveOne(c1);		// ������� ������
	std::cout << list3;
	std::cout << "\n�������� c2 - " << list3.RemoveOne(c2);		// ������� ������
	std::cout << list3;

	std::cout << "\n********** ������� ��� �������:********" << std::endl;
	int deleteTemp = list3.RemoveAll(c1);		// ������� ��� �������
	std::cout << list3;			// ����������� ������
	std::cout << "\n� ������: " << deleteTemp << std::endl;


	// ������� �� �����
	std::cout << "\n******������� �� �����**********" << std::endl;
	std::ifstream fout("int.txt");
	List list4;
	fout >> list4;				// ��������� � ���������� � ������ list3
	fout.close();
	std::cout << "\n����� ������ �� �����:" << std::endl;
	std::cout << list4;			// ����������� ������

	stop

	return 0;
}