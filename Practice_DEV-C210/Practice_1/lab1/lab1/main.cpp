// �������� RTTI
//

#include <iostream>
//#include<typeinfo>
#include<crtdbg.h> // ��� ������ ������ 
#include"List.h"
#include"Circle.h"
#include"Rect.h"

#define stop __asm nop

std::ostream& operator<<(std::ostream& os, const List& list)	// ! Done     // ����������� ������ 
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
			//os << p->m_Data;
			//p = p->pNext;
		}

		return os;
	}
	else
	{
		os << "\n������ ����!!";
	}

	return os;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	// ����� �������� ��������� � ������ ��������� � �� ���� ����� ����������� ��� ��������� ������������� 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	List l;
	l.AddToHead(Rect(1, 2, 3, 4, Shape::BLUE));
	l.AddToHead(Circle(2, 2, 4, Shape::GREEN));

	l.RemoveOne(Circle(1, 1, 4, Shape::GREEN));

	//C* pC = &c;
	//B* pB = &c;
	//A* pA = &c;
	stop
	return 0;
}

