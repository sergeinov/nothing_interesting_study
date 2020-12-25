#pragma once
#include "Shape.h"
class Rect :
    public Shape
{
public:
	// конструктор  по умолчанию
	Rect();
	// конструктор с параметрами
	Rect(int left, int right, int top, int bottom, eColor color);

	// деструктор
	~Rect() {};

	// установить цвет
	void SetColor(eColor color);

	const char* GetColor() const;

private:
	int m_left, m_right, m_top, m_bottom;
	eColor m_color;
};

