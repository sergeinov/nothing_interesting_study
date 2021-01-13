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
	// ���������� �����������
	Rect(const Rect& copyToOtherClass);
	//Rect(const Circle& copyToOther);

	// ����������
	virtual ~Rect();

	// ����� ����������� ����������� ��� �� ���������� ����� ������������� ����������
	void Normalize();
	// ����� ����������� ������� �������������� �� ��������
	void InflateRect(int left, int right, int top, int bottom);

	// �����  ������������� �������� ���� ������
	void SetAll(int left, int right, int top, int bottom);

	// ����� ��������� �������� ����
	void GetAll(int* x1, int* x2, int* y1, int* y2) const;

	// ����� ��������� �������� ����
	const char* GetColor() const;

	void WhereAmI() const;

	virtual void WhereAmIVirtual() const;

	// ���������� ������� ������������ ������
	// ����� ��������� ������� ������
	//virtual void Inflate(int quantity);

private:
	int m_left, m_right, m_top, m_bottom;
};

