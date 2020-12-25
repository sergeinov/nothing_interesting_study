#include "Circle.h"

Circle::Circle()
{
	m_diametr = 0;
	m_color = BLACK;
}

Circle::~Circle() {};

Circle::Circle(double diametr, eColor color)
{
	m_diametr = diametr;
	m_color = color;
}

const double Circle::GetDiametr() const
{
	return m_diametr;
}

const double Circle::GetColor() const
{
	return m_color;
}

void Circle::SetColor(eColor color)
{
	m_color = color;
};