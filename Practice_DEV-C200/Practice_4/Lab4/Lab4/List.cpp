#include "List.h"

// ������������
List::List() : m_size(0)		// Head � Tail  ���������������� ������������� �� ���������
{
	Head.pNext = &Tail;		// �������� �� ����� ������
	Tail.pPrev = &Head;		// ��������� �� ������ ������
};

List::List(const List& otherList) : m_size(otherList.m_size)	// ����������� �����������
{
	// ���������� � �����������
	Head.pNext = &Tail;			//���������� ���� �� �����
	Tail.pPrev = &Head;
	
	Node* pThis = &this->Head;				// ��������� �� ������ ������� �����
	Node* pOther = otherList.Head.pNext;	// ��������� �� ������ Node  ������� ������

	// �����������
	for (size_t i = 0; i < m_size; i++)
	{
		pThis = new Node(pThis, pOther->m_Data);	// �������� ������ ����
		pOther = pOther->pNext;
	}
};	
List::List(List&& otherList) : m_size(otherList.m_size)		// ����������� ����������� move
{
	// ������ �� ������� otherList ?

	this->Head.pNext = otherList.Head.pNext;	//  ��� ��������� ���������� ���� this ���������
	this->Tail.pPrev = otherList.Tail.pPrev;	// ��� ���������� ���������� ���� ����������
	this->Head.pNext->pPrev = &this->Head;					//  � ���� �������  � ���� ���� ��������� , ���������� ���������� ��� Head
	this->Tail.pPrev->pNext = &this->Tail;					//  ��� ������������� ��������� ���������� ���� ���������

	// �������� ��� ������
	otherList.Head.pNext = &otherList.Tail;		// ��������� �� ���� �����
	otherList.Tail.pPrev = &otherList.Head;		// ��������� �� ���� ������
	otherList.m_size = 0;
};			

List::~List()
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
};

// ����������
List& List::operator=(const List& otherList)	//���������� ��������� ������������ = ��� �������
{
	// TODO
};		

// ������
void List::AddToHead(const Circle& figure)	// �������� � ������ ������
{
	new Node(&Head, &figure); // ����� �� head  � Circle
	m_size++;
};

void List::AddToEnd(const Circle& figure)			// �������� � ����� ������
{
	new Node(Tail.pPrev, &figure);
	m_size++;
};	

// ������� ��� �� ������ (����������� ������� Circle) // ���������� ���������� ��������� ��������
int List::RemoveAll(const Circle& figure)
{
	int quantity = 0;
	Node* p = Head.pNext;			// ��������� �� ������� ������ ����� ������
	while (p != &Tail)
	{
		Node* temp = p->pNext;
		if (p->m_Data == figure)	// ������������� operator== � Circle
		{
			m_size--;
			delete p;	
			quantity++;
		}
		p = temp;				// ����� �������� ����������� ��������� �� ��������� �������
	}
	return quantity;
};

// ������� ���� �� ������, ���������� ������� Circle
bool List::RemoveOne(const Circle& figure)
{
	Node* p = Head.pNext;			// ��������� �� ������� ������ ����� ������
	while (p != &Tail)
	{
		if (p->m_Data == figure)	// ������������� operator== � Circle
		{
			m_size--;
			delete p;
			return true;
		}
		p = p->pNext;				// ����� �������� ����������� ��������� �� ��������� �������
	}
	return false;
};

