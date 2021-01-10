#include "Point.h"

// конструктор
Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
};

// конструктор копировани€
Point::Point(const Point& otherClass)
{
	m_x = otherClass.m_x;
	m_y = otherClass.m_y;
};

// перегрузка оператора +=
Point& Point::operator+=(const Point& RightObject)
{
	m_x = m_x + RightObject.m_x;
	m_y = m_y + RightObject.m_y;
	return *this;

};
Point& Point::operator+=(const int value)
{
	m_x = m_x + value;
	m_y = m_y + value;
	return *this;

};

//ѕерегрузка оператора +
Point& Point::operator+(const Point& RightObject)
{
	*this += RightObject;	// вызов перегруженного метода +=
	return *this;
};
Point& Point::operator+(const int value)
{
	this->m_x += value;
	this->m_y += value;
	return *this;
};

// ѕерегрузика унарного оператора - (-pt1;)
Point& Point::operator-()
{
	this->m_x = -m_x;
	this->m_y = -m_y;
	return *this;
};

// ѕерегрузика унарного оператора + (+pt1;)
Point& Point::operator+()
{
	return *this;
};