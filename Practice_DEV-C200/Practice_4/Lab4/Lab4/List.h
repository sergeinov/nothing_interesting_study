#pragma once

#include"Node.h"

class List
{
private:
	Node Head;				// ������� ������ ������ (�����)
	Node Tail;				// ������� ����� ������ (�����)
	size_t m_size;			// ���������� ��������� � ������
public:
	List();
	~List();

	void AddToHead(const Circle& figure);	// �������� � ������ ������
	bool RemoveOne(const Circle& figure);	// ������� �� ������
};

