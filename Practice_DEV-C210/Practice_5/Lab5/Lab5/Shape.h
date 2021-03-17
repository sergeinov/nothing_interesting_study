#pragma once
#include<iostream>

static const char* arr[] = { "", "RED", "YELLOW", "GREEN", "BLACK" };	// дл€ текстового обозначени€ перечислени€  Ecolor

class Shape
{
public:
	enum eColor { BLACK = 1, YELLOW, GREEN, BLUE };
private:
	eColor color;
public:
	
/*
*	 онструкторы
*/
	Shape();
	Shape(eColor color);
	virtual ~Shape();

/*
*	методы
*/
	virtual double Area() const  = 0;
	virtual Shape* Clone() const = 0;
	virtual std::ostream& Print(std::ostream& os) const = 0;
	eColor GetColor() const { return color; }
/*
*	перегрузки
*/
	virtual Shape& operator=(const Shape& other) { 
		this->color = other.color;
		return *this; 
	};		
	
	//ѕерегрузка оператора присваивани€ = дл€ обьекта
	virtual bool operator==(const Shape&) const = 0;

	friend std::ifstream& operator>>(std::ifstream& iff2, Shape::eColor& color); // дл€ с типом  перечислени€ eColor

};

