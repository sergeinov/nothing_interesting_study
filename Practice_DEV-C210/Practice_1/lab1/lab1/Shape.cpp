#include "Shape.h"
#include<iostream>

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
bool Shape::operator==(const Shape& object) const
{
	return ( this->color == object.color );
}