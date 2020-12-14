#pragma once
/*
enum CATEGORY2 { ������� = 1, ���������, �����������, ����������, �������, �������, ����� };

struct TBook2
{
	char autor[50];
	char title[100];
	unsigned short year;
	float price;
	CATEGORY2 category;
};


// ��� ������� 1.3
void printBOOK2(const TBook2* book);


// ��� ������� 1.4
void editBook2(TBook2* book);
*/


////////////////////////////////////////////////

// ��� ������� 2

enum eCATEGORY { Detectives = 1, Adventure, Fantastic, Fantasy, History, Sports };

// �����
struct BOOK
{
	char autor[50] = {0};
	char title[100] = {0};
	unsigned short year;
	float price;
	eCATEGORY category;
};

//���������
struct CARD_INDEX
{
	BOOK** pB;				// ��������� �� ����� BOOK* pB
	size_t count;		// ���������� ����
	size_t cap;				// ������� ���������
};

// ������� ������ ����
void outputMenu(int* answer);

// ����������� �����
void print(const BOOK* book);

// ������� ��� ���������� ���������
void printBOOK(const CARD_INDEX* pCard);

// ������� ���������� �����
void addBook(CARD_INDEX* pCard);

// ������� ���������� ����� � �����
void addFieldsBook(BOOK* book);

// ������� �����
void deleteBook(CARD_INDEX* pCard);

// �������� � ���� ���������
void addInFile(CARD_INDEX* pCard);

// �������� �� ����� �����
void addOutFile(CARD_INDEX* pCard);

//////////////////////////////////////////////////////////////////////

// ��� ������� 3

enum eSwap { autor = 1, title, year, price, category };

void sortByAll(CARD_INDEX* pCard, eSwap numberSort);
//void sortByTitle(CARD_INDEX* pCard, eSwap numberSort);
//void sortByYear(CARD_INDEX* pCard, eSwap numberSort);
//void sortByPrice(CARD_INDEX* pCard, eSwap numberSort);
//void sortByCategory(CARD_INDEX* pCard, eSwap numberSort);