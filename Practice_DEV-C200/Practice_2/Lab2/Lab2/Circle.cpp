#include <iostream>
#include "Circle.h"


// конструкторы
Circle::Circle()
{
	m_diametr = 0;
	m_color = BLACK;
};
Circle::Circle(int x, int y, double diametr, eColor color)
{
	m_diametr = diametr;
	m_x = x;
	m_y = y;
	m_color = color;
};

// деструктор
Circle::~Circle() 
{
	std::cout << "Now I am in Circle's destructor!" << std::endl;
};

void Circle::SetPosition(int x, int y)
{
	m_x = x;
	m_y = y;
};

void Circle::SetDiametr(double diametr)
{
	m_diametr = diametr;
};
void Circle::SetColor(eColor color)
{
	m_color = color;
};

const double Circle::GetDiametr() const
{
	return m_diametr;
};

const char* Circle::GetColor() const
{
	static const char* arrColor[] = { "0", "RED", "YELLOW", "GREEN", "BLACK" };
	return arrColor[m_color];
};

void Circle::WhereAmI()
{
	std::cout << "Now I am in class Circle" << std::endl;
};

void Circle::WhereAmIVirtual()
{
	std::cout << "Now I am in class Circle virtual" << std::endl;
};