#pragma once

#include"Point.h"

class Circle
{
private:
	double m_radius;
	Point point;
public:
	Circle();
	Circle(double radius, const Point& point);
	virtual ~Circle();

	//����������� �����������
	// ����������� ����������� ���������, ����� ���� ����������� ���������� ������ ��� ��������� ����

};

