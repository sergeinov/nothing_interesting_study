#include <iostream>
#include "Rect.h"


// конструкторы
Rect::Rect() : Shape(RED) { m_left = 0; m_right = 0; m_top = 0; m_bottom = 0; };
Rect::Rect(int left, int right, int top, int bottom, eColor color) : Shape(color)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;

	Normalize();
};

// коструктор копирования
Rect::Rect(const Rect& copyToOtherClass)
{
	m_left = copyToOtherClass.m_left;
	m_right = copyToOtherClass.m_right;
	m_top = copyToOtherClass.m_top;
	m_bottom = copyToOtherClass.m_bottom;
}
Rect::Rect(const Circle& copyToOther)
{
	m_left += copyToOther.GetDiametr();
	m_right += copyToOther.GetDiametr();
	m_top += copyToOther.GetDiametr();
	m_bottom += copyToOther.GetDiametr();
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

// метод увеличивает сторону прямоугольникана на значение
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

void Rect::WhereAmI() const
{
	std::cout << "Now I am in class Rect" << std::endl;
};

void Rect::WhereAmIVirtual() const
{
	std::cout << "Now I am in class Rect virtual" << std::endl;
};

// перегрузка чистого вертуального метода
// метод изменения размера фигуры
// void Rect::Inflate(int quantity)
//{
//	m_left -= quantity;
//	m_right += quantity;
//	m_top += quantity;
//	m_bottom -= quantity;
//
//	Normalize();
//};
