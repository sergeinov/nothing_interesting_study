#include "List.h"

// конструкторы
List::List() : m_size(0)		// Head и Tail  инициализируются конструторами по умолчанию
{
	Head.pNext = &Tail;		// указывет на конец списка
	Tail.pPrev = &Head;		// указывает на начало списка
};

List::~List()
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
};

// перегрузки


// методы
void List::AddToHead(const Circle& figure)	// добавить в начало списка
{
	new Node(&Head, &figure);	// ошибка в конструкторе при  const Circle* data
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

// удалить один из списка, все сопадающие объекты Circle
bool List::RemoveOne(const Circle& figure)
{
	Node* p = Head.pNext;			// указатель на элемент списка после стража
	while (p != &Tail)
	{
		if (p->m_Data == figure)	// перегруженный operator== в Circle
		{
			m_size--;
			delete p;
			return true;
		}
		p = p->pNext;				// после удаления присваиваем указатель на следующий элемент
	}
	return false;
};