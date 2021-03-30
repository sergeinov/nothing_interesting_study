#pragma once
#include<utility>

template<typename T> class MyQueue
{
	T* m_p{};			//указатель на начало динамического массива
	size_t m_size{};	//актуальное количество элементов в очереди
	size_t m_cap{};		//емкость (сколько выделено памяти)
	const size_t delta = 1; //на сколько увеличиваем емкость при перераспределении памяти
	size_t m_begin{};		//индекс первого элемента в очереди (это тот элемент, который можно извлечь из очереди с помощью pop())
	size_t m_end{};			// индекс первого свободного элемента в очереди (это тот элемент, в который можно присвоить новое значение с помощью push())
public:
	class iterator
	{
		size_t index{};
		MyQueue<T>* p{};
	public:
		iterator() = default;
		iterator(size_t index, MyQueue<T>* p) : index(index), p(p) { };
		T& operator*()
		{
			//return p->m_p[ index ];
			T* p1 = p->m_p;
			//return p1[ index ];
			return *( p1 + index );
		}
		const T& operator*() const
		{
			return p->m_p[ index ];
		}

		iterator& operator++()
		{
			index++;
			/*if ( p->m_cap == index )
			{
				index = 0;
			}*/
			index = index % p->m_cap;
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmp = *this;
			index++;
			index = index % p->m_cap;
			return tmp;
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

	MyQueue() = default;

	iterator begin()
	{
		return iterator(m_begin, this);
	}
	iterator end()
	{
		return iterator(m_end, this);
	}

	void push(const T& value)
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
			m_begin = 0;
			m_end = m_size;
		}
		m_p[ m_end ] = value;
		m_end++;
		m_end = m_end % m_cap;

		m_size++;
	}
};

