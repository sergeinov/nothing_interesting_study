#pragma once

enum CATEGORY { ������� = 1, ���������, �����������, ����������, Fantasy, �������, ����� };

struct BOOK
{
	char autor[50] = "������ ��������� ����";
	char title[100] = "�������";
	int year = 2011;
	float price = 55.45;
	CATEGORY category = Fantasy;
};


// ��� ������� 1.3
void printBOOK(const BOOK* book);


// ��� ������� 1.4
void editBook(BOOK* book);