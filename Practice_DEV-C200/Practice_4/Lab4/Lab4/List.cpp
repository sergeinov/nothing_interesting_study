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
		pThis = new Node(pThis, pOther->m_Data);	// создание нового нода
		pOther = pOther->pNext;
	}
};	
List::List(List&& otherList) : m_size(otherList.m_size)		// конструктор перемещения move
{
	// защита от пустого otherList ?

	this->Head.pNext = otherList.Head.pNext;	//  его следующий становится моим this следующим
	this->Tail.pPrev = otherList.Tail.pPrev;	// его предидущий становится моим предидущим
	this->Head.pNext->pPrev = &this->Head;					//  у нода который  у меня стал следующим , предидущий становится мой Head
	this->Tail.pPrev->pNext = &this->Tail;					//  мой предпоследний следующий становится моим последним

	// обнуляем его список
	otherList.Head.pNext = &otherList.Tail;		// указывает на свой хвост
	otherList.Tail.pPrev = &otherList.Head;		// указывает на свою голову
	otherList.m_size = 0;
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
	// TODO
};		

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
			delete p;
			return true;
		}
		p = p->pNext;				// после удаления присваиваем указатель на следующий элемент
	}
	return false;
};

