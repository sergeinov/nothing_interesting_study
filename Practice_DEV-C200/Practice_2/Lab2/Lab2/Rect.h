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
	// коструктор копирования
	Rect(const Rect& copyToOtherClass);
	//Rect(const Circle& copyToOther);

	// деструктор
	virtual ~Rect();

	// метод нормализует прямоуголик при не правильном вводе пользователем параметров
	void Normalize();
	// метод увеличивает сторону прямоугольника на значение
	void InflateRect(int left, int right, int top, int bottom);

	// метод  устанавливает значение поля класса
	void SetAll(int left, int right, int top, int bottom);

	// метод позволяет получить поле
	void GetAll(int* x1, int* x2, int* y1, int* y2) const;

	// метод позволяет получить цвет
	const char* GetColor() const;

	void WhereAmI() const;

	virtual void WhereAmIVirtual() const;

	// перегрузка чистого вертуального метода
	// метод изменения размера фигуры
	//virtual void Inflate(int quantity);

private:
	int m_left, m_right, m_top, m_bottom;
};

