#include "List.h"


/*
*	Конструкторы
*/
List::List() : m_size(0)		// Head и Tail  инициализируются конструторами по умолчанию
{
	Head.pNext = &Tail;		// указывет на конец списка
	Tail.pPrev = &Head;		// указывает на начало списка
};

List::List(const List& otherList) : m_size(otherList.m_size)	// конструктор копирования
{
	// подготовка к копированию
	Head.pNext = &Tail;			//направляет друг на друга
	Tail.pPrev = &Head;

	Node* pThis = &this->Head;				// указатель на начало объекта слева
	Node* pOther = otherList.Head.pNext;	// указатель на первый Node  объекта справа

	// копирование
	for ( size_t i = 0; i < m_size; i++ )
	{
		pThis = new Node(pThis, pOther->figure);	// создание нового нода
		pOther = pOther->pNext;
	}
};
List::List(List&& otherList) : m_size(otherList.m_size)		// конструктор перемещения move
{
	if ( this->m_size == 0 )
	{
		this->Head.pNext = &this->Tail;
		this->Tail.pPrev = &this->Head;
	}
	else
	{
		this->Head.pNext = otherList.Head.pNext;	//  его следующий становится моим this следующим
		this->Tail.pPrev = otherList.Tail.pPrev;	// его предидущий становится моим предидущим
		this->Head.pNext->pPrev = &this->Head;					//  у нода который  у меня стал следующим , предидущий становится мой Head
		this->Tail.pPrev->pNext = &this->Tail;					//  мой предпоследний следующий становится моим последним

		// обнуляем его список
		otherList.Head.pNext = &otherList.Tail;		// указывает на свой хвост
		otherList.Tail.pPrev = &otherList.Head;		// указывает на свою голову
		otherList.m_size = 0;
	}
};

List::~List()
{
	//ClearList();
}

;
/*
*	методы
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
		if ( *(p->figure) == fig )	// перегруженный оператор= в Shape (сравнение цвета)
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
*	перегрузки
*/


