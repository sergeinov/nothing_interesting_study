// ���� - � ������� ������� ����������� ������ �������� ���� Circle 
// ����� ���������� ����������� ������

#include <tchar.h>
#include<iostream>
#include"List.h"


#define stop _asm nop

std::ostream& operator<<(std::ostream& os, Point& place)	// ����������� ����������
{
	os << "\n����������:\n" << "x = " << place.m_x << ", " << "y = " << place.m_y;
	return os;
}; 

std::ostream& operator<<(std::ostream& os, Circle& object)	// ����������� ������
{
	os << "\n����: " << object.point << "\n����: " << object.color << "\n������: " << object.m_radius << "\n";
	return os;
};

std::ostream& operator<<(std::ostream& os, Node& node)		// ����� ������ �������� ������ Node
{
	os << node.m_Data;
	
	return os;
}; 

std::ostream& operator<<(std::ostream& os, List& list)	// ����������� ������
{
		Node* p = &list.Head;	


		os << "\n������: \n";
		
		for (size_t i = 0; i < list.m_size; i++)
		{
			if (p)
			{
				
			}
			
		}
		
		return os;
	
};
	

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");

	Circle c1(2, 3, 3, Circle::eColor::GREEN);
	Circle c2(4, 6, 6, Circle::eColor::RED);
	List list;

	list.AddToHead(c1);
	list.AddToEnd(c2);

	std::cout << c1;

	std::cout << list;

	list.RemoveOne(c1);
	std::cout << c1;

	list.RemoveAll(c2);
	std::cout << list;

	return 0;
}