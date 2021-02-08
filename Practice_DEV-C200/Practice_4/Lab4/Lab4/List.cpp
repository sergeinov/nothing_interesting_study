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
	for (size_t i = 0; i < m_size; i++)
	{
		pThis = new Node(pThis, &pOther->m_Data);	// �������� ������ ����
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
	ClearList();
};

/*
*	����������
*/
List& List::operator=(const List& otherList)	//���������� ��������� ������������ = ��� �������
{
	Node* pThis = this->Head.pNext;
	Node* pOther = otherList.Head.pNext;
	// �����������
	while ( pThis != &this->Tail && pOther != &otherList.Tail)
	{
		pThis->m_Data = pOther->m_Data;
		pThis = pThis->pNext;
		pOther = pOther->pNext;
	}
	// this ������  otherList
	for ( size_t i = otherList.m_size; i < this->m_size; i++ )
	{
		delete Tail.pPrev;
	}
	// otherList ������ this
	for ( size_t i = this->m_size; i < otherList.m_size; i++ )
	{
		this->AddToEnd(pOther->m_Data);
		pOther = pOther->pNext;
	}
	this->m_size = otherList.m_size;
	return *this;
}

List& List::operator=(List&& otherList)		// ���������� ��������� ������������ ������������ // ��� ��������� ��������
{
	if ( this != &otherList )
	{
		this->ClearList();	
	}

	return *this;
}

/*
*	������ 
*/

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
	while (p != &Tail)				// ���� �� ������ �� ������ Tail
	{
		Node* temp = p->pNext;		// ���������� ��� �������� �� ������
		if (p->m_Data == figure)	// ������������� operator== � Circle
		{
			m_size--;
			delete p;				// ������� �����
			quantity++;
		}
		p = temp;					// ����� �������� ����������� ��������� �� ��������� �������
	}
	return quantity;
}

void List::ClearList()
{
	while ( Head.pNext != &Tail )
	{
		delete Head.pNext;
	}
	m_size = 0;
}


// ������� ���� �� ������, ���������� ������� Circle
bool List::RemoveOne(const Circle& figure)
{
	Node* p = Head.pNext;			// ��������� �� ������� ������ ����� ������	//  ���������� ��� ��������
	while (p != &Tail)
	{
		if (p->m_Data == figure)	// ������������� operator== � Circle
		{
			m_size--;
			delete p;				// ����� ����������� Circle
			return true;
		}
		p = p->pNext;				// ����� �������� ����������� ��������� �� ��������� �������
	}
	return false;
};

void List::SortList()		// ����������  �� ����������� �������
{
	Node* pCurrent = Head.pNext;	//  ���������� ��� �������� 
	
	while ( pCurrent != Tail.pPrev )	// ���� ��������� �� ����� ����������
	{
		Node* pMin = pCurrent;	// �� ������ Node  // ������ ������� ������
		Node* p = pCurrent->pNext;	// �� ��������� Node

		while ( p != &Tail )	// ���� ������ Node  �� ����� � �����
		{
			if ( p->m_Data < pMin->m_Data)	// ���������� ��� ������� �� ���� m_radius
			{
				pMin = p;
			}
			p = p->pNext;		// ��������� ������
		}

		if ( pMin == pCurrent )	// ���� ������ ����� ��������� ��������
		{
			pCurrent = pCurrent->pNext;
		}
		else
		{
			// �����
			Node* prev = pMin->pPrev;	//  ���������� ��� ��������
			Node* next = pMin->pNext;	//  ���������� ��� ��������
			prev->pNext = next;
			next->pPrev = prev;

			// ���������
			Node* newPrev = pCurrent->pPrev;
			Node* newNext = pCurrent;

			pMin->pNext = newNext;
			pMin->pPrev = newPrev;

			newPrev->pNext = pMin;
			newNext->pPrev = pMin;
		}

	}

};

