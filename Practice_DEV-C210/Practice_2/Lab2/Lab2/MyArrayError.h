#pragma once

// ��������� ���������� ������ �� ������� �������

class MyArrayError
{
public:
	int m_wrong_Index;
	int m_MaxIndex;

	MyArrayError(int index, int max) : m_wrong_Index(index), m_MaxIndex(max) { };

};

