#pragma once


template <typename T> class MyStack2
{	
	// вложенный узел данных
	template<typename T>
	class Node
	{
	public:
		Node* pNext;		// указатель на следующую Node
		T data;				//  данные

		Node(T data = T(), Node* pNext = nullptr)	// конструктор	//  Node* pNext = nullptr  считаем что последний указатель на следующий всегда пустой
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;				// размер стека
	Node<T>* head;			// страж

public:
	MyStack2() : size(0), head(nullptr) { };
	~MyStack2() { clear(); };
	// оператор копирования
	// конструктор копирования

	void push(const T& object);			//добавление элемента в  список
	void clear();						// очистить список
	size_t GetSize() const;				// получить количество елементов в списке
	void pop();							//удаление последнего элемента в списке

	T& operator[](const int index);		// перегруженный оператор [] 

};


// ***************************************************//

template<typename T>
inline void MyStack2<T>::push(const T& data)
{
	//head = new Node<T>(data, head);		// создаем новый Node  через конструктор	// добавление в начало списка
	//size++;

	if ( head == nullptr )
	{
		head = new Node<T>(data);		// если список пустой создаем  данные
	}
	else
	{
		Node<T>* p = this->head;		// указатель на начало списка

		while ( p->pNext != nullptr )	// доходим до конца списка
		{
			p = p->pNext;				
		}
		p->pNext = new Node<T>(data);	// создаем данные

	}

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
	Node<T>* p = this->head;					// указатель на начало
	for ( int i = 0; i < size - 1; i++ )
	{
		p = p->pNext;							// идем до последнего в списке
	}						
	delete p;									// удаляем

	size--;
}

template<typename T>
inline T& MyStack2<T>::operator[](const int index)
{
	int count = 0;

	Node<T>* p = this->head;		// начало списка

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
