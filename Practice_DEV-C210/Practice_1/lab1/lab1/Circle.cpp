#include "Circle.h"
#include<iostream>

#define PI 3.14


/*
*	������������
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
*	������
*/
double Circle::Area() const
{  
    return ( PI* m_radius * m_radius);
}

Shape* Circle::Clone() const
{
    return new Circle(*this);   // ������ ��������� ����������  Print �����������
}

std::ostream& Circle::Print(std::ostream& os) const  // ! Done  
{
    os << "\n����������: \n"
        << "x: " << m_x << "\n"
        << "y: " << m_y << "\n"
        << "�������: " << this->Area() << std::endl;
    return os;
}

/*
*	����������
*/
bool Circle::operator==(const Shape& object) const
{
    if ( this->Shape::operator==(object) )
    {
        if ( typeid( object ) == typeid( Circle ) )     // ��������� ������� ��������
        {
            /* const Circle& c = static_cast< const Circle& >(object);
             return (c.m_radius == this->m_radius);*/
             // ������ �������
            return  ( static_cast< const Circle& >( object ).m_radius == this->m_radius );
        }
    }
    return false;
}

