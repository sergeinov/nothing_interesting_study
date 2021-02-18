#include "Circle.h"
#include<iostream>

#define PI 3.14


/*
*	Конструкторы
*/
Circle::Circle() : m_x(0), m_y(0), m_radius(0)
{
}

Circle::Circle(int x, int y, double radius, eColor color) : 
    m_x(x), m_y(y), m_radius(radius), Shape(color)
{
}

Circle::~Circle()
{
    std::cout << "virtual Destructor Circle!" << std::endl;
}

/*
*	методы
*/
double Circle::Area() const
{  
    return ( PI * ( m_radius * m_radius));
}

Shape* Circle::Clone() const
{
    return new Circle(*this);   // почему требовало перегрузку  Print виртуальный
}

std::ostream& Circle::Print(std::ostream& os) const  // ! Done  
{
    os << "\nCircle:\n"
        << "x: " << m_x << "\n"
        << "y: " << m_y << "\n"
        << "Radius: " << m_radius << "\n"
        << "Area: " << this->Area() 
        << std::endl;
        Shape::Print(os) << std::endl;
    return os;
}

/*
*	перегрузки
*/
Shape& Circle::operator=(const Circle& other)                // оператор копирования
{
    this->m_x = other.m_x;
    this->m_y = other.m_y;
    this->m_radius = other.m_radius;
    // ? цвет
    return *this;
}

bool Circle::operator==(const Shape& object) const
{
    if ( this->Shape::operator==(object) )
    {
        if ( typeid( object ) == typeid( Circle ) )     // сравнения адресов объектов
        {
            /* const Circle& c = static_cast< const Circle& >(object);
             return (c.m_radius == this->m_radius);*/
             // второй вариант
            return  ( static_cast< const Circle& >( object ).m_radius == this->m_radius );
        }
    }
    return false;
}

