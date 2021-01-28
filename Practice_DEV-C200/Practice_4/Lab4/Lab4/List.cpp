#include "List.h"

// ������������
List::List() : m_size(0)		// Head � Tail  ���������������� ������������� �� ���������
{
	Head.pNext = &Tail;		// �������� �� ����� ������
	Tail.pPrev = &Head;		// ��������� �� ������ ������
};

List::~List()
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
};

// ����������


// ������
void List::AddToHead(const Circle& figure)	// �������� � ������ ������
{
	new Node(&Head, &figure);	// ������ � ������������ ���  const Circle* data
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

// ������� ���� �� ������, ��� ���������� ������� Circle
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