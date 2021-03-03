#include "Point.h"
#include<iostream>

// конструкторы
Point::Point() : m_x(0), m_y(0) {};
Point::Point(int x, int y) : m_x(x), m_y(y) {};
//Point::~Point() { std::cout << "I am Point destructor!" << std::endl; }


// перегрузки
bool Point::operator==(const Point& point) const
{
	return (this->m_x == point.m_x && this->m_y == point.m_y);
}

bool Point::operator<(const Point& point) const
{
	return (this->m_x < point.m_x);
}
;

// методы

