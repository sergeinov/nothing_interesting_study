#pragma once

#include"Shape.h"
#include"Rect.h"

class Circle: public Shape
{
private:
	int m_x;
	int m_y;
	double m_radius;
public:

/*
*	������������
*/
	Circle();
	Circle(int x, int y, double radius, eColor color);
	virtual ~Circle();
/*
*	������
*/
	virtual double Area() const;				// ������� ������
	virtual Shape* Clone() const;
	virtual std::ostream& Print(std::ostream& os) const;

	//const double GetRadius() const;
	//void SetPosition(int x, int y);
	//void SetRadius(double r);

/*
*	����������
*/
	virtual Shape& operator=(const Shape& other);				// �������� �����������
	virtual bool operator==(const Shape&) const;



};

