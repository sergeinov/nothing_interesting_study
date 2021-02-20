// �������� RTTI
//

#include <iostream>
//#include<typeinfo>
#include<crtdbg.h> // ��� ������ ������ 
#include<fstream>
#include"List.h"
#include"Circle.h"
#include"Rect.h"

#define stop __asm nop


std::ostream& operator<<(std::ostream& os, const List& list)    // ����������� ������ 
{
	if ( list.m_size != 0 )
	{
		os << "\n������: \n";
		Node* p = list.Head.pNext;
		//p->pNext;
		os << list.m_size << std::endl;
		for ( size_t i = 0; i < list.m_size; i++ )
		{
			/*os <<*/ p->figure->Print(os) << std::endl;
			p = p->pNext;
		}

		return os;
	}
	else
	{
		os << "\n������ ����!!";
	}

	return os;
}

std::ifstream& operator>>(std::ifstream& iff, List& list)		// ������ ������ �� �����
{
	char ar[ 20 ];					// ������ ��� ����������� ������
	iff >> ar;						// ������ "������"
	int temp;
	iff >> temp;					// ����� ���������� � ������
	for ( size_t i = 0; i < temp; i++ )
	{
		int n1, n2, n3, n4;			// ��� ������  int ��������
		double n5;					// ��� ������  double ��������
		Shape::eColor n6 = {};		// ���������� ��� ���������� �����

		iff >> ar;					// ��������� �������� �������
		if ( strcmp(ar, "Rect:") == 0 )
		{
			iff.ignore(10, ':');
			iff >> n1;
			iff.ignore(10, ':');
			iff >> n2;
			iff.ignore(10, ':');
			iff >> n3;				
			iff.ignore(10, ':');
			iff >> n4;
			iff.ignore(10, ':');
			iff.ignore(10, '\n');				// ? ��� ���������� ������ // ����������  Area   - ���������� 
			iff >> n6;				// eColor
			list.AddToEnd(Rect(n1, n1, n3, n4, n6));	// ��������� ��������� ������ � ������
		}
		else if ( strcmp(ar, "Circle:") == 0 )		// ? ���������� ��������� ���  �������  ����� 3-��
		{
			iff.ignore(10, ':');
			iff >> n1;
			iff.ignore(10, ':');
			iff >> n2;
			iff.ignore(10, ':');
			iff >> n5;					// ������
			iff >> n4;				// ? ��� ���������� ������ // ����������  Area   - ���������� 
			iff >> n6;					// eColor	// ������������ ������������� �������� <<
			list.AddToEnd(Circle(n1, n2, n5, n6));
		}
	}

	return iff;
}

std::ifstream& operator>>(std::ifstream& iff2, Shape::eColor& color)		// ��� ���������� ������ ��� ���� ������������ eColor
{
	char ar[ 20 ];
	iff2 >> ar;
	for ( size_t i = 1; i < sizeof(arr) / sizeof(arr[ 0 ]); i++ )
	{
		if ( strcmp(ar, arr[ i ]) == 0 )
		{
			color = static_cast< Shape::eColor >( i );
			break;
		}
	}
	return iff2;
};



int main()
{
	setlocale(LC_ALL, "Russian");
	// ����� �������� ��������� � ������ ��������� � �� ���� ����� ����������� ��� ��������� ������������� 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	List l;
	l.AddToHead(Rect(1, 1, 4, 4, Shape::BLUE));
	l.AddToHead(Circle(2, 2, 4, Shape::GREEN));
	l.AddToEnd(Circle(4, 4, 6, Shape::YELLOW));
	l.AddToEnd(Rect(6, 6, 8, 8, Shape::YELLOW));
	l.AddToEnd(Circle(8, 8, 10, Shape::YELLOW));
	//l.ClearList();


	//List l6;				// ��� �����   List& List::operator=(const List& otherList)	//���������� ��������� ������������ = ��� �������
	//l.AddToEnd(Circle(8, 8, 10, Shape::YELLOW));
	//l.AddToHead(Rect(1, 1, 4, 4, Shape::BLUE));
	//l.AddToEnd(Rect(6, 6, 8, 8, Shape::YELLOW));
	//l.AddToHead(Circle(2, 2, 4, Shape::GREEN));
	//l.AddToEnd(Circle(4, 4, 6, Shape::YELLOW));


	List l2 = l;		// ����������� �����������
	std::cout << "\n********���������� �����������:************" << std::endl;
	std::cout << "\n������ l:" << std::endl;
	std::cout << "\n������ l2:" << std::endl;
	std::cout << l2;			// ����������� ������

	List l3;
	l3 = l2;					// �������� ������������/ �����������
	//l6 = l2;					// ��� �������� ������������  virtual Shape& operator=()
	std::cout << "\n************������������:*****************" << std::endl;
	std::cout << "\n������ l2:" << std::endl;
	std::cout << l2;
	std::cout << "\n������ l3:" << std::endl;
	std::cout << l3;

	std::cout << "\n*********���������� �� �����:**************" << std::endl;
	l.Sort(Color);
	std::cout << "����� ���������������� ������:" << std::endl;
	std::cout << l;
	
	std::cout << "\n*********���������� �� �������:**************" << std::endl;
	l.Sort(Area);
	std::cout << "����� ���������������� ������:" << std::endl;
	std::cout << l;

	stop

	std::cout << "\n*********�������� � ����:****************" << std::endl;
	std::cout << "\n ..........Loading...........\n" << std::endl;
	std::ofstream listOut("in.txt");	// ������� ����
	listOut << l;						// �������� ������ � ����	// ������������ ������������� std::ostream& operator<<(std::ostream& os, const List& list)
	listOut.close();

	stop

	std::cout << "\n******������� �� �����**********" << std::endl;	
	std::ifstream fout("in.txt");
	List list1;
	fout >> list1;				// ��������� � ���������� � ������ list1
	fout.close();
	std::cout << "\n����� ������ list1 �� �����:" << std::endl;
	std::cout << list1;			// ����������� ������

	stop

	std::cout << "\n**********�������� ������ list1:************" << std::endl;
	list1.ClearList();
	std::cout << "\n����� ������ list1:" << std::endl;
	std::cout << list1 << std::endl;			// ����������� ������

	stop

	std::cout << "\n**********������� �������:************" << std::endl;
	l.RemoveOne(Circle(4, 4, 6, Shape::YELLOW));
	std::cout << l;

	stop
	return 0;
}

