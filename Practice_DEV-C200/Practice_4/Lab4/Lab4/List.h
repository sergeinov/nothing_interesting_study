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

	
	/*
	TODO
	- ����� ��������� ������� � ����� ������
	- ������� ������ ������. ������� ��� �������
	*/

	// ������
	void AddToHead(const Circle& figure);	// �������� � ������ ������
	bool RemoveOne(const Circle& figure);	// ������� ���� �� ������
	int RemoveAll(const Circle& figure);	// ������� ��� ������



	/*
	TODO
	1.	���������� �� ����������� ������� �������.
	2.	����� �������� ��������� ������ �� �������
		cout << l;
	3.	����� �������� ��������� ������ � ����(� ��������������� ����)
	#include <fstream>
		ofstream fout(ar);
		fout << l;
		fout.close();
	4.	������ �� �����
	*/
};

