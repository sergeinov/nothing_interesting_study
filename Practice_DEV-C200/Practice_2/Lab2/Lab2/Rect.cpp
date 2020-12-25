#include "Rect.h"
// конструктор
Rect::Rect() { m_left = 0; m_right = 0; m_top = 0; m_bottom = 0; m_color = BLACK; };
Rect::Rect(int left, int right, int top, int bottom, eColor color)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
	m_color = color;
};

// метод дает цвет фигуре
void Rect::SetColor(eColor color)
{
	m_color = color;
};

// метод получения цвета
const char* Rect::GetColor() const
{
	static const char* arrColor[] = { "0", "RED", "YELLOW", "GREEN", "BLACK" };
	return arrColor[m_color];
	
};