#pragma once

#include"Node.h"

enum eParametrs {Color, Area };

class List
{
private:
	Node Head;
	Node Tail;
	size_t m_size;
public:
/*
*	������������
*/
	List();
	List(const List& otherList);	// ����������� �����������
	List(List&& otherList);			// ����������� ����������� move
	~List();

/*
*	������
*/
	void AddToHead(const Shape& figure);	// �������� � ������ ������
	void AddToEnd(const Shape& figure);		// �������� � ����� ������
	bool RemoveOne(const Shape& figure);	// ������� ���� �� ������
	void ClearList();						// �������� ������ �� ��������
	void Sort(eParametrs param);			// ���������� �� ����������� ������� �������		// TODO
	//int RemoveAll(const Shape& figure);		// ������� ��� ������	

/*
*	����������
*/
	friend std::ostream& operator<<(std::ostream& os, const List& list);	// ����� ������		// TODO
	friend std::ifstream& operator>>(std::ifstream& iff, List& list);	// ������ �� �����		// TODO

	List& operator=(const List& otherList);		//���������� ��������� ������������ = ��� �������

	//List& operator=(List&& otherList);			// ���������� ��������� move



};


//! TODO  !Done
/*
�	�������� ����� ������ � ������ ������  /
�	�������� ����� ������ � ����� ������
�	��������� ������, ����������� � ����������
	- ����� ������ � ���� � ������ �� �����
	-���������� �� ����������� ������� ������� (�� �����, �� �������� �� ������ ���������).
*/