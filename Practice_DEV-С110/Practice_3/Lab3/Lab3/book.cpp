#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"



/*// для Задания 1.3
void printBOOK2(const TBook2* book) 
{
	static const char* arr[] = {"Боевики", "Детективы", "Приключения", "Фантастика", "Фэнтези", "История", "Спорт "};
	printf("Автор : %s\nНазвание : %s\nГод : %d\nЦена : %.2f\nКатегория : %s",
		book->autor, book->title, book->year, book->price, arr[book->category - 1]);
};


// для Задания 1.4
void editBook2(TBook2* book)
{
	bool flag = true;	// для завершения цикла
	while (flag) 
	{
		printf("\nВведите автора:\n");
		scanf("%49s", book->autor);

		printf("\nВведите название книги:\n");
		scanf("%99s", book->title);

		printf("\nВведите год:\n");
		scanf(" %d", &book->year);
		if (book->year < 1445 || book->year > 2020)
		{
			printf("Не допустимый год издания.Не меньше 1445г\n");
			continue;
		}

		printf("\nВведите цену:\n");
		scanf("%f", &book->price);
		if (book->price < 0)
		{
			printf("Цена не может быть отрицательной!\n");
			continue;
		}

		printf("\nВведите категорию: 1 - Боевики, 2 - Детективы, 3 - Приключения, 4 - Фантастика, 5 - Фэнтези, 6 -История, 7 - Спорт ):\n");
		scanf("%d", &book->category);
		if (book->category < 0 || book->category > 7)
		{
			printf("Категория не верна!\n");
			continue;
		}

		flag = false;
	}
	
};
*/


////////////////////////////////////////////////

// для Задания 2

//функция вывода меню
void outputMenu(int* answer)
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };

	printf("\tМеню команд:\n\
	%d - Распечатать картотеку книг. \n\
	%d - Добавить новую книгу.\n\
	%d - Удалить книгу из картотеки.\n\
	%d - Записать содержимое картотеки в файл\n\
	%d - Считать из файла содержимое в картотеку.\n\
	%d - Выход из программы",\
	arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);

	printf("\nВведите команду: ");
	scanf("%d", answer);
};

// функция для распечатки картотеки
void printBOOK(const CARD_INDEX* pCard)
{
	for (size_t i = 0; i < pCard->count; i++)
	{
		print(pCard->pB[i]);
	}
};

// распечатать книгу
void print(const BOOK* book)
{
	static const char* arr[] = { "Adventure", "Fantastic", "Fantasy", "History", "Sports", "Detectives"};
	printf("Автор : %s\nНазвание : %s\nГод : %d\nЦена : %.2f\nКатегория : %d",
		book->autor, book->title, book->year, book->price, arr[book->category - 1]);
	printf("\n\n");
};

// функция добавления книги
void addBook(CARD_INDEX* pCard)
{
	if (pCard->count >= pCard->cap)		// емкость исчерпана
	{
		// не знаю как, но перераспределяем память
	}

	pCard->pB[pCard->count] = new BOOK[pCard->count + 1];	// куда-то не в ту память лезем
	for (size_t i = 0; i < pCard->count + 1; i++)
	{
		pCard->pB[i ] =  
	}
	
	bool flag = true;	// для завершения цикла
	while (flag)
	{
		printf("\nВведите автора:\n");
		scanf("%49s", pCard->pB[pCard->count]->autor);

		printf("\nВведите название книги:\n");
		scanf("%99s", pCard->pB[pCard->count]->title);

		printf("\nВведите год:\n");
		scanf("%d", pCard->pB[pCard->count]->year);
		if (pCard->pB[pCard->count]->year < 1445 || pCard->pB[pCard->count]->year > 2020)
		{
			printf("Не допустимый год издания.Не меньше 1445г\n");
			continue;
		}

		printf("\nВведите цену:\n");
		scanf("%f", pCard->pB[pCard->count]->price);
		if (pCard->pB[pCard->count]->price < 0)
		{
			printf("Цена не может быть отрицательной!\n");
			continue;
		}

		printf("\nВведите категорию\
			1 - Adventure,2 - Fantastic,3 - Fantasy,4 - History,5 - Sports,6 - Detectives:\n");
		scanf("%d", pCard->pB[pCard->count]->category);
		if (pCard->pB[pCard->count]->price < 0 || pCard->pB[pCard->count]->price > 6)
		{
			printf("Категория не верна!\n");
			continue;
		}
	}
		flag = false;
};
