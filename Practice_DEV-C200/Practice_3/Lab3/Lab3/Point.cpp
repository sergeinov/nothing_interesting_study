#include "Point.h"

// конструктор
Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
};

// конструктор копирования
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
Point& Point::operator+=(const int number)
{
	m_x = m_x + number;
	m_y = m_y + number;
	return *this;

};

//Перегрузка оператора +
Point& Point::operator+(const Point& RightObject)
{
	*this += RightObject;	// вызов перегруженного метода +=
	return *this;
};
Point& Point::operator+(const int number)
{
	this->m_x += number;
	this->m_y += number;
	return *this;
};