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
		printf("\n� �������� �����!\n");
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
	
	bool flag = true;
	do
	{
		if (pCard->count == 0)
		{
			printf("\n� �������� �����! �������� �����!\n");
			flag = false;
		}
		int numberBook = 0;
		printf("\n������� ����� ����� �������: 0,1,2....\n");
		scanf("%d", &numberBook);

		// ��������� �����
		if (numberBook > pCard->count - 1)
		{
			printf("\n�������� ����� � ��������\n");
			continue;
		} else {
			// ������� ���������
			delete pCard->pB[numberBook];

			// �������� ��� ����� ����� �� ����� ���������
			for (size_t i = numberBook; i < pCard->count; i++)
			{
				pCard->pB[i] = pCard->pB[i + 1];
			}
		}
		// ��������� ���������� ����
		pCard->count--;
		
		flag = false;
	} while (flag);
	
};


// �������� � ���� ���������
void addInFile(CARD_INDEX* pCard)
{
	FILE* file = fopen("in.txt", "w");		//��������� ����
	const char* arr[] = { "Adventure", "Fantastic", "Fantasy", "History", "Sports", "Detectives" };
	if (file)
	{
		fprintf(file,"Book is %d\n", pCard->count);
		for (size_t i = 0; i < pCard->count; i++)
		{		
			fprintf(file, "�����: %s\n��������: %s\n���: %d\n����: %.2f\n���������: %s\n\n",
			pCard->pB[i]->autor, pCard->pB[i]->title, pCard->pB[i]->year, pCard->pB[i]->price, arr[pCard->pB[i]->category]);
		}
		printf("\n��������!\n");
		fclose(file);
	}
	else {
		printf("������ �������� �����!");
	}
};


// �������� �� ����� �����
void addFromFile(CARD_INDEX* pCard)
{
	FILE* file = fopen("out.txt", "r");
	if (file)
	{
		int countBook = 0;
		fscanf(file, "Books is %d", &countBook);
		if (pCard->count + countBook > pCard->cap)
		{
			pCard->cap = pCard->count + countBook;
			BOOK** tmp = new BOOK*[pCard->cap];
			for (size_t i = 0; i < pCard->count; i++)
			{
				tmp[i] = pCard->pB[i];
			}
		}

		for (size_t i = pCard->count; i < pCard->count + countBook; i++)
		{
			BOOK* book = new BOOK;

			fscanf(file, "\nautor: %s\ntitle: %s\nyear: %d\nprice: %f\ncategory: %d\n\n",
					book->autor, book->title, &book->year, &book->price, &book->category);
			pCard->pB[i] = book;
		}

		pCard->count += countBook;

		fclose(file);
	}
	else {
		printf("�� ���������� ������� ����!");
	}
};

// ���� ���� ���������� � ��� ������� �������
//if()
//{
//������ ������ �� �����
//�) ������� ���������� ���������
//�) ������� ������ ��������� �����������
//�) ������� ������ �� ����� � ������

////////////////////////////////////////////////////////////////////////

// ��� ������� 3

void sortByAll(CARD_INDEX* pCard, eSwap numberSort)
{
	/*switch (numberSort)
	{
	case 1:
		printf("���������� �� ������....\n");
		for (size_t i = 0; i < pCard->count; i++)
		{
			for (size_t j = 0; j < pCard->count - i - 1; j++)
			{
				// ���� �� ������ ����� ������ �������
				if (strcmp(pCard->pB[j]->autor, pCard->pB[j + 1]->autor) > 0)
				{
					BOOK* tmp = pCard->pB[j];	// ����� ��������� 
					pCard->pB[j] = pCard->pB[j + 1];
					pCard->pB[j + 1] = tmp;
				}
			}
		}
		break;
	case 2:
		printf("���������� �� �������� �����....\n");
		for (size_t i = 0; i < pCard->count; i++)
		{
			for (size_t j = 0; j < pCard->count - i - 1; j++)
			{
				// ���� �� ������ ����� ������ �������
				if (strcmp(pCard->pB[j]->title, pCard->pB[j + 1]->title) > 0)
				{
					BOOK* tmp = pCard->pB[j];	// ����� ��������� 
					pCard->pB[j] = pCard->pB[j + 1];
					pCard->pB[j + 1] = tmp;
				}
			}
		}
		break;
	case 3:
		printf("���������� �� ���� �������....\n");
		for (size_t i = 0; i < pCard->count; i++)
		{
			for (size_t j = 0; j < pCard->count - i - 1; j++)
			{
				// ���� �� ������ ����� ������ �������
				if (pCard->pB[j]->year > pCard->pB[j + 1]->year)
				{
					BOOK* tmp = pCard->pB[j];	// ����� ��������� 1
					pCard->pB[j] = pCard->pB[j + 1];
					pCard->pB[j + 1] = tmp;
				}
			}
		}
		break;
	case 4:
		printf("���������� �� ����....\n");
		for (size_t i = 0; i < pCard->count; i++)
		{
			for (size_t j = 0; j < pCard->count - i - 1; j++)
			{
				// ���� �� ������ ����� ������ �������
				if (pCard->pB[j]->price > pCard->pB[j + 1]->price)
				{
					BOOK* tmp = pCard->pB[j];	// ����� ��������� 1
					pCard->pB[j] = pCard->pB[j + 1];
					pCard->pB[j + 1] = tmp;
				}
			}
		}
		break;
	case 5:
		printf("���������� �� ���������....\n");
		for (size_t i = 0; i < pCard->count; i++)
		{
			for (size_t j = 0; j < pCard->count - i - 1; j++)
			{
				// ���� �� ������ ����� ������ �������
				if (pCard->pB[j]->category > pCard->pB[j + 1]->category)
				{
					BOOK* tmp = pCard->pB[j];	// ����� ��������� 1
					pCard->pB[j] = pCard->pB[j + 1];
					pCard->pB[j + 1] = tmp;
				}
			}
		}
		break;
	default:
		printf("\n������������� � �������!!!\n");
	}*/
	const char* arr[] = { " ", "�����","���������", "���", "����", "���������" };

	printf("\n���������� �� %s\n", arr[numberSort]);

	for (size_t i = 0; i < pCard->count; i++)
	{
		for (size_t j = 0; j < pCard->count - i - 1; j++)
		{
			bool flag = false;
			switch (numberSort)
			{
			case 1:
				flag = (strcmp(pCard->pB[j]->autor, pCard->pB[j + 1]->autor));
				break;
			case 2:
				flag = (strcmp(pCard->pB[j]->title, pCard->pB[j + 1]->title));
				break;
			case 3:
				flag = (pCard->pB[j]->year > pCard->pB[j + 1]->year);
				break;
			case 4:
				flag = (pCard->pB[j]->price > pCard->pB[j + 1]->price);
				break;
			case 5:
				flag = (pCard->pB[j]->category > pCard->pB[j + 1]->category);
				break;
			default:
				break;
			}

			// ���� ���� ������������� ��������� 
			if (flag)
			{
				BOOK* tmp = pCard->pB[j];	// ����� ��������� 
				pCard->pB[j] = pCard->pB[j + 1];
				pCard->pB[j + 1] = tmp;
			}

		}
	}

	printf("�������������!!!\n");
};