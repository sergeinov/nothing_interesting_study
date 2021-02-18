#include "Shape.h"
#include<iostream>



/*
*	������������
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
*	������
*/


/*
*	����������
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