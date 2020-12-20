#pragma once
#include <iostream>

class Rect{

	int m_left, m_right, m_top, m_bottom;

	public:
		
		// �����������  �� ���������
		Rect() { m_left = 0; m_right = 0; m_top = 0; m_bottom = 0; };

		// ����������� � �����������
		Rect( unsigned int left, unsigned int right, unsigned int top, unsigned int bottom)
		{
			if ((left + right + top + bottom) < 4)
			{
				std::cout << "������! �������� �������� ���������� ������������" <<  this <<std::endl;
			}

			if ((left + top + right > bottom) && (top + right + bottom) > (left && right + bottom + left > top))
			{
				m_left = left;
				m_right = right;
				m_top = top;
				m_bottom = bottom;
			}
			else {
				std::cout << "������! �������� �������� ���������� ������������: " << this << std::endl;
			}
		};

		// ����������� �����������
		Rect(const Rect& copyToOtherClass);

		// ����� ����������� ������� ������������ �� ��������
		void InflateRect(unsigned int left, unsigned int right, unsigned int top, unsigned int bottom);

		void InflateRect(unsigned int leftRight = 1, unsigned int topBottom = 1);

		// �����  ������������� �������� ���� ������
		void SetAll(int left, int right, int top, int bottom);

		// ����� ��������� �������� ����
		const int* Get() ;
		
		// ����� ���������� ������ ��������������
		Rect& BoundingRect(const Rect* rect1, const Rect* rect2);
};

