/*************************************************************
	������������ ������� �3-����-�110. ���������
//������������ ������ ��������
//�����
//����������
//���������� � �����
//������ �� �����
*************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include "book.h"

//#pragma pack(push,1)	// ���������� ������������ ���������

#define	  stop __asm nop	

// �������� ���������� � ���������� �������
//TBook2 book1;							// ������������� ������  

int main()
{
	setlocale(LC_ALL, "Russian");
	/*
	{
		using namespace std;
		//���� "������" ��������� ������� ����������� ����������
		//������� 1. � ������� ������� scanf ����������� ��� ������������: A,B,C
		printf("������� 1\n");
		int a;
		int b;
		int c;
		
		printf("������� �������� A, B, C: ");
		scanf("%d %d %d", &a, &b, &c);
		//printf("%4d %4d %4d", a, b, c);

		//������� 2. �������� (�������!) ������� �������� y=A*x*x + B*x + C
		//��� ��������� x � ��������� -2 �� +2 � ����� 0.5
		double y;
		float x = -2;
		float step = 0.5;
		char space = ' ';
		char lineVert = '|';

		printf("\n\n");
		printf("\t%c %6cx%6c %c %6cy%-6c %c", lineVert, space, space, lineVert, space, space, lineVert);
		printf("\n\t_________________________________");
		while (!(x >= 2))
		{
			y = ((a * pow(x, 2)) + ((b * x) + c));
			printf("\n\t%c x = %6.1f %4c y = %6.2f %4c", lineVert, x, lineVert, y, lineVert);
			x += step;
		}
		printf("\n\t_________________________________");
	}
	//����. ��������� �.	
//������� 1.1 �������� ��������� BOOK, ����������� �����
//(�����, ��������, ��� �������, ����, ����������).
//���������: ������ ���� ����� ���� ���� ���������.
//���������: ���������� ��������� ������������� ��������
//� ������������ ����.
	{

		printf("\n\n������� 1.2\n");
		//������� 1.2. �������� ������� ��������� (����������, ���������, �����������,
		//������������) ���������� (�������) ���� BOOK (��� �������������).
		//���������� - ������� ������ ������� ���������� ��� ������
		//����� ������. ��� ���������������� (��� �� ����������������) ����
		//���������. ���������: �� ���� ������� ����� ���������� ������?
		

		// �������� ��������� � ���������� �������
		printf("%d", sizeof(book1));		// 176 ����

		// ��������� ���������
		TBook2 book3;							// ������������� �������
		printf("\n%d", sizeof(book3));		// 176 ����

		// ����������� ��������� ���������
		static TBook2 book2;					// ������������� ������
		printf("\n%d", sizeof(book2));		// 176 ����

		// �������� ��������� ������������ ���������
		TBook2* book4 = new TBook2;				// ������������� �������
		printf("\n%d", sizeof*(book4));		// 176 ����

		// ���������� ���������� ������ ��������
		const int N = 5;
		TBook2 book5[N] = { 0 };				// �������� ��� ���� ������ �������� // ������������������� ���� ����� ������ ��� �������� ����������
		printf("\n%d", sizeof(book5));		// 880 ����
		printf("\n%d", (sizeof(book5) / sizeof(TBook2)));		// 5

		//������� 1.3. �������� �������, ��������� �� ����� ��������� �����.
		//���������: ��� ����������� ���������� ��������� BOOK � �������.
		//��� ������ �� ������� ����������� ������� ����������� ����������
		//printf
		printf("\n\n������� 1.3\n");
		TBook2 book6;
		strcpy(book6.autor, "������ ��������� ����");
		strcpy(book6.title, "�������");
		book6.year = 2011;
		book6.price = 55, 45;
		book6.category = ����������;
		printBOOK2(&book6);


		//������� 1.4. �������� ������� ��� ������������ ����� ���������.
		//��� ����� ����������� ������� ����������� ���������� scanf
		//���������: ������� �������� � ����� ������� ����������� ��������
		//������������ ���������� ��������, ��������, ��� ������� �� ����� ����
		//�����, ���... (��� ��������� ������������), ��������� ������������
		//������ �������� �� ������������, ���� �� ����� ���� �������������...
		printf("\n\n������� 1.4\n");
		TBook2 book7;
		editBook2(&book7);
		printf("\n�����...\n");
		printBOOK2(&book7);

		//����������� ��������� BOOK, ��������� � ���������� �������.
		//��� ����� ���������� ���������� � ���������� � ������� �����
		//book.h � book.cpp
		
	}
	*/
	{
		//////////////////////////////////////////////////////////////
		//������� 2. ������� ����������.
		//���������� - ��� ������ �������� => ����� ����� ������ �������.
		//���������: ������ ������� �������� ������������� ���� ���������� ���� =>
		//������ ������ ���� ����� ������???
		printf("\n\n������� 2\n");

		//������������ ������ ����� ����������� �� ������ ������� ���������
		//������ �������� � ���������� => ����� ����� ����������� ���
		//������������: ��� ����� ��������� ��� ����� "����" (��������
		//��������� �������� � ��������������� ������� ������������), ��������:
		//����������� ���������� ��������� (1)
		//������ ����� ����� (2)
		//������� ������������(��) (3)
		//�������� ������� ���������� ��������� � ���� (4)
		//������� �� ����� ���������� � ��������� (5)
		//...
		//����� �� ��������� (...)
		//���������� ����������� ������� ������ ����������� ������ � ����������

		int codeAnswer = 0;					// ��� ������ ���� ������� 

		CARD_INDEX card;					// ��������� ���������
		card.count = 0;
		card.cap = 0;
		card.pB = nullptr;
		
		do
		{
			outputMenu(&codeAnswer);

			switch (codeAnswer)
			{
			case 1:
				printBOOK(&card);
				break;
			case 2:
				addBook(&card);
				card.count++;			// ����������� ���������� ���� �� 1
				break;
			case 3:
			case 4:
			case 5:
			case 6:
				printf("\n����� �� ���������!\n");
			default:
				break;
			}
			

		} while (!(codeAnswer == 6));
		
		// ����������� ������ �� ������� ��������
		/*for (size_t i = 0; i < N; i++)
		{
			delete Card[i];
		}
		delete[] Card;
		*/

		//���������1: ��� ��������� �����/������ ����������� ������� fprintf � fscanf
		//(������������ ���� <cstdio>
		// ���������:
		//1. ����� ����� � �������� ����� ������� �� ������ �����
		//2. ��� ������ ����� �������� ���������� �������. ���� �������
		//   �� ������ ��������, �� � ������� ������� �������, �������
		//   �) ������������ ������������ ��������� �����/������ - wprintf(), wscanf()
		//   �) ������� ������ ��� ����������� - wchar_t
		//   �) ���������� ��������� - setlocale(LC_CTYPE, ".866");	


		// ���������2: ������ � �������� ������� ������� � ����� ������� ����������
		// ���� � ���������
		//���� ���� ���������� � ��� ������� �������
		//if()
		//{
		//������ ������ �� �����
		//�) ������� ���������� ���������
		//�) ������� ������ ��������� �����������
		//�) ������� ������ �� ����� � ������
		//}



	}

	//****************************************************************
	{
		//������� 3. ������������ ������������ ����������� �������� �������� ����
		//� ������������ ������� => �������� ������� (�������) ���������� �������
		//�� ������ �� ����� ���������.
		//���������: ������� - "�� ������ ���� ���������" ����� ������ � �������
		//������������.


	}
	return 0;
}