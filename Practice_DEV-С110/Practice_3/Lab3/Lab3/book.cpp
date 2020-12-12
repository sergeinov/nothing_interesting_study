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
	do
	{
		scanf("%d", answer);
	} while (*answer <= 0 || *answer > 6);
};

// функция для распечатки картотеки
void printBOOK(const CARD_INDEX* pCard)
{
	if (pCard->count == 0)
	{
		printf("\nПусто!\n");
	} else {
		printf("\nКниг: %d\n", pCard->count);
		for (size_t i = 0; i < pCard->count; i++)
		{
			print(pCard->pB[i]);
		}
	}
	
};

// распечатать книгу
void print(const BOOK* book)
{
	static const char* arr[] = { "Adventure", "Fantastic", "Fantasy", "History", "Sports", "Detectives"};
	printf("Автор : %s\nНазвание : %s\nГод : %d\nЦена : %.2f\nКатегория : %s",
		book->autor, book->title, book->year, book->price, arr[book->category - 1]);
	printf("\n\n");
};

// функция добавления книги
void addBook(CARD_INDEX* pCard)
{
	//pCard->count++;						//  увеличили количество книг

	if (pCard->count >= pCard->cap)		// проверка. емкость исчерпана
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

	bool flag = true;	// для завершения цикла
	while (flag)
	{
		printf("\nВведите автора:\n");
		scanf("%49s", book->autor);

		printf("\nВведите название книги:\n");
		scanf("%99s", book->title);

		printf("\nВведите год:\n");
		scanf("%d", &book->year);
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

		printf("\nВведите категорию: 1 - Adventure,2 - Fantastic,3 - Fantasy,4 - History,5 - Sports,6 - Detectives:\n");
		scanf("%d", &book->category);
		if (book->category <= 0 || book->category > 6)
		{
			printf("Категория не верна!\n");
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
		printf("\nВведите какую книгу удалить: 0,1,2....\n");
		scanf("%d", &numberBook);

		if (numberBook > pCard->count)
		{
			printf("Неверный номер в каталоге");
			continue;
		}
		flag = false;
	} while (flag);
	
	delete pCard->pB[numberBook];

	pCard->pB[numberBook] = pCard->pB[pCard->count - 1];

	pCard->count--;
	//delete pCard->pB[numberBook + 1];

};