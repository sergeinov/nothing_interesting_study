#include "Circle.h"
#include<iostream>

// ������������
// � Point ������� ����������� �� ���������?
Circle::Circle() : m_radius(0) {};     // point  ����������� �� ���������
Circle::Circle(double radius, const Point& point) : m_radius(radius), point(point) {}; // ?
Circle::~Circle()
{
	std::cout << "Now I am in Circle's destructor!" << std::endl;
};

// ����������


// ������