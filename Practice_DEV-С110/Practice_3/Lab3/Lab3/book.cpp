#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"



/*// ��� ������� 1.3
void printBOOK2(const TBook2* book) 
{
	static const char* arr[] = {"�������", "���������", "�����������", "����������", "�������", "�������", "����� "};
	printf("����� : %s\n�������� : %s\n��� : %d\n���� : %.2f\n��������� : %s",
		book->autor, book->title, book->year, book->price, arr[book->category - 1]);
};


// ��� ������� 1.4
void editBook2(TBook2* book)
{
	bool flag = true;	// ��� ���������� �����
	while (flag) 
	{
		printf("\n������� ������:\n");
		scanf("%49s", book->autor);

		printf("\n������� �������� �����:\n");
		scanf("%99s", book->title);

		printf("\n������� ���:\n");
		scanf(" %d", &book->year);
		if (book->year < 1445 || book->year > 2020)
		{
			printf("�� ���������� ��� �������.�� ������ 1445�\n");
			continue;
		}

		printf("\n������� ����:\n");
		scanf("%f", &book->price);
		if (book->price < 0)
		{
			printf("���� �� ����� ���� �������������!\n");
			continue;
		}

		printf("\n������� ���������: 1 - �������, 2 - ���������, 3 - �����������, 4 - ����������, 5 - �������, 6 -�������, 7 - ����� ):\n");
		scanf("%d", &book->category);
		if (book->category < 0 || book->category > 7)
		{
			printf("��������� �� �����!\n");
			continue;
		}

		flag = false;
	}
	
};
*/


////////////////////////////////////////////////

// ��� ������� 2

//������� ������ ����
void outputMenu(int* answer)
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };

	printf("\t���� ������:\n\
	%d - ����������� ��������� ����. \n\
	%d - �������� ����� �����.\n\
	%d - ������� ����� �� ���������.\n\
	%d - �������� ���������� ��������� � ����\n\
	%d - ������� �� ����� ���������� � ���������.\n\
	%d - ����� �� ���������",\
	arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);

	printf("\n������� �������: ");
	do
	{
		scanf("%d", answer);
	} while (*answer <= 0 || *answer > 6);
};

// ������� ��� ���������� ���������
void printBOOK(const CARD_INDEX* pCard)
{
	if (pCard->count == 0)
	{
		printf("\n�����!\n");
	} else {
		printf("\n����: %d\n", pCard->count);
		for (size_t i = 0; i < pCard->count; i++)
		{
			print(pCard->pB[i]);
		}
	}
	
};

// ����������� �����
void print(const BOOK* book)
{
	static const char* arr[] = { "Adventure", "Fantastic", "Fantasy", "History", "Sports", "Detectives"};
	printf("����� : %s\n�������� : %s\n��� : %d\n���� : %.2f\n��������� : %s",
		book->autor, book->title, book->year, book->price, arr[book->category - 1]);
	printf("\n\n");
};

// ������� ���������� �����
void addBook(CARD_INDEX* pCard)
{
	//pCard->count++;						//  ��������� ���������� ����

	if (pCard->count >= pCard->cap)		// ��������. ������� ���������
	{
		pCard->cap++;
		BOOK** tmp = new BOOK* [pCard->cap];
		for (size_t i = 0; i < pCard->count; i++)
		{
			tmp[i] = pCard->pB[i];
		}
		delete[] pCard->pB;
		pCard->pB = tmp;
	}

	BOOK* pBook = new BOOK;
	addFieldsBook(pBook);

	pCard->pB[pCard->count] = pBook;
	pCard->count++;
	
};

void addFieldsBook(BOOK* book) {

	bool flag = true;	// ��� ���������� �����
	while (flag)
	{
		printf("\n������� ������:\n");
		scanf("%49s", book->autor);

		printf("\n������� �������� �����:\n");
		scanf("%99s", book->title);

		printf("\n������� ���:\n");
		scanf("%d", &book->year);
		if (book->year < 1445 || book->year > 2020)
		{
			printf("�� ���������� ��� �������.�� ������ 1445�\n");
			continue;
		}

		printf("\n������� ����:\n");
		scanf("%f", &book->price);
		if (book->price < 0)
		{
			printf("���� �� ����� ���� �������������!\n");
			continue;
		}

		printf("\n������� ���������: 1 - Adventure,2 - Fantastic,3 - Fantasy,4 - History,5 - Sports,6 - Detectives:\n");
		scanf("%d", &book->category);
		if (book->category <= 0 || book->category > 6)
		{
			printf("��������� �� �����!\n");
			continue;
		}
		flag = false;
	}
		
};


void deleteBook(CARD_INDEX* pCard)
{
	int numberBook = 0;
	bool flag = true;
	do
	{
		printf("\n������� ����� ����� �������: 0,1,2....\n");
		scanf("%d", &numberBook);

		if (numberBook > pCard->count)
		{
			printf("�������� ����� � ��������");
			continue;
		}
		flag = false;
	} while (flag);
	
	delete pCard->pB[numberBook];

	pCard->pB[numberBook] = pCard->pB[pCard->count - 1];

	pCard->count--;
	//delete pCard->pB[numberBook + 1];

};