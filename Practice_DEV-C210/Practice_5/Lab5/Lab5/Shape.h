#pragma once
#include<iostream>

static const char* arr[] = { "", "RED", "YELLOW", "GREEN", "BLACK" };	// ��� ���������� ����������� ������������  Ecolor

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
	virtual Shape& operator=(const Shape& other) { 
		this->color = other.color;
		return *this; 
	};		
	
	//���������� ��������� ������������ = ��� �������
	virtual bool operator==(const Shape&) const = 0;

	friend std::ifstream& operator>>(std::ifstream& iff2, Shape::eColor& color); // ��� � �����  ������������ eColor

};

