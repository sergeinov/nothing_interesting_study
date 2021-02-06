#include "List.h"

// конструкторы
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
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
};

// перегрузки
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
List& List::operator=(List&& otherList)
{
	// TODO: insert return statement here
	return *this;
}

// методы
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
	while (p != &Tail)
	{
		Node* temp = p->pNext;
		if (p->m_Data == figure)	// перегруженный operator== в Circle
		{
			m_size--;
			delete p;	
			quantity++;
		}
		p = temp;				// после удаления присваиваем указатель на следующий элемент
	}
	return quantity;
};

// удалить один из списка, сопадающий объекты Circle
bool List::RemoveOne(const Circle& figure)
{
	Node* p = Head.pNext;			// указатель на элемент списка после стража
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

