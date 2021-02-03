#pragma once

#include"Point.h"
#include<iostream>

class Circle
{
public:
	enum eColor { RED = 1, YELLOW, GREEN, BLACK };
private:
	double m_radius;
	Point point;
	eColor color;
public:
	Circle();
	Circle(double radius, const Point& point, eColor color);
	Circle(double radius, int x, int y, eColor color);
	virtual ~Circle();

	//����������� �����������
	// ����������� ����������� ���������, ����� ���� ����������� ���������� ������ ��� ��������� ����

	// ����������
	bool operator==(const Circle& figure) const;
	friend std::ostream& operator<<(std::ostream& os, Circle& object);	// ����� �������

	// ������

};

