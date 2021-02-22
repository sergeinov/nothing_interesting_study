#include "MyVector.h"
#include<cstdlib>
/*
*	конструкторы
*/
template<typename T>
inline MyVector<T>::MyVector() : m_p(nullptr), m_n(0), m_cap(0) { };

template<typename T>
inline MyVector<T>::MyVector(size_t n)
{
	m_cap = m_n = n;										// увеличиваем  объем и размер вектора
	m_p = static_cast< T* >( malloc(n * sizeof(T)) );		// создаем сырую память
	for ( size_t i = 0; i < n; i++ )						// создаем объекты в памяти
	{
		new( &m_p[ i ] )T();								// для каждого вызывается дефолтный конструктор
	}
};

template<typename T>
MyVector<T>::MyVector(size_t n, const T* data)
{
	m_cap = m_n = n;										// увеличиваем  объем и размер вектора
	m_p = static_cast< T* >( malloc(n * sizeof(T)) );		// создаем сырую память
	for ( size_t i = 0; i < n; i++ )						// создаем объекты в памяти
	{
		new( &m_p[ i ] )T(data);							// placement New
	}

}

template<typename T>
MyVector<T>::~MyVector()
{
	for ( size_t i = 0; i < m_n; i++ )
	{
		m_p[ i ].~T();				// вызов деструкторов для каждого элемента вектора
	}
	free(m_p);						// очистка сырой памяти
}



/*
*	методы
*/
template<typename T>
void MyVector<T>::clear()
{
	for ( size_t i = 0; i < m_n; i++ )
	{
		m_p[ i ].~T();
	}
	m_n = 0;							// обнулили размер
}

template<typename T>
size_t MyVector<T>::size() const
{
	return m_n;
}


/*
*	перегрузки
*/

