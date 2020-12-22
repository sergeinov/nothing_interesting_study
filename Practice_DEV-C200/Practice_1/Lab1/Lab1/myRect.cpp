#include "myRect.h"

// Задание 1а
// конструктор
Rect::Rect() { m_left = 0; m_right = 0; m_top = 0; m_bottom = 0; };
Rect::Rect(int left, int right, int top, int bottom)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;

	Normalize();
};

// метод нормализации параметров от пользователя
void Rect::Normalize()
{
	if (m_left > m_right)
	{
		int temp = m_left;
		m_left = m_right;
		m_right = temp;
	}

	if (m_bottom > m_top)
	{
		int temp = m_bottom;
		m_bottom = m_top;
		m_top = temp;
	}
}

// Задание 1в
// метод увеличивает сторону треугольникана на значение
void Rect::InflateRect(int left,int right,int top,int bottom)
{
	m_left -= left;
	m_right += right;
	m_top += top;
	m_bottom -= bottom;

	Normalize();
}

// Задание 2а
// коструктор копирования
Rect::Rect(const Rect& copyToOther)
{
	m_left = copyToOther.m_left;
	m_right = copyToOther.m_right;
	m_top = copyToOther.m_top;
	m_bottom = copyToOther.m_bottom;
}

// Задание 2б
void Rect::InflateRect(int leftRight, int topBottom)
{
	m_left -= leftRight;
	m_right += leftRight;
	m_top += topBottom;
	m_bottom -= topBottom;

	Normalize();
};


//Задание 3
void Rect::SetAll(int left, int right, int top, int bottom)
{
	this->m_left = left;
	this->m_right = right;
	this->m_top = top;
	this->m_bottom = bottom;

	Normalize();
}


const int* Rect::Get()
{
	int* arr = new int[4];
	arr[0] = this->m_left;
	arr[1] = this->m_right;
	arr[2] = this->m_bottom;
	arr[3] = this->m_bottom;

	return arr;
};

void Rect::GetAll(int* x1, int* x2, int* y1, int* y2)
{
	*x1 = m_left;
	*x2 = m_right;
	*y1 = m_top;
	*y2 = m_bottom;
};

//Задание 4б
Rect& Rect::BoundingRect(const Rect* rect1, const Rect* rect2) 
{
	
	Rect* p = new Rect;		// вызов конструктора по умолчанию

	p->m_left = rect1->m_left + rect2->m_left;
	p->m_right = rect1->m_right + rect2->m_right;
	p->m_top = rect1->m_top + rect2->m_top;
	p->m_bottom = rect1->m_bottom + rect2->m_bottom;

	return *p;
};