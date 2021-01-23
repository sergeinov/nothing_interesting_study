#include "Point.h"

// конструктор
Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
};

// конструктор копирования
//Point::Point(const Point& otherClass)
//{
//	m_x = otherClass.m_x;
//	m_y = otherClass.m_y;
//};

// перегрузка оператора +=
Point& Point::operator+=(const Point& RightObject)
{
	this->m_x = this->m_x + RightObject.m_x;
	this->m_y = this->m_y + RightObject.m_y;
	return *this;

};
Point& Point::operator+=(const int value)
{
	this->m_x = this->m_x + value;
	this->m_y = this->m_y + value;
	return *this;

};

//Перегрузка оператора +
Point Point::operator+(const Point& RightObject) const
{
	return Point(m_x + RightObject.m_x, m_y + RightObject.m_y); // возвращаем копию обекта со сложенными параметрами
	// вызов деструктора
};
Point Point::operator+(const int value) const
{
	/*this->m_x += value;
	this->m_y += value;
	return *this;*/

	return Point(m_x + value, m_y + value); // возвращаем копию обекта со сложенными параметрами
	// вызов деструктора
};

// Перегрузика унарного оператора - (-pt1;)
Point Point::operator-() const
{
	Point point(-m_x, -m_y);
	/*this->m_x = -m_x;
	this->m_y = -m_y;*/
	return point;
};

// Перегрузика унарного оператора + (+pt1;)
const Point& Point::operator+() const
{
	return *this;
};