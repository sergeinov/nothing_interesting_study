#include <iostream>
#include "Shape.h"


Shape::Shape() {};
Shape::~Shape() 
{
	std::cout << "Now I am in Shape's destructor!" << std::endl;
};


void Shape::GetShape()
{
	std::cout << "I am shape figure" << std::endl;
};

void Shape::WhereAmI()
{
	std::cout << "Now I am in class Shape" << std::endl;
};

void Shape::WhereAmIVirtual()
{
	std::cout << "Now I am in class Shape virtual" << std::endl;
};