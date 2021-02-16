#pragma once

#include"Shape.h"
#include <ostream>



class Node
{
private:
	Node* pPrev;
	Node* pNext;
	Shape* figure;

	friend class List;	// для доступа к данным списка
/*
*	Конструкторы
*/
	Node();
	Node(Node* p, const Shape* f);
	~Node();

public:

/*
*	методы
*/


/*
*	перегрузки
*/
	friend std::ostream& operator<<(std::ostream& os, const List& list);

};

