#include "Point.h"
#include<iostream>

// конструкторы
Point::Point() : m_x(0), m_y(0), m_color(BLACK) {};
Point::Point(int x, int y, eColor color) : m_x(x), m_y(y), m_color(color) {};
Point::~Point() { std::cout << "I am Point destructor!" << std::endl; }


// перегрузки


// методы