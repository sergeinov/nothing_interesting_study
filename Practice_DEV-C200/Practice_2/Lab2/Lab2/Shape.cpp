#include <iostream>
#include "Shape.h"


Shape::Shape() { m_color = BLACK; };
Shape::Shape(eColor color)
{
	m_color = color;
}
Shape::~Shape() 
{
	std::cout << "Now I am in Shape's destructor!" << std::endl;
};


void Shape::GetShape()
{
	std::cout << "I am shape figure" << std::endl;
};

void Shape::WhereAmI() const
{
	std::cout << "Now I am in class Shape" << std::endl;
};

void Shape::WhereAmIVirtual() const
{
	std::cout << "Now I am in class Shape virtual" << std::endl;
};