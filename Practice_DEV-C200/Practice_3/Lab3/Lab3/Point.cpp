#include "Point.h"

// �����������
Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
};

// ����������� �����������
Point::Point(const Point& otherClass)
{
	m_x = otherClass.m_x;
	m_y = otherClass.m_y;
};

// ���������� ��������� +=
Point& Point::operator+=(const Point& RightObject)
{
	m_x = m_x + RightObject.m_x;
	m_y = m_y + RightObject.m_y;
	return *this;

};
Point& Point::operator+=(const int number)
{
	m_x = m_x + number;
	m_y = m_y + number;
	return *this;

};

//���������� ��������� +
Point& Point::operator+(const Point& RightObject)
{
	*this += RightObject;	// ����� �������������� ������ +=
	return *this;
};
Point& Point::operator+(const int number)
{
	this->m_x += number;
	this->m_y += number;
	return *this;
};