#pragma once
#include <iostream>

class Rect{

	int m_left, m_right, m_top, m_bottom;

	public:
		
		// конструктор  по умолчанию
		Rect();

		// конструктор с параметрами
		Rect(int left, int right, int top, int bottom);

		// деструктор
		~Rect() {};

		// конструктор копирования
		Rect(const Rect& copyToOtherClass);

		// метод нормализует прямоуголик при не правилом вводе пользователем параметров
		void Normalize();

		// метод увеличивает сторону треугольника на значение
		void InflateRect(int left,int right,int top,int bottom);
		void InflateRect(int leftRight = 1, int topBottom = 1);

		// метод  устанавливает значение поля класса
		void SetAll(int left, int right, int top, int bottom);

		// метод позволяет получить поле
		const int* Get();
		void GetAll(int* x1, int* x2, int* y1, int* y2);

		// метод возвращает объект прямоугольника
		Rect& BoundingRect(const Rect* rect1, const Rect* rect2);
};

