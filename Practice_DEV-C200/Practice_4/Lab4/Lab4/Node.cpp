#include "Node.h"

// конструкторы
//List::Node::Node() : pNext(nullptr), pPrev(nullptr) {};

Node::Node() : pPrev(nullptr), pNext(nullptr) {};  // m_Data  конструктор по умолчанию
Node::Node(Node* p, const Circle* data) : m_Data(*data)
{
	//вставка создаваемого Node в список
	// формирование будущих соседей для this
	this->pPrev = p;			// заносим адрес, после которого вставляем свой  Node в список
	this->pNext = p->pNext;

	// формирование соседей у  Node*p
	p->pNext = this; 
	this->pNext->pPrev = this;

	//Node* n = p->pNext;
	//this->pPrev = p;			// заносим адрес, после которого вставляем свой  Node в список
	//this->pNext = n;

	//// формирование соседей у  Node*p
	//p->pNext = this;
	//n->pPrev = this;
};

Node::~Node()
{
	if (pPrev)
	{
		// если есть сосед слева, то соседом становится сосед от this справа.
		pPrev->pNext = this->pNext;
	}
	if (pNext)
	{
		// если есть сосед справа, то соседом становится предыдущий от this 
		pNext->pPrev = this->pPrev;
	}
};


// перегрузки


// методы