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
	ClearList();
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

void List::AddToEnd(const Shape& figure)
{
	new Node(Tail.pPrev, &figure);
	m_size++;
}

bool List::RemoveOne(const Shape& fig)
{
	Node* p = Head.pNext;			// ��������� �� ��������� ����� ������
	while ( p != &Tail )
	{
		// ���� ����� ��������� ������ ������� �����, �������
		if ( *(p->figure) == fig )	// ������������� ��������= � Shape (��������� �����)
		{
			delete p;
			m_size--;
			return true;
		}
		p = p->pNext;				// ��������� ������ �� ������, ���� ���������� ������
	}
	return false;
}

void List::ClearList()				// !DONE
{
	while ( Head.pNext != &Tail )	// ? ������ ������������ �� ������
	{
		delete Head.pNext;
	}
	m_size = 0;
}

void List::Sort(eParametrs param)
{
	Node* pCurrent = Head.pNext;

	while ( pCurrent != Tail.pPrev )	// ���� ��������� �� ����� ����������
	{
		Node* pMin = pCurrent;	// �� ������ Node  // ������ ������� ������
		Node* p = pCurrent->pNext;	// �� ��������� Node
		while ( p != &Tail )	// ���� ������ Node  �� ����� � �����
		{
			// ������� ������������ � ������� �������� �� ����� �������� �� ������ �������� ����������� enum eParametrs {Color, Area .....};
			bool flag = false;
			switch ( param )
			{
			case Color:
				flag = ( p->figure->GetColor() < pMin->figure->GetColor() );
				break;
			case Area:
				flag = ( p->figure->Area() < pMin->figure->Area() );
				break;
			}
			//if ( p->figure->Area() < pMin->figure->Area())	// ���������� ��� ������� �� ���������� ������ ���������� ������� Area()
			//{
			//	pMin = p;
			//}

			if ( flag )
			{
				pMin = p;
			}
			p = p->pNext;		// ��������� ������
		}
		// ����� ��������
		Shape* temp = pCurrent->figure;
		pCurrent->figure = pMin->figure;
		pMin->figure = temp;

		pCurrent = pCurrent->pNext;		// ��������� ������

	}
}

/*
*	����������
*/


List& List::operator=(const List& otherList)	//���������� ��������� ������������ = ��� �������		//TODO
{
	
	Node* pThis = this->Head.pNext;
	Node* pOther = otherList.Head.pNext;

	while ( pThis != &this->Tail && pOther != &otherList.Tail )
	{
		// ���� ������� ����������� ����, �������� ��������  ����� �� ������ � Node. ���� ������ ������� ����, �������� ������
		if ( typeid(*pThis->figure) == typeid(*pOther->figure) )
		{
			*pThis->figure = *pOther->figure;	// TODO  ���������� ���������=  (�����������)
		}
		else
		{
			// ���� ������
			delete pThis->figure;							// ������� ���� 
			pThis->figure = pOther->figure->Clone();		// ��������
		}
		//pThis->m_Data = pOther->m_Data;				
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
		this->AddToEnd(*pOther->figure);
		pOther = pOther->pNext;
	}
	this->m_size = otherList.m_size;
	return *this;
}