#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"



// для Задания 1.3
void printBOOK2(const BOOK2* book) 
{
	printf("Автор : %s\nНазвание : %s\nГод : %d\nЦена : %.2f\nКатегория : %d",
			book->autor, book->title, book->year, book->price,
			(((book->category == 1) ? "Боевики" : (book->category == 2) ? "Детективы" :
			(book->category == 3) ? "Приключения" : (book->category == 4) ? "Фанта стика" : 
			(book->category == 5) ? "Фэнтези" : (book->category == 6) ? "История" : "Спорт")));
};


// для Задания 1.4
void editBook2(BOOK2* book) 
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

		printf("\nВведите категорию(1,2,3,4,5,6,7):\n");
		scanf("%f", &book->category);
		/*if (book->category < 0 || book->category > 6)
		{
			printf("Категория не верна!\n");
			continue;
		}*/

		flag = false;
	}
	
};

////////////////////////////////////////////////

// для Задания 2

//функция вывода меню
void outputMenu()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	printf("Меню команд:\n%d - Распечатать картотеку книг. \n%d - Добавить новую книгу.\n\
%d - Удалить книгу из картотеки.\n%d - Записать содежимое картотеки в файл\n\
%d - Считать из файла содержимое в картотеку.\n%d - Выход из программы", \
			arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
};

// функция для распечатки картотеки
/*void printBOOK(const CARD_INDEX* pCard, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		pCard[i] = new CARD_INDEX;
	}
	for (size_t i = 0; i < size; i++)
	{
		printf("Автор : %s\nНазвание : %s\nГод : %d\nЦена : %.2f\nКатегория : %d",
			pCard->pB[i], book[i].title, book[i].year, book[i].price, book[i].category);
	}
};*/

// функция добавления книги
void addBook(CARD_INDEX* pCard)
{
	if (pCard->count >= pCard->cap)		// емкость исчерпана
	{
		// перераспределяем память
	}
	bool flag = true;	// для завершения цикла
	while (flag)
	{
		printf("\nВведите автора:\n");
		//scanf("%49s", pCard->pB);

		printf("\nВведите название книги:\n");
		//scanf("%99s", book[quantity].title);

		printf("\nВведите год:\n");
		//scanf(" %d", &book[quantity].year);
		//if (book[quantity].year < 1445 || book[quantity].year > 2020)
		//{
		//	printf("Не допустимый год издания.Не меньше 1445г\n");
		//	continue;
		//}

		printf("\nВведите цену:\n");
		//scanf("%f", &book[quantity].price);
		//if (book[quantity].price < 0)
		//{
		//	printf("Цена не может быть отрицательной!\n");
		//	continue;
		//}

		//printf("\nВведите категорию(1,2,3,4,5,6,7):\n");
		//scanf("%f", &book[quantity].category);
		//if (book->category < 0 || book->category > 6)
		//{
		//	printf("Категория не верна!\n");
		//	continue;
	}

		flag = false;
};
