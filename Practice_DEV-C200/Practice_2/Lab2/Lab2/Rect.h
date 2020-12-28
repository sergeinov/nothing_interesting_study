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
	virtual ~Rect();

	// метод нормализует прямоуголик при не правилом вводе пользователем параметров
	void Normalize();
	// метод увеличивает сторону прямоугольника на значение
	void InflateRect(int left, int right, int top, int bottom);

	// метод  устанавливает значение поля класса
	void SetAll(int left, int right, int top, int bottom);
	// установить цвет
	void SetColor(eColor color);

	// метод позволяет получить поле
	void GetAll(int* x1, int* x2, int* y1, int* y2) const;

	// метод позволяет получить цвет
	const char* GetColor() const;

	void WhereAmI();

	virtual void WhereAmIVirtual();

private:
	int m_left, m_right, m_top, m_bottom;
	eColor m_color;
};

