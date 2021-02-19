#pragma once


template <typename T> class MyStack2
{	
	// ��������� ���� ������
	template<typename T>
	class Node
	{
	public:
		Node* pNext;		// ��������� �� ��������� Node
		T data;				//  ������

		Node(T data = T(), Node* pNext = nullptr)	// �����������	//  Node* pNext = nullptr  ������� ��� ��������� ��������� �� ��������� ������ ������
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;				// ������ �����
	Node<T>* head;			// �����

public:
	MyStack2() : size(0), head(nullptr) { };
	~MyStack2() { clear(); };
	// �������� �����������
	// ����������� �����������

	void push(const T& object);			//���������� �������� �  ������
	void clear();						// �������� ������
	size_t GetSize() const;				// �������� ���������� ��������� � ������
	void pop();							//�������� ���������� �������� � ������

	T& operator[](const int index);		// ������������� �������� [] 

};


// ***************************************************//

template<typename T>
inline void MyStack2<T>::push(const T& data)
{
	//head = new Node<T>(data, head);		// ������� ����� Node  ����� �����������	// ���������� � ������ ������
	//size++;

	if ( head == nullptr )
	{
		head = new Node<T>(data);		// ���� ������ ������ �������  ������
	}
	else
	{
		Node<T>* p = this->head;		// ��������� �� ������ ������

		while ( p->pNext != nullptr )	// ������� �� ����� ������
		{
			p = p->pNext;				
		}
		p->pNext = new Node<T>(data);	// ������� ������

	}

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
	Node<T>* p = this->head;					// ��������� �� ������
	for ( int i = 0; i < size - 1; i++ )
	{
		p = p->pNext;							// ���� �� ���������� � ������
	}						
	delete p;									// �������

	size--;
}

template<typename T>
inline T& MyStack2<T>::operator[](const int index)
{
	int count = 0;

	Node<T>* p = this->head;		// ������ ������

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
