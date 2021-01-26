#include "Circle.h"
#include<iostream>

// конструкторы
// А Point вызовет конструктор по умолчанию?
Circle::Circle() : m_radius(0) {};     // point  конструктор по умолчанию
Circle::Circle(double radius, const Point& point) : m_radius(radius), point(point) {}; // ?
Circle::~Circle()
{
	std::cout << "Now I am in Circle's destructor!" << std::endl;
};

// перегрузки


// методы