#pragma once

#include"Shape.h"
#include <ostream>



class Node
{
private:
	Node* pPrev;
	Node* pNext;
	Shape* figure;

	friend class List;	// ��� ������� � ������ ������
/*
*	������������
*/
	Node();
	Node(Node* p, const Shape* f);
	~Node();

public:

/*
*	������
*/


/*
*	����������
*/
	friend std::ostream& operator<<(std::ostream& os, const List& list);

};

