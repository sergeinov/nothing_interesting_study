#pragma once
#include"Pair.h"
#include<iostream>

class Base
{
private:
	Pair* pBase;		// ��������� �� ����
	size_t count;		// ���������� �����������
	size_t capacity;	// ������ ����
public:
	//������������
	Base();
	~Base();
	Base(const Base& bd); // ����������� ����������� ���������, ����� ���� ����������� ���������� ������
	Base(Base&& bd);

	//������������
	Base& operator=(const Base& bd);	// ���������������� �������� ������������
	Base& operator=(Base&& bd);			// �������� ����������� move
	MyData& operator[](const char* key);
	friend std::ostream& operator<<(std::ostream& os, const Base& bd);

	// ������
	void deletePair(const char* key);	// �������� ���������� �� ����	
	
};

