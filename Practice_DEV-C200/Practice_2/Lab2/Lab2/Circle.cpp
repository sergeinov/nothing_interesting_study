#include <iostream>
#include "Circle.h"


// конструкторы
Circle::Circle() : Shape(RED)
{
	m_x = 0;
	m_y = 0;
	m_diametr = 0;
};
Circle::Circle(int x, int y, double diametr, eColor color) : Shape(color)
{
	m_diametr = diametr;
	m_x = x;
	m_y = y;
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

const double Circle::GetDiametr() const
{
	return m_diametr;
};

const char* Circle::GetColor() const
{
	static const char* arrColor[] = { "0", "RED", "YELLOW", "GREEN", "BLACK" };
	return arrColor[m_color];
};

void Circle::WhereAmI() const
{
	std::cout << "Now I am in class Circle" << std::endl;
};

void Circle::WhereAmIVirtual() const
{
	std::cout << "Now I am in class Circle virtual" << std::endl;
};


// перегрузка чистого вертуального метода
// метод изменения размера фигуры
//void Circle::Inflate(int quantity)
//{
//	m_diametr += quantity;
//};