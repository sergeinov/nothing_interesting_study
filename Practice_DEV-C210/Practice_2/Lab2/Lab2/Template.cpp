//  ���������� ��������

#include"Template.h"


template<typename T> inline void Swap(const T& a, const T& b)	// ������ ������ ��������
{
	// ��� ������ � MyString ��������� � ������ ����������� ����������� ���������� � �����������
	T temp = a;
	a = b;
	b = temp;
}
