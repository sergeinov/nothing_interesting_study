#include "Rect.h"
#include<iostream>

/*
*	������������
*/
Rect::Rect() : m_left(0), m_right(0), m_top(0), m_bottom(0)
{

}

Rect::Rect(int left, int right, int top, int bottom, Shape::eColor color) :
    m_left(left), m_right(right), m_top(top), m_bottom(bottom), Shape(color)
{

}

Rect::~Rect()
{
    std::cout << "virtual Destructor Rect!" << std::endl;
}

/*
*	������
*/
double Rect::Area() const
{
    return (m_left * m_top);
}

Shape* Rect::Clone() const
{
    return new Rect(*this);
}

std::ostream& Rect::Print(std::ostream& os)   const  // ! Done
{
    os << "\nRect: \n"
        << "left: " << m_left<< "\n"
        << "right: " << m_right << "\n"
        << "top: " << m_top << "\n"
        << "bottom: " << m_bottom 
        << << std::endl;
        Shape::Print(os) << std::endl;
    return os;
}


/*
*	����������
*/

bool Rect::operator==(const Shape& r) const
{
    // ��������� � ������� dynamic_cast
    if ( this->Shape::operator==(r) )
    {
        if ( const Rect* pR = dynamic_cast< const Rect* >( &r ) )   // ���� ���������� dynamic_cast ��������, �� ������ ����� ������� // ���� ��� �� 0
        {
            return ( ( pR->m_right - pR->m_left ) == ( this->m_right - this->m_left ) ) && ((pR->m_top - pR->m_bottom) == (this->m_top - this->m_bottom));  // ! Done
        }
    }
    return false;
}
