#include "Shape.h"
#include<iostream>

static const char* arr[] = { "", "RED", "YELLOW", "GREEN", "BLACK" };	// для текстового обозначения перечисления  Ecolor

/*
*	Конструкторы
*/
Shape::Shape() : color(Shape::BLACK)
{

}

Shape::Shape(eColor color) :color(color)
{

}

Shape::~Shape()
{
	std::cout << "Shape destructor!" << std::endl;
}


/*
*	методы
*/


/*
*	перегрузки
*/
std::ostream& Shape::Print(std::ostream& os) const
{
	os << arr[ color ];
	return os;
}

bool Shape::operator==(const Shape& object) const
{
	return ( this->color == object.color );
}