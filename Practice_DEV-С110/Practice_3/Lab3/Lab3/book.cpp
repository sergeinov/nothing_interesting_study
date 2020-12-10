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
	scanf("%d", answer);
};

// ������� ��� ���������� ���������
void printBOOK(const CARD_INDEX* pCard)
{
	for (size_t i = 0; i < pCard->count; i++)
	{
		print(pCard->pB[i]);
	}
};

// ����������� �����
void print(const BOOK* book)
{
	static const char* arr[] = { "Adventure", "Fantastic", "Fantasy", "History", "Sports", "Detectives"};
	printf("����� : %s\n�������� : %s\n��� : %d\n���� : %.2f\n��������� : %d",
		book->autor, book->title, book->year, book->price, arr[book->category - 1]);
	printf("\n\n");
};

// ������� ���������� �����
void addBook(CARD_INDEX* pCard)
{
	if (pCard->count >= pCard->cap)		// ������� ���������
	{
		// �� ���� ���, �� ���������������� ������
	}

	pCard->pB[pCard->count] = new BOOK[pCard->count + 1];	// ����-�� �� � �� ������ �����
	for (size_t i = 0; i < pCard->count + 1; i++)
	{
		pCard->pB[i ] =  
	}
	
	bool flag = true;	// ��� ���������� �����
	while (flag)
	{
		printf("\n������� ������:\n");
		scanf("%49s", pCard->pB[pCard->count]->autor);

		printf("\n������� �������� �����:\n");
		scanf("%99s", pCard->pB[pCard->count]->title);

		printf("\n������� ���:\n");
		scanf("%d", pCard->pB[pCard->count]->year);
		if (pCard->pB[pCard->count]->year < 1445 || pCard->pB[pCard->count]->year > 2020)
		{
			printf("�� ���������� ��� �������.�� ������ 1445�\n");
			continue;
		}

		printf("\n������� ����:\n");
		scanf("%f", pCard->pB[pCard->count]->price);
		if (pCard->pB[pCard->count]->price < 0)
		{
			printf("���� �� ����� ���� �������������!\n");
			continue;
		}

		printf("\n������� ���������\
			1 - Adventure,2 - Fantastic,3 - Fantasy,4 - History,5 - Sports,6 - Detectives:\n");
		scanf("%d", pCard->pB[pCard->count]->category);
		if (pCard->pB[pCard->count]->price < 0 || pCard->pB[pCard->count]->price > 6)
		{
			printf("��������� �� �����!\n");
			continue;
		}
	}
		flag = false;
};
