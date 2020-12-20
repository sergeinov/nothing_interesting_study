#include "myRect.h"


// ������� 1�
// ����� ����������� ������� �������������� �� ��������
void Rect::InflateRect(unsigned int left, unsigned int right, unsigned int top, unsigned int bottom)
{
	m_left += left;
	m_right += right;
	m_top += top;
	m_bottom += bottom;
}

// ������� 2�
// ���������� �����������
Rect::Rect(const Rect& copyToOther)
{
	m_left = copyToOther.m_left;
	m_right = copyToOther.m_right;
	m_top = copyToOther.m_top;
	m_bottom = copyToOther.m_bottom;
}

// ������� 2�
void Rect::InflateRect(unsigned int leftRight, unsigned int topBottom)
{
	m_left += leftRight;
	m_right += leftRight;
	m_top += topBottom;
	m_bottom += topBottom;
};


//������� 3
void Rect::SetAll(int left, int right, int top, int bottom)
{
	this->m_left = left;
	this->m_right = right;
	this->m_top = top;
	this->m_bottom = bottom;
}


const int* Rect::Get()
{
	int* arr = new int[4];
	arr[0] = this->m_left;
	arr[1] = this->m_right;
	arr[2] = this->m_bottom;
	arr[3] = this->m_bottom;

	return arr;
};


//������� 4�
Rect& Rect::BoundingRect(const Rect* rect1, const Rect* rect2) 
{
	
	Rect* p = new Rect;		// ����� ������������ �� ���������

	p->m_left = rect1->m_left + rect2->m_left;
	p->m_right = rect1->m_right + rect2->m_right;
	p->m_top = rect1->m_top + rect2->m_top;
	p->m_bottom = rect1->m_bottom + rect2->m_bottom;

	return *p;
};