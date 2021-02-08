#include "List.h"

/*
*	конструкторы
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
	for (size_t i = 0; i < m_size; i++)
	{
		pThis = new Node(pThis, &pOther->m_Data);	// создание нового нода
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
	ClearList();
};

/*
*	перегрузки
*/
List& List::operator=(const List& otherList)	//Перегрузка оператора присваивания = для обьекта
{
	Node* pThis = this->Head.pNext;
	Node* pOther = otherList.Head.pNext;
	// копирования
	while ( pThis != &this->Tail && pOther != &otherList.Tail)
	{
		pThis->m_Data = pOther->m_Data;
		pThis = pThis->pNext;
		pOther = pOther->pNext;
	}
	// this больше  otherList
	for ( size_t i = otherList.m_size; i < this->m_size; i++ )
	{
		delete Tail.pPrev;
	}
	// otherList больше this
	for ( size_t i = this->m_size; i < otherList.m_size; i++ )
	{
		this->AddToEnd(pOther->m_Data);
		pOther = pOther->pNext;
	}
	this->m_size = otherList.m_size;
	return *this;
}

List& List::operator=(List&& otherList)		// перегрузка оператора присваивания перемещением // для временных объектов
{
	if ( this != &otherList )
	{
		this->ClearList();	
	}

	return *this;
}

/*
*	методы 
*/

void List::AddToHead(const Circle& figure)	// добавить в начало списка 
{
	new Node(&Head, &figure); // адрес на head  и Circle
	m_size++;
};

void List::AddToEnd(const Circle& figure)			// добавить в конец списка
{
	new Node(Tail.pPrev, &figure);
	m_size++;
};	

// удалить все из списка (совпадающие объекты Circle) // возвращает количество удаленных обьектов
int List::RemoveAll(const Circle& figure)
{
	int quantity = 0;
	Node* p = Head.pNext;			// указатель на элемент списка после стража
	while (p != &Tail)				// пока не дойдем до стража Tail
	{
		Node* temp = p->pNext;		// переменная для движения по списку
		if (p->m_Data == figure)	// перегруженный operator== в Circle
		{
			m_size--;
			delete p;				// удаляем адрес
			quantity++;
		}
		p = temp;					// после удаления присваиваем указатель на следующий элемент
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


// удалить один из списка, сопадающий объекты Circle
bool List::RemoveOne(const Circle& figure)
{
	Node* p = Head.pNext;			// указатель на элемент списка после стража	//  переменная для удобства
	while (p != &Tail)
	{
		if (p->m_Data == figure)	// перегруженный operator== в Circle
		{
			m_size--;
			delete p;				// вызов деструктора Circle
			return true;
		}
		p = p->pNext;				// после удаления присваиваем указатель на следующий элемент
	}
	return false;
};

void List::SortList()		// сортировка  по возрастанию радиуса
{
	Node* pCurrent = Head.pNext;	//  переменная для удобства 
	
	while ( pCurrent != Tail.pPrev )	// пока следующий не равно предыдущий
	{
		Node* pMin = pCurrent;	// на первый Node  // первый элемент списка
		Node* p = pCurrent->pNext;	// на следующий Node

		while ( p != &Tail )	// пока первый Node  не страж в конце
		{
			if ( p->m_Data < pMin->m_Data)	// сравниваем два объекта по полю m_radius
			{
				pMin = p;
			}
			p = p->pNext;		// двигаемся дальше
		}

		if ( pMin == pCurrent )	// если объект самый маленький оказался
		{
			pCurrent = pCurrent->pNext;
		}
		else
		{
			// обмен
			Node* prev = pMin->pPrev;	//  переменная для удобства
			Node* next = pMin->pNext;	//  переменная для удобства
			prev->pNext = next;
			next->pPrev = prev;

			// вставляем
			Node* newPrev = pCurrent->pPrev;
			Node* newNext = pCurrent;

			pMin->pNext = newNext;
			pMin->pPrev = newPrev;

			newPrev->pNext = pMin;
			newNext->pPrev = pMin;
		}

	}

};

