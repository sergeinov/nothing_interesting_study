#include "Node.h"
#include<typeinfo>
#include"Rect.h"
#include"Circle.h"

/*
*	������������
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

	this->pPrev = p;			// ������� �����, ����� �������� ��������� ����  Node � ������
	this->pNext = p->pNext;

	// ������������ ������� �  Node*p
	p->pNext = this;
	this->pNext->pPrev = this;
	
}
Node::~Node()
{
	// TODO
	if ( pPrev )
	{
		// ���� ���� ����� �����, �� ������� ���������� ����� �� this ������.
		pPrev->pNext = this->pNext;
	}
	if ( pNext )
	{
		// ���� ���� ����� ������, �� ������� ���������� ���������� �� this 
		pNext->pPrev = this->pPrev;
	}
}

/*
*	������
*/


/*
*	����������
*/