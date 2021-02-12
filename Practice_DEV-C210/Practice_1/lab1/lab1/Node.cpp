#include "Node.h"
#include<typeinfo>
#include"Rect.h"
#include"Circle.h"

/*
*	Конструкторы
*/
Node::Node() : pPrev(nullptr), pNext(nullptr), figure(nullptr) { };
Node::Node(Node* p, const Shape* f)
{
	//if ( typeid(*f) == typeid(Rect) )
	//{
	//	this->figure = new Rect(*static_cast<const Rect*>(f));
	//	//this->figure = new Rect(static_cast<const Rect&>(*f));		

	//}
	//else
	//{
	//	this->figure = new Circle(*static_cast< const Circle*>( f ));
	//	//this->figure = new Circle(static_cast< const Circle&>( *f ));
	//}
	this->figure = f->Clone();

	this->pPrev = p;			// заносим адрес, после которого вставляем свой  Node в список
	this->pNext = p->pNext;

	// формирование соседей у  Node*p
	p->pNext = this;
	this->pNext->pPrev = this;
	
}
Node::~Node()
{
	// TODO
	if ( pPrev )
	{
		// если есть сосед слева, то соседом становится сосед от this справа.
		pPrev->pNext = this->pNext;
	}
	if ( pNext )
	{
		// если есть сосед справа, то соседом становится предыдущий от this 
		pNext->pPrev = this->pPrev;
	}
}

/*
*	методы
*/


/*
*	перегрузки
*/