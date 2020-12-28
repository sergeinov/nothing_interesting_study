#pragma once
#include "Shape.h"
class Rect :
    public Shape
{
public:
	// �����������  �� ���������
	Rect();
	// ����������� � �����������
	Rect(int left, int right, int top, int bottom, eColor color);

	// ����������
	virtual ~Rect();

	// ����� ����������� ����������� ��� �� �������� ����� ������������� ����������
	void Normalize();
	// ����� ����������� ������� �������������� �� ��������
	void InflateRect(int left, int right, int top, int bottom);

	// �����  ������������� �������� ���� ������
	void SetAll(int left, int right, int top, int bottom);
	// ���������� ����
	void SetColor(eColor color);

	// ����� ��������� �������� ����
	void GetAll(int* x1, int* x2, int* y1, int* y2) const;

	// ����� ��������� �������� ����
	const char* GetColor() const;

	void WhereAmI();

	virtual void WhereAmIVirtual();

private:
	int m_left, m_right, m_top, m_bottom;
	eColor m_color;
};

