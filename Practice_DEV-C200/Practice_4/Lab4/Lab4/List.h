#pragma once

#include"Node.h"
#include<iostream>
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

	// ����������
	List& operator=(const List& otherList);		//���������� ��������� ������������ = ��� �������
	List& operator=(List&& otherList);
	friend std::ostream& operator<<(std::ostream& os, const List& list);	// ����� ������
	//friend std::ofstream& operator<<(std::ofstream& of, List& list);	// ����� � ����
	friend std::ifstream& operator>>(std::ifstream& iff, List& list);	// ������ �� �����


	/*
	TODO
	1.	���������� �� ����������� ������� �������.
	2.	����� �������� ��������� ������ �� �������
		cout << l;
	3.	����� �������� ��������� ������ � ����(� ��������������� ����)
	#include <fstream>
		ofstream fout(file);
		fout << l;
		fout.close();
	4.	������ �� �����
		ifstream fout(file);
		fout >> l;
		fout.close();
	*/
};

