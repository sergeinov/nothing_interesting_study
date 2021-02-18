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
	ClearList();
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

void List::AddToEnd(const Shape& figure)
{
	new Node(Tail.pPrev, &figure);
	m_size++;
}

bool List::RemoveOne(const Shape& fig)
{
	Node* p = Head.pNext;			// указатель на следующий после стража
	while ( p != &Tail )
	{
		// если цвета совпадают значит объекты схожи, удаляем
		if ( *(p->figure) == fig )	// перегруженный оператор= в Shape (сравнение цвета)
		{
			delete p;
			m_size--;
			return true;
		}
		p = p->pNext;				// двигаемся дальше по списку, ищем подходящий объект
	}
	return false;
}

void List::ClearList()				// !DONE
{
	while ( Head.pNext != &Tail )	// ? почему продвигается по списку
	{
		delete Head.pNext;
	}
	m_size = 0;
}

void List::Sort(eParametrs param)
{
	Node* pCurrent = Head.pNext;

	while ( pCurrent != Tail.pPrev )	// пока следующий не равно предыдущий
	{
		Node* pMin = pCurrent;	// на первый Node  // первый элемент списка
		Node* p = pCurrent->pNext;	// на следующий Node
		while ( p != &Tail )	// пока первый Node  не страж в конце
		{
			// создали перечисления с помощью которого мы можем выбирать по какому свойству сортировать enum eParametrs {Color, Area .....};
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
			//if ( p->figure->Area() < pMin->figure->Area())	// сравниваем два объекта по результату метода вычисления площади Area()
			//{
			//	pMin = p;
			//}

			if ( flag )
			{
				pMin = p;
			}
			p = p->pNext;		// двигаемся дальше
		}
		// обмен объектов
		Shape* temp = pCurrent->figure;
		pCurrent->figure = pMin->figure;
		pMin->figure = temp;

		pCurrent = pCurrent->pNext;		// двигаемся дальше

	}
}

/*
*	перегрузки
*/


List& List::operator=(const List& otherList)	//Перегрузка оператора присваивания = для обьекта		//TODO
{
	
	Node* pThis = this->Head.pNext;
	Node* pOther = otherList.Head.pNext;

	while ( pThis != &this->Tail && pOther != &otherList.Tail )
	{
		// если фигурки одинакового типа, заменяем значение  слева на справа в Node. Если разное удаляем свое, копируем вторую
		if ( typeid(*pThis->figure) == typeid(*pOther->figure) )
		{
			*pThis->figure = *pOther->figure;	// TODO  перегрузку оператора=  (виртуальный)
		}
		else
		{
			// если разное
			delete pThis->figure;							// удаляем свое 
			pThis->figure = pOther->figure->Clone();		// копируем
		}
		//pThis->m_Data = pOther->m_Data;				
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
		this->AddToEnd(*pOther->figure);
		pOther = pOther->pNext;
	}
	this->m_size = otherList.m_size;
	return *this;
}