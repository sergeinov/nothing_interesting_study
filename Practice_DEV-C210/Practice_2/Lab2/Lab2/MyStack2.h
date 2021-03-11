#pragma once
#include<iostream>
#include"MyEmptyStack.h"

template <typename T> class MyStack2
{	
	// вложенный узел данных
	//template<typename T>
	class Node
	{
	public:
		Node* pNext;		// указатель на следующую Node
		T data;				//  данные

		Node(Node* pNext = nullptr, const T & data = T()) : pNext(pNext), data(data)	// конструктор	//  Node* pNext = nullptr  считаем что последний указатель на следующий всегда пустой
		{
			//this->data = data;
			//this->pNext = pNext;
		}
	};

	int size;				// размер стека
	Node* head;			// указатель на первый

	void PrintRecursive(std::ostream& os, Node* data) const;

public:
	MyStack2() : size(0), head(nullptr) { };
	~MyStack2() { clear(); };

	MyStack2(const MyStack2& stack);		// конструктор копирования
	MyStack2(MyStack2&& stack);				// конструктор перемещения
	
	

	void push(const T& object);						//добавление элемента в  список
	void clear();									// очистить список
	size_t GetSize() const;							// получить количество елементов в списке
	void pop();										//удаление последнего элемента в списке
	void Print(std::ostream& os) const;
	

	T& operator[](const int index);					// перегруженный оператор [] 
	const T& operator[](const int index) const;		// перегруженный оператор []  для константных
	template<typename T> friend std::ostream& operator<<(std::ostream& os, const MyStack2<T>& stack);

	MyStack2& operator=(const MyStack2& stack);		// оператор копирования
	//MyStack2& MyStack2<T>::operator=(const MyStack2& stack)
	MyStack2& operator=(MyStack2&& stack);			// оператор перемещения move

};


// ***************************************************//



template<typename T>
inline MyStack2<T>::MyStack2(const MyStack2& stack) : size(stack.size), head(nullptr)			// конструктор копирования
{
	if ( stack.head )
	{
		Node* p = stack.head;								// указатель на первый элемент stack

		this->head = new Node(nullptr, stack.head->data);	//  cоздаем первый нод  такой же  как у stack

		p = p->pNext;										// переместили на его следующий
		Node* pThis = this->head;							//  создали указатель на наш текущий элемент
		while ( p )
		{
			pThis->pNext = new Node(nullptr, p->data);
			p = p->pNext;
			pThis = pThis->pNext;
		}
	}
}

template<typename T>
inline MyStack2<T>::MyStack2(MyStack2&& stack)	: size(stack.size)	// конструктор перемещения
{
	this->head = stack.head;
	stack.head = nullptr;
	stack.size = 0;
}

template<typename T>
inline void MyStack2<T>::push(const T& data)
{
	//head = new Node<T>(data, head);		// создаем новый Node  через конструктор	// добавление в начало списка
	//size++;

	//if ( head == nullptr )
	//{
	//	head = new Node<T>(data);		// если список пустой создаем  данные
	//}
	//else
	//{
	//	Node<T>* p = this->head;		// указатель на начало списка

	//	while ( p->pNext != nullptr )	// доходим до конца списка
	//	{
	//		p = p->pNext;				
	//	}
	//	p->pNext = new Node<T>(data);	// создаем данные

	//}
	head = new Node(head, data);
	size++;
}

template<typename T>
inline void MyStack2<T>::clear()
{
	while ( size )
	{
		pop();		// удаляем сверху вниз
	}
}

template<typename T>
inline size_t MyStack2<T>::GetSize() const
{
	return size;
}


template<typename T>
inline void MyStack2<T>::pop()
{
	if ( head )
	{
		Node* p = this->head;					// указатель на начало
		head = p->pNext;
		delete p;									// удаляем
		size--;
	}
	else
	{
		throw MyEmptyStack(0);
	}
}

template<typename T>
inline void MyStack2<T>::PrintRecursive(std::ostream& os, Node* data) const
{
	if ( data == nullptr )
	{
		return;
	}
	else
	{
		PrintRecursive(os, data->pNext);			// рекурсия
		os << data->data << " ";
	}
}

template<typename T>
inline void MyStack2<T>::Print(std::ostream& os) const
{
	PrintRecursive(os, head);
}

template<typename T>
inline T& MyStack2<T>::operator[](const int index)	
{
	int count = 0;

	Node* p = this->head;		// начало списка

	while ( p != nullptr )			// идем до конца списка
	{
		if ( count == index )
		{
			return p->data;			// когда счетчик совпадет с номером списка, возвращаем адрес данных
		}
		p = p->pNext;				// двигаемся дальше
		count++;
	}
}

template<typename T>
inline const T& MyStack2<T>::operator[](const int index) const	// перегрузка для константных объектов (для случая  std::ostream& operator<<(std::ostream& os, const MyStack2<T>& stack))
{
	int count = 0;

	Node* p = this->head;		// начало списка

	while ( p != nullptr )			// идем до конца списка
	{
		if ( count == index )
		{
			return p->data;			// когда счетчик совпадет с номером списка, возвращаем адрес данных
		}
		p = p->pNext;				// двигаемся дальше
		count++;
	}
}

template<typename T>
MyStack2<T>& MyStack2<T>::operator=(const MyStack2& stack)		// оператор присваивания
{
	// проверяем на одинаковые данные
	if ( this == &stack )
	{
		return *this;
	}
	this->clear();
	Node* p = stack.head;								// указатель на первый элемент stack

	this->head = new Node(nullptr, stack.head->data);	//  cоздаем первый нод  такой же  как у stack

	p = p->pNext;										// переместили на его следующий
	Node* pThis = this->head;							//  создали указатель на наш текущий элемент
	while ( p )
	{
		pThis->pNext = new Node(nullptr, p->data);
		p = p->pNext;
		pThis = pThis->pNext;
	}

}

template<typename T>
MyStack2<T>& MyStack2<T>::operator=(MyStack2&& stack)			// оператор перемещения
{
	this->clear();
	if ( stack.head )
	{
		this->head = stack.head;
	}
	else
	{
		this->head = nullptr;
	}
	this->size = stack.size;
	return *this;
}



template<typename T>
inline std::ostream& operator<<(std::ostream& os, const MyStack2<T>& stack)
{
	/*for ( size_t i = 0; i < stack.GetSize(); i++ )
	{
		os << stack[ i ] << " ";
	}*/
	stack.Print(os);


	return os;
}
