#pragma once
#include<utility>
//  �������

template<typename T> inline void Swap(T& a, T& b)	// ������ ������ ��������
{
	// ��� ������ � MyString ��������� � ������ ����������� ����������� ���������� � (?����������� - ������������)
	T temp = std::move(a);		// ����� �� ������������ ����������� ����������� (�� ���������)
	a = std::move(b);		
	b = std::move(temp);
}