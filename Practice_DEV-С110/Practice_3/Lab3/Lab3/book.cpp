#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"



// ��� ������� 1.3
void printBOOK2(const BOOK2* book) 
{
	printf("����� : %s\n�������� : %s\n��� : %d\n���� : %.2f\n��������� : %d",
			book->autor, book->title, book->year, book->price,
			(((book->category == 1) ? "�������" : (book->category == 2) ? "���������" :
			(book->category == 3) ? "�����������" : (book->category == 4) ? "����� �����" : 
			(book->category == 5) ? "�������" : (book->category == 6) ? "�������" : "�����")));
};


// ��� ������� 1.4
void editBook2(BOOK2* book) 
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

		printf("\n������� ���������(1,2,3,4,5,6,7):\n");
		scanf("%f", &book->category);
		/*if (book->category < 0 || book->category > 6)
		{
			printf("��������� �� �����!\n");
			continue;
		}*/

		flag = false;
	}
	
};

////////////////////////////////////////////////

// ��� ������� 2

//������� ������ ����
void outputMenu()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	printf("���� ������:\n%d - ����������� ��������� ����. \n%d - �������� ����� �����.\n\
%d - ������� ����� �� ���������.\n%d - �������� ��������� ��������� � ����\n\
%d - ������� �� ����� ���������� � ���������.\n%d - ����� �� ���������", \
			arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
};

// ������� ��� ���������� ���������
/*void printBOOK(const CARD_INDEX* pCard, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		pCard[i] = new CARD_INDEX;
	}
	for (size_t i = 0; i < size; i++)
	{
		printf("����� : %s\n�������� : %s\n��� : %d\n���� : %.2f\n��������� : %d",
			pCard->pB[i], book[i].title, book[i].year, book[i].price, book[i].category);
	}
};*/

// ������� ���������� �����
void addBook(CARD_INDEX* pCard)
{
	if (pCard->count >= pCard->cap)		// ������� ���������
	{
		// ���������������� ������
	}
	bool flag = true;	// ��� ���������� �����
	while (flag)
	{
		printf("\n������� ������:\n");
		//scanf("%49s", pCard->pB);

		printf("\n������� �������� �����:\n");
		//scanf("%99s", book[quantity].title);

		printf("\n������� ���:\n");
		//scanf(" %d", &book[quantity].year);
		//if (book[quantity].year < 1445 || book[quantity].year > 2020)
		//{
		//	printf("�� ���������� ��� �������.�� ������ 1445�\n");
		//	continue;
		//}

		printf("\n������� ����:\n");
		//scanf("%f", &book[quantity].price);
		//if (book[quantity].price < 0)
		//{
		//	printf("���� �� ����� ���� �������������!\n");
		//	continue;
		//}

		//printf("\n������� ���������(1,2,3,4,5,6,7):\n");
		//scanf("%f", &book[quantity].category);
		//if (book->category < 0 || book->category > 6)
		//{
		//	printf("��������� �� �����!\n");
		//	continue;
	}

		flag = false;
};
