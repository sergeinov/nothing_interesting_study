#pragma once


template<typename T>class MyVector
{
private:
	T* m_p;
	size_t m_n;
	size_t m_cap;

public:
	/*
	*	конструкторы
	*/
	MyVector();
	MyVector(size_t n);
	MyVector(size_t n, const T* data);		// присваиваем данные для n элементов
	~MyVector();

	// MyVector(const MyVector& other);			// конструктор копирования
	// MyVector(const MyVector&& other);		// конструктор пермещения move

	/*
	*	методы
	*/
	void clear();
	size_t size() const;


	/*
	*	перегрузки
	*/
	//MyVector& operator=(const T& object);			// оператор присваивания/ копирования
	//MyVector& operator=(T&& object;)				// std::move()



};

