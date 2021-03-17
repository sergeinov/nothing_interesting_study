#pragma once
#include"Shape.h"

class Rect: public Shape
{
private:
	int m_left, m_right, m_top, m_bottom;
public:
/*
*	Конструкторы
*/
	Rect();
	Rect(int left, int right, int top, int bottom, Shape::eColor color);
	virtual ~Rect();

/*
*	методы
*/
	void Normalize();		// корректировка значений при создании объекта
	void InflateRect(int left, int riht, int top, int bottom);

	virtual double Area() const;				// площадь фигуры
	virtual Shape* Clone() const;
	virtual std::ostream& Print(std::ostream& os) const;

	//void GetAllFields(int* x, int* x2, int* y, int* y2);
	//void SetAllFields(int left, int right, int top, int bottom);
	const char* GetColor();

/*
*	перегрузки
*/
	//virtual Shape& operator=(const Shape& other);			// оператор копирования
	virtual bool operator==(const Shape& r) const;

};


