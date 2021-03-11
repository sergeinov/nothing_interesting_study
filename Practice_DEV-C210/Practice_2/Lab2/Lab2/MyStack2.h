#pragma once
#include<iostream>
#include"MyEmptyStack.h"

template <typename T> class MyStack2
{	
	// ��������� ���� ������
	//template<typename T>
	class Node
	{
	public:
		Node* pNext;		// ��������� �� ��������� Node
		T data;				//  ������

		Node(Node* pNext = nullptr, const T & data = T()) : pNext(pNext), data(data)	// �����������	//  Node* pNext = nullptr  ������� ��� ��������� ��������� �� ��������� ������ ������
		{
			//this->data = data;
			//this->pNext = pNext;
		}
	};

	int size;				// ������ �����
	Node* head;			// ��������� �� ������

	void PrintRecursive(std::ostream& os, Node* data) const;

public:
	MyStack2() : size(0), head(nullptr) { };
	~MyStack2() { clear(); };

	MyStack2(const MyStack2& stack);		// ����������� �����������
	MyStack2(MyStack2&& stack);				// ����������� �����������
	
	

	void push(const T& object);						//���������� �������� �  ������
	void clear();									// �������� ������
	size_t GetSize() const;							// �������� ���������� ��������� � ������
	void pop();										//�������� ���������� �������� � ������
	void Print(std::ostream& os) const;
	

	T& operator[](const int index);					// ������������� �������� [] 
	const T& operator[](const int index) const;		// ������������� �������� []  ��� �����������
	template<typename T> friend std::ostream& operator<<(std::ostream& os, const MyStack2<T>& stack);

	MyStack2& operator=(const MyStack2& stack);		// �������� �����������
	//MyStack2& MyStack2<T>::operator=(const MyStack2& stack)
	MyStack2& operator=(MyStack2&& stack);			// �������� ����������� move

};


// ***************************************************//



template<typename T>
inline MyStack2<T>::MyStack2(const MyStack2& stack) : size(stack.size), head(nullptr)			// ����������� �����������
{
	if ( stack.head )
	{
		Node* p = stack.head;								// ��������� �� ������ ������� stack

		this->head = new Node(nullptr, stack.head->data);	//  c������ ������ ���  ����� ��  ��� � stack

		p = p->pNext;										// ����������� �� ��� ���������
		Node* pThis = this->head;							//  ������� ��������� �� ��� ������� �������
		while ( p )
		{
			pThis->pNext = new Node(nullptr, p->data);
			p = p->pNext;
			pThis = pThis->pNext;
		}
	}
}

template<typename T>
inline MyStack2<T>::MyStack2(MyStack2&& stack)	: size(stack.size)	// ����������� �����������
{
	this->head = stack.head;
	stack.head = nullptr;
	stack.size = 0;
}

template<typename T>
inline void MyStack2<T>::push(const T& data)
{
	//head = new Node<T>(data, head);		// ������� ����� Node  ����� �����������	// ���������� � ������ ������
	//size++;

	//if ( head == nullptr )
	//{
	//	head = new Node<T>(data);		// ���� ������ ������ �������  ������
	//}
	//else
	//{
	//	Node<T>* p = this->head;		// ��������� �� ������ ������

	//	while ( p->pNext != nullptr )	// ������� �� ����� ������
	//	{
	//		p = p->pNext;				
	//	}
	//	p->pNext = new Node<T>(data);	// ������� ������

	//}
	head = new Node(head, data);
	size++;
}

template<typename T>
inline void MyStack2<T>::clear()
{
	while ( size )
	{
		pop();		// ������� ������ ����
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
		Node* p = this->head;					// ��������� �� ������
		head = p->pNext;
		delete p;									// �������
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
		PrintRecursive(os, data->pNext);			// ��������
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

	Node* p = this->head;		// ������ ������

	while ( p != nullptr )			// ���� �� ����� ������
	{
		if ( count == index )
		{
			return p->data;			// ����� ������� �������� � ������� ������, ���������� ����� ������
		}
		p = p->pNext;				// ��������� ������
		count++;
	}
}

template<typename T>
inline const T& MyStack2<T>::operator[](const int index) const	// ���������� ��� ����������� �������� (��� ������  std::ostream& operator<<(std::ostream& os, const MyStack2<T>& stack))
{
	int count = 0;

	Node* p = this->head;		// ������ ������

	while ( p != nullptr )			// ���� �� ����� ������
	{
		if ( count == index )
		{
			return p->data;			// ����� ������� �������� � ������� ������, ���������� ����� ������
		}
		p = p->pNext;				// ��������� ������
		count++;
	}
}

template<typename T>
MyStack2<T>& MyStack2<T>::operator=(const MyStack2& stack)		// �������� ������������
{
	// ��������� �� ���������� ������
	if ( this == &stack )
	{
		return *this;
	}
	this->clear();
	Node* p = stack.head;								// ��������� �� ������ ������� stack

	this->head = new Node(nullptr, stack.head->data);	//  c������ ������ ���  ����� ��  ��� � stack

	p = p->pNext;										// ����������� �� ��� ���������
	Node* pThis = this->head;							//  ������� ��������� �� ��� ������� �������
	while ( p )
	{
		pThis->pNext = new Node(nullptr, p->data);
		p = p->pNext;
		pThis = pThis->pNext;
	}

}

template<typename T>
MyStack2<T>& MyStack2<T>::operator=(MyStack2&& stack)			// �������� �����������
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
