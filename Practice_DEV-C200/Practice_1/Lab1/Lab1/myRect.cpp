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


const void Rect::Get()
{
	std::cout << "m_left: " << m_left << std::endl;
	std::cout << "m_right: " << m_right << std::endl;
	std::cout << "m_top: " << m_top << std::endl;
	std::cout << "m_bottom: " << m_bottom << std::endl;
};