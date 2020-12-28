#include <iostream>
#include "Rect.h"


// конструкторы
Rect::Rect() { m_left = 0; m_right = 0; m_top = 0; m_bottom = 0; m_color = BLACK; };
Rect::Rect(int left, int right, int top, int bottom, eColor color)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
	m_color = color;

	Normalize();
};

// деструктор
Rect::~Rect()
{
	std::cout << "Now I am in Rect's destructor!" << std::endl;
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
};

// метод увеличивает сторону треугольникана на значение
void Rect::InflateRect(int left, int right, int top, int bottom)
{
	m_left -= left;
	m_right += right;
	m_top += top;
	m_bottom -= bottom;

	Normalize();
};

void Rect::SetAll(int left, int right, int top, int bottom)
{
	this->m_left = left;
	this->m_right = right;
	this->m_top = top;
	this->m_bottom = bottom;

	Normalize();
};

// метод дает цвет фигуре
void Rect::SetColor(eColor color)
{
	m_color = color;
};

void Rect::GetAll(int* x1, int* x2, int* y1, int* y2) const
{
	*x1 = m_left;
	*x2 = m_right;
	*y1 = m_top;
	*y2 = m_bottom;
};

// метод получения цвета
const char* Rect::GetColor() const
{
	static const char* arrColor[] = { "0", "RED", "YELLOW", "GREEN", "BLACK" };
	return arrColor[m_color];

};

void Rect::WhereAmI()
{
	std::cout << "Now I am in class Rect" << std::endl;
};

void Rect::WhereAmIVirtual()
{
	std::cout << "Now I am in class Rect virtual" << std::endl;
};