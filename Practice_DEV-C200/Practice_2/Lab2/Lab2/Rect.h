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
	~Rect() {};

	// ���������� ����
	void SetColor(eColor color);

	const char* GetColor() const;

private:
	int m_left, m_right, m_top, m_bottom;
	eColor m_color;
};

