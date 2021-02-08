#include "Circle.h"
#include<iostream>

// ������������
// � Point ������� ����������� �� ���������?
Circle::Circle() : m_radius(0) {};     // point  ����������� �� ���������
Circle::Circle(double radius, const Point& point, eColor color) : m_radius(radius), point(point), color(color) {}; // ?
Circle::Circle(double radius, int x, int y, eColor color) : m_radius(radius), point(x, y), color(color) {};
Circle::~Circle()
{
	std::cout << "Now I am in Circle's destructor!" << std::endl;
};

// ����������
bool Circle::operator==(const Circle& figure) const
{
	return (this->m_radius == figure.m_radius && this->point == figure.point);

}
bool Circle::operator<(const Circle& figure) const
{
	return ((this->m_radius < figure.m_radius)? true : false);
}
// ������