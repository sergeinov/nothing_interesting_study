#pragma once
#include<utility>
#include<algorithm>
#include"MyString.h"

template<typename T, typename V> void myCopy(T first, T last, V to)
{
	while ( first != last )
	{
		*to = *first;
		++to;
		++first;
	}
}

template<typename T> class MyQueue
{
	T* m_p{};				//��������� �� ������ ������������� �������
	size_t m_size{};		//���������� ���������� ��������� � �������
	size_t m_cap{1};		//������� (������� �������� ������)
	const size_t delta = 1; //�� ������� ����������� ������� ��� ����������������� ������
	size_t m_begin{};		//������ ������� �������� � ������� (��� ��� �������, ������� ����� ������� �� ������� � ������� pop())
	size_t m_end{};			// ������ ������� ���������� �������� � ������� (��� ��� �������, � ������� ����� ��������� ����� �������� � ������� push())
public:
	class iterator
	{
		size_t index{};
		const MyQueue<T>* p{};
	public:
		/*
		*  ������������
		*/
		iterator() = default;
		iterator(size_t index, const MyQueue<T>* p) : index(index), p(p) { };

		/*
		*  ������
		*/
		T& operator*()													// �������� �������������
		{
			//return p->m_p[ index ];
			T* p1 = p->m_p;
			//return p1[ index ];
			return *( p1 + index );		// ��������� ����� �� ������� � �������������� ��������
		}
		const T& operator*() const										// �������� ������������� ��� ��������
		{
			return p->m_p[ index ];
		}

		iterator& operator++()					// ����������
		{
			index++;
			/*if ( p->m_cap == index )
			{
				index = 0;
			}*/
			index = index % p->m_cap;			// ��������� ������ �� ������� �������������������
			return *this;
		}
		iterator operator++(int)				// �����������
		{
			iterator tmp = *this;
			index++;
			index = index % p->m_cap;			// �����������
			return tmp;							// ���������� ����� �������������� �������
		}
		bool operator==(const iterator& other) const
		{
			return ( index == other.index && p == other.p );
		}

		bool operator!=(const iterator& other) const
		{
			return !operator==(other);
		}
	};

	/*
	*  ������������
	*/

	MyQueue() = default;						//  ����������� �� ���������
	MyQueue(std::initializer_list<T> list)		// ����������� � �����������(������ �������������)
	{
		m_size = list.size();
		m_cap = m_size + 1;
		m_p = new T[ m_cap ];
		std::copy(list.begin(), list.end(), m_p);
		m_begin = 0;
		m_end = m_size;
	}

	MyQueue(int num, const T& str)		// ����������� � �����������(������� ������ ��������� 10 ��������� �� �������)
	{
		m_size = num;
		m_cap = m_size + 1;
		m_p = new T[ m_cap ];
		for ( size_t i = 0; i < m_size; i++ )		// ��������� �� ������������� �������
		{
			m_p[ i ] = str;							// ���������� ��������
		}
		m_begin = 0;
		m_end = m_size;
	}

	MyQueue(const MyQueue& other)				// ����������� �����������
	{
		if ( other.m_size != 0 )
		{
			m_size = other.m_size;
			m_cap = m_size + 1;
			m_p = new T[ m_cap ];
			iterator it = other.begin();
			for ( size_t i = 0; i < m_size; i++ )
			{
				m_p[ i ] = *it;
				++it;
			}
			m_end = m_size;
		}
	}
	MyQueue(MyQueue&& other)					// ����������� �����������
	{
		m_p = other.m_p;
		m_size = other.m_size;
		m_cap = other.m_cap;
		m_begin = other.m_begin;
		m_end = other.m_end;
		other.m_size = 0;
		other.m_cap = 1;
		other.m_begin = 0;
		other.m_end = 0;
		other.m_p = nullptr;
	}

	MyQueue& operator=(const MyQueue& other)	// �������� ������������
	{
		if ( this != &other )
		{
			if ( this->m_cap <= (other.m_size + 1) )	// ��������� , ������� ������ ��� ���
			{
				// ���������������� ������
				delete[] this->m_p;
				m_cap = other.m_size + 1;
				m_p = new T[ m_cap ];
			}
			auto it = other.begin();
			for ( size_t i = 0; i < m_size; i++ )
			{
				m_p[ i ] = *it;
				++it;
			}
			this->m_size = other.m_size;
			m_begin = 0;
			m_end = this->m_size;
		}
		return *this;
	}

	MyQueue& operator=(std::initializer_list<T>&& list)			// ���������� ��������� ������������
	{
		delete[] this->m_p;
		m_size = list.size();
		m_cap = m_size + 1;
		m_p = new T[ m_cap ];
		std::copy(list.begin(), list.end(), m_p);
		m_begin = 0;
		m_end = m_size;
		return *this;
	}


	MyQueue& operator=(MyQueue&& other)		// �������� �����������
	{
		if ( this != &other )
		{
			delete[] this->m_p;
			m_p = other.m_p;
			m_size = other.m_size;
			m_cap = other.m_cap;
			m_begin = other.m_begin;
			m_end = other.m_end;
			other.m_size = 0;
			other.m_cap = 1;
			other.m_begin = 0;
			other.m_end = 0;
			other.m_p = nullptr;
		}
		return *this;
	}

	/*
	*  ������
	*/

	iterator begin() const
	{
		return iterator(m_begin, this);
	}
	iterator end() const
	{
		return iterator(m_end, this);
	}

	void push(const T& value)			// ��������� ����� �������� � ������� push()
	{
		if ( m_size == (m_cap - 1))
		{
			m_cap += delta;
			T* temp = new T[m_cap];

			for ( size_t i = 0, j = m_begin; i < m_size; i++ )
			{
				temp[ i ] = std::move(m_p[ j ]);
				j++;
				j = j % m_cap;
			}
			delete[] m_p;
			m_p = temp;
			m_begin = 0;
			m_end = m_size;
		}
		m_p[ m_end ] = value;
		m_end++;
		m_end = m_end % m_cap;

		m_size++;
	}

	T pop()
	{
		if ( this->m_size )
		{
			T temp = std::move(m_p[ m_begin ]);
			++m_begin;
			m_begin = m_begin % m_cap;		// ���� �� �������, �������������� / ������������ �� ����
			m_size--;
			return temp;
		}
		throw "empty queue";
	}

	T& operator[](int index)
	{
		if ( index >= 0 && index < m_size)
		{
			int i = ( m_begin + index ) % m_cap;		// ��������� ����� � ���������
			return m_p[ i ];
		}
		throw "invalid index";
	}
};

