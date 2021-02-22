#pragma once


template<typename T>class MyVector
{
private:
	T* m_p;
	size_t m_n;
	size_t m_cap;

public:
	/*
	*	������������
	*/
	MyVector();
	MyVector(size_t n);
	MyVector(size_t n, const T* data);		// ����������� ������ ��� n ���������
	~MyVector();

	// MyVector(const MyVector& other);			// ����������� �����������
	// MyVector(const MyVector&& other);		// ����������� ���������� move

	/*
	*	������
	*/
	void clear();
	size_t size() const;


	/*
	*	����������
	*/
	//MyVector& operator=(const T& object);			// �������� ������������/ �����������
	//MyVector& operator=(T&& object;)				// std::move()



};

