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
#include "lab3.h"


#define	  stop __asm nop	




void main()
{
	setlocale(LC_ALL, "Russian");
	{
		using namespace std;
		//���� "������" ��������� ������� ����������� ����������
		//������� 1. � ������� ������� scanf ����������� ��� ������������: A,B,C
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
		while (!(x == 2))
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



	//������� 1.2. �������� ������� ��������� (����������, ���������, �����������,
	//������������) ���������� (�������) ���� BOOK (��� �������������).
	//���������� - ������� ������ ������� ���������� ��� ������
	//����� ������. ��� ���������������� (��� �� ����������������) ����
	//���������. ���������: �� ���� ������� ����� ���������� ������?



	//������� 1.3. �������� �������, ��������� �� ����� ��������� �����.
	//���������: ��� ����������� ���������� ��������� BOOK � �������.
	//��� ������ �� ������� ����������� ������� ����������� ����������
	//printf

	//������� 1.4. �������� ������� ��� ������������ ����� ���������.
	//��� ����� ����������� ������� ����������� ���������� scanf
	//���������: ������� �������� � ����� ������� ����������� ��������
	//������������ ���������� ��������, ��������, ��� ������� �� ����� ����
	//�����, ���... (��� ��������� ������������), ��������� �����������
	//������ �������� �� ������������, ���� �� ����� ���� �������������...


	//����������� ��������� BOOK, ��������� � ���������� �������.
	//��� ����� ���������� ���������� � ���������� � ������� �����
	//book.h � book.cpp

	//������� 2. ������� ����������.
	//���������� - ��� ������ �������� => ����� ����� ������ �������.
	//���������: ������ ������� �������� ������������� ���� ���������� ���� =>
	//������ ������ ���� ����� ������???
	

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




	//���������1: ��� ��������� �����/������ ����������� ������� fprintf � fscanf
	//(������������ ���� <cstdio>



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




	//****************************************************************
	//������� 3. ������������ ������������ ����������� �������� �������� ����
	//� ������������ ������� => �������� ������� (�������) ���������� �������
	//�� ������ �� ����� ���������.
	//���������: ������� - "�� ������ ���� ���������" ����� ������ � �������
	//������������.



}