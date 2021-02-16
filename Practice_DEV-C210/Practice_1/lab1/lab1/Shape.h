#pragma once
#include<iostream>

//

class Shape
{
public:
	enum eColor { BLACK = 1, YELLOW, GREEN, BLUE };
private:
	eColor color;
public:
	
/*
*	������������
*/
	Shape();
	Shape(eColor color);
	virtual ~Shape();

/*
*	������
*/
	virtual double Area() const  = 0;
	virtual Shape* Clone() const = 0;
	virtual std::ostream& Print(std::ostream& os) const = 0;
	eColor GetColor() const { return color; }
/*
*	����������
*/
	virtual bool operator==(const Shape&) const = 0;


};

