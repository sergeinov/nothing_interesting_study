#include "Rect.h"
#include<iostream>

/*
*	Конструкторы
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
*	методы
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
    os << "\nСтороны прямоугольника: \n"
        << "Слева: " << m_left<< "\n"
        << "Справа: " << m_right << "\n"
        << "Вверх: " << m_top << "\n"
        << "Низ: " << m_bottom << std::endl;
    return os;
}


/*
*	перегрузки
*/

bool Rect::operator==(const Shape& r) const
{
    // сравнение с помощью dynamic_cast
    if ( this->Shape::operator==(r) )
    {
        if ( const Rect* pR = dynamic_cast< const Rect* >( &r ) )   // если приведение dynamic_cast возможно, то вернет адрес объекта // если нет то 0
        {
            return ( ( pR->m_right - pR->m_left ) == ( this->m_right - this->m_left ) ); //&& (() == ());  // TODO сравнить стороны
        }
    }
    return false;
}
