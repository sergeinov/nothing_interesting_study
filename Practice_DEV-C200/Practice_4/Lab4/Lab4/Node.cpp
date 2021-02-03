#include "Node.h"

// ������������
//List::Node::Node() : pNext(nullptr), pPrev(nullptr) {};

Node::Node() : pPrev(nullptr), pNext(nullptr) {};  // m_Data  ����������� �� ���������
Node::Node(Node* p, const Circle* data) : m_Data(*data)
{
	//������� ������������ Node � ������
	// ������������ ������� ������� ��� this
	this->pPrev = p;			// ������� �����, ����� �������� ��������� ����  Node � ������
	this->pNext = p->pNext;

	// ������������ ������� �  Node*p
	p->pNext = this; 
	this->pNext->pPrev = this;

	//Node* n = p->pNext;
	//this->pPrev = p;			// ������� �����, ����� �������� ��������� ����  Node � ������
	//this->pNext = n;

	//// ������������ ������� �  Node*p
	//p->pNext = this;
	//n->pPrev = this;
};

Node::~Node()
{
	if (pPrev)
	{
		// ���� ���� ����� �����, �� ������� ���������� ����� �� this ������.
		pPrev->pNext = this->pNext;
	}
	if (pNext)
	{
		// ���� ���� ����� ������, �� ������� ���������� ���������� �� this 
		pNext->pPrev = this->pPrev;
	}
};


// ����������


// ������