#pragma once

#include"Circle.h"

class Node
{
private:
	Node* pPrev;		// ����� �����
	Node* pNext;		// ����� ������
	Circle m_Data;		// ���� ������  (������ ����)

public:
	Node();			// ��� ��������������� ������� ������� (Head, Tail)
	Node(Node* p, const Circle* data); // Node* p - ��������� � ������ data
	~Node();

	friend class List;		// ��� ������� � ������ ������
};

