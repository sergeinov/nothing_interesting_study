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
	T* m_p{};				//указатель на начало динамического массива
	size_t m_size{};		//актуальное количество элементов в очереди
	size_t m_cap{1};		//емкость (сколько выделено памяти)
	const size_t delta = 1; //на сколько увеличиваем емкость при перераспределении памяти
	size_t m_begin{};		//индекс первого элемента в очереди (это тот элемент, который можно извлечь из очереди с помощью pop())
	size_t m_end{};			// индекс первого свободного элемента в очереди (это тот элемент, в который можно присвоить новое значение с помощью push())
public:
	class iterator
	{
		size_t index{};
		const MyQueue<T>* p{};
	public:
		/*
		*  Конструкторы
		*/
		iterator() = default;
		iterator(size_t index, const MyQueue<T>* p) : index(index), p(p) { };

		/*
		*  методы
		*/
		T& operator*()													// оператор разименования
		{
			//return p->m_p[ index ];
			T* p1 = p->m_p;
			//return p1[ index ];
			return *( p1 + index );		// вычисляем адрес по индексу и разименовываем значение
		}
		const T& operator*() const										// оператор разименования для констант
		{
			return p->m_p[ index ];
		}

		iterator& operator++()					// префиксный
		{
			index++;
			/*if ( p->m_cap == index )
			{
				index = 0;
			}*/
			index = index % p->m_cap;			// вычисляем размер по емкости посследовательности
			return *this;
		}
		iterator operator++(int)				// постфиксный
		{
			iterator tmp = *this;
			index++;
			index = index % p->m_cap;			// увеличиваем
			return tmp;							// возвращаем адрес неизменненного индекса
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
	*  Конструкторы
	*/

	MyQueue() = default;						//  конструктор по умолчанию
	MyQueue(std::initializer_list<T> list)		// конструктор с параметрами(список инициализации)
	{
		m_size = list.size();
		m_cap = m_size + 1;
		m_p = new T[ m_cap ];
		std::copy(list.begin(), list.end(), m_p);
		m_begin = 0;
		m_end = m_size;
	}

	MyQueue(int num, const T& str)		// конструктор с параметрами(очередь должна содержать 10 элементов со строкой)
	{
		m_size = num;
		m_cap = m_size + 1;
		m_p = new T[ m_cap ];
		for ( size_t i = 0; i < m_size; i++ )		// двигаемся по динамическому массиву
		{
			m_p[ i ] = str;							// записываем значение
		}
		m_begin = 0;
		m_end = m_size;
	}

	MyQueue(const MyQueue& other)				// конструктор копирования
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
	MyQueue(MyQueue&& other)					// конструктор перемещения
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

	MyQueue& operator=(const MyQueue& other)	// оператор присваивания
	{
		if ( this != &other )
		{
			if ( this->m_cap <= (other.m_size + 1) )	// проверяем , хватает памяти или нет
			{
				// перераспределяем память
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

	MyQueue& operator=(std::initializer_list<T>&& list)			// перегрузка оператора присваивания
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


	MyQueue& operator=(MyQueue&& other)		// оператор перемещения
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
	*  методы
	*/

	iterator begin() const
	{
		return iterator(m_begin, this);
	}
	iterator end() const
	{
		return iterator(m_end, this);
	}

	void push(const T& value)			// присвоить новое значение с помощью push()
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
			m_begin = m_begin % m_cap;		// если за пределы, закольцовываем / сбрасывается на ноль
			m_size--;
			return temp;
		}
		throw "empty queue";
	}

	T& operator[](int index)
	{
		if ( index >= 0 && index < m_size)
		{
			int i = ( m_begin + index ) % m_cap;		// вычисляем адрес в кольцевом
			return m_p[ i ];
		}
		throw "invalid index";
	}
};

