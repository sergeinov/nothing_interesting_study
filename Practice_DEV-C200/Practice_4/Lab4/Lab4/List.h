#pragma once

#include"Node.h"
//#include<iostream>
#include <fstream>

class List
{
private:
	Node Head;				// ������� ������ ������ (�����)
	Node Tail;				// ������� ����� ������ (�����)
	size_t m_size;			// ���������� ��������� � ������
public:

	// ������������
	List();
	List(const List& otherList);	// ����������� �����������
	List(List&& otherList);			// ����������� ����������� move
	~List();

	// ������
	void AddToHead(const Circle& figure);	// �������� � ������ ������
	void AddToEnd(const Circle& figure);	// �������� � ����� ������
	bool RemoveOne(const Circle& figure);	// ������� ���� �� ������
	int RemoveAll(const Circle& figure);	// ������� ��� ������
	void SortList();
	void ClearList();

	// ����������
	List& operator=(const List& otherList);		//���������� ��������� ������������ = ��� �������
	List& operator=(List&& otherList);			// ���������� ��������� move
	friend std::ostream& operator<<(std::ostream& os, const List& list);	// ����� ������
	friend std::ifstream& operator>>(std::ifstream& iff, List& list);	// ������ �� �����


	/*
	TODO
	1.	���������� �� ����������� ������� �������.
	*/
};

