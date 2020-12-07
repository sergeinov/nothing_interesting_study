#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"



// ��� ������� 1.3
void printBOOK(const BOOK* book) 
{
	printf("����� : %s\n�������� : %s\n��� : %d\n���� : %.2f\n��������� : %d",
			book->autor, book->title, book->year, book->price,
			(((book->category == 1) ? "�������" : (book->category == 2) ? "���������" :
			(book->category == 3) ? "�����������" : (book->category == 4) ? "����� �����" : 
			(book->category == 5) ? "�������" : (book->category == 6) ? "�������" : "�����")));
};


// ��� ������� 1.4
void editBook(BOOK* book) 
{
	bool flag = true;
	while (flag) 
	{
		printf("������� ������, �������� �����, ���, ����, ���������(1,2,3,4,5,6,7):\n");
		scanf("%49s %99s %d %f %d", book->autor, book->title, &book->year, &book->price, &book->category);

		if (book->year < 1445)
		{
			printf("�� ���������� ��� �������.�� ������ 1445�\n");
			continue;
		}
		else if (book->price < 0)
		{
			printf("���� �� ����� ���� �������������!\n");
			continue;
		} 
		else if (book->category < 0 || book->category > 6)
		{
			printf("��������� �� �����!\n");
		}
		flag = false;
	}
	
};