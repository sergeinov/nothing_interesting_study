#pragma once
#include <iostream>

class Rect{

	int m_left, m_right, m_top, m_bottom;

	public:
		
		// конструктор  по умолчанию
		Rect() { m_left = 0; m_right = 0; m_top = 0; m_bottom = 0; };

		// конструктор с параметрами
		Rect( unsigned int left, unsigned int right, unsigned int top, unsigned int bottom)
		{
			if ((left + right + top + bottom) < 4)
			{
				std::cout << "ќшибка! неверные значени€ параметров  онструктора" <<  this <<std::endl;
			}

			if ((left + top + right > bottom) && (top + right + bottom) > (left && right + bottom + left > top))
			{
				m_left = left;
				m_right = right;
				m_top = top;
				m_bottom = bottom;
			}
			else {
				std::cout << "ќшибка! неверные значени€ параметров  онструктора: " << this << std::endl;
			}
		};

		// конструктор копировани€
		Rect(const Rect& copyToOtherClass);

		// метод увеличивает сторону треугольника на значение
		void InflateRect(unsigned int left, unsigned int right, unsigned int top, unsigned int bottom);

		void InflateRect(unsigned int leftRight = 1, unsigned int topBottom = 1);

		// метод  устанавливает значение пол€ класса
		void SetAll(int left, int right, int top, int bottom);

		// метод позвол€ет получить поле
		const int* Get() ;
		
		// метод возвращает объект пр€моугольника
		Rect& BoundingRect(const Rect* rect1, const Rect* rect2);
};

