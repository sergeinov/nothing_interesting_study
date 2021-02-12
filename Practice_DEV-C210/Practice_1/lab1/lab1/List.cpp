#include "List.h"


/*
*	������������
*/
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
	for ( size_t i = 0; i < m_size; i++ )
	{
		pThis = new Node(pThis, pOther->figure);	// �������� ������ ����
		pOther = pOther->pNext;
	}
};
List::List(List&& otherList) : m_size(otherList.m_size)		// ����������� ����������� move
{
	if ( this->m_size == 0 )
	{
		this->Head.pNext = &this->Tail;
		this->Tail.pPrev = &this->Head;
	}
	else
	{
		this->Head.pNext = otherList.Head.pNext;	//  ��� ��������� ���������� ���� this ���������
		this->Tail.pPrev = otherList.Tail.pPrev;	// ��� ���������� ���������� ���� ����������
		this->Head.pNext->pPrev = &this->Head;					//  � ���� �������  � ���� ���� ��������� , ���������� ���������� ��� Head
		this->Tail.pPrev->pNext = &this->Tail;					//  ��� ������������� ��������� ���������� ���� ���������

		// �������� ��� ������
		otherList.Head.pNext = &otherList.Tail;		// ��������� �� ���� �����
		otherList.Tail.pPrev = &otherList.Head;		// ��������� �� ���� ������
		otherList.m_size = 0;
	}
};

List::~List()
{
	//ClearList();
}

;
/*
*	������
*/
void List::AddToHead(const Shape& figure)
{
	new Node(&Head, &figure);
	m_size++;
}

void List::AddToEnd(const Shape& figure)	// !DONE
{
	new Node(Tail.pPrev, &figure);
	m_size++;
}

bool List::RemoveOne(const Shape& fig)
{
	Node* p = Head.pNext;
	while ( p != &Tail )
	{
		if ( *(p->figure) == fig )	// ������������� ��������= � Shape (��������� �����)
		{
			delete p;
			m_size--;
			return true;
		}
		p = p->pNext;
	}
	return false;
}

/*
*	����������
*/


