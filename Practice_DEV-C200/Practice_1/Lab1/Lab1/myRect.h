#pragma once
#include <iostream>

class Rect{

	int m_left, m_right, m_top, m_bottom;

	public:
		
		// �����������  �� ���������
		Rect();

		// ����������� � �����������
		Rect(int left, int right, int top, int bottom);

		// ����������
		~Rect() {};

		// ����������� �����������
		Rect(const Rect& copyToOtherClass);

		// ����� ����������� ����������� ��� �� �������� ����� ������������� ����������
		void Normalize();

		// ����� ����������� ������� ������������ �� ��������
		void InflateRect(int left,int right,int top,int bottom);
		void InflateRect(int leftRight = 1, int topBottom = 1);

		// �����  ������������� �������� ���� ������
		void SetAll(int left, int right, int top, int bottom);

		// ����� ��������� �������� ����
		const int* Get();
		void GetAll(int* x1, int* x2, int* y1, int* y2);

		// ����� ���������� ������ ��������������
		Rect& BoundingRect(const Rect* rect1, const Rect* rect2);
};

