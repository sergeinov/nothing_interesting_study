#pragma once

enum CATEGORY2 { ������� = 1, ���������, �����������, ����������, �������, �������, ����� };

struct BOOK2
{
	char autor[50] = "������ ��������� ����";
	char title[100] = "�������";
	unsigned short year = 2011;
	float price = 55.45;
	CATEGORY2 category = ����������;
};


// ��� ������� 1.3
void printBOOK2(const BOOK2* book);


// ��� ������� 1.4
void editBook2(BOOK2* book);

////////////////////////////////////////////////

// ��� ������� 2

enum eCATEGORY { Detectives = 1, Adventure, Fantastic, Fantasy, History, Sports };

struct BOOK
{
	char autor[50] = {0};
	char title[100] = {0};
	unsigned short year;
	float price;
	eCATEGORY category;
};

struct CARD_INDEX
{
	BOOK** pB;				// ��������� �� ��������� BOOK* pB
	size_t count = 0;		// ���������� ����
	size_t cap;				// ������� ���������
};

// ������� ������ ����
void outputMenu();

// ������� ��� ���������� ���������
void printBOOK(const CARD_INDEX* pCard, int size);

// ������� ���������� �����
void addBook(CARD_INDEX* pCard);