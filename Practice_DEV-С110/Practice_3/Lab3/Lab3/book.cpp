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
		printf("\nВ каталоге пусто!\n");
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
		if (pCard->count == 0)
		{
			printf("\nВ каталоге пусто! Добавьте книгу!\n");
			flag = false;
		}

		printf("\nВведите какую книгу удалить: 0,1,2....\n");
		scanf("%d", &numberBook);

		if (numberBook > pCard->count - 1)
		{
			printf("\nНеверный номер в каталоге\n");
			continue;
		} else {
			// удаляем структуру
			if (numberBook == (pCard->count - 1))
			{
				// если последний елемент, удаляем сразу
				delete pCard->pB[numberBook];
			}
			else {
				// если не последний, ставим на его место последний элемент
				BOOK* temp = pCard->pB[numberBook];
				pCard->pB[numberBook] = pCard->pB[pCard->count - 1];
				pCard->pB[pCard->count - 1] = temp;
				// удаляем
				delete pCard->pB[pCard->count - 1];

				/*for (size_t i = 0; i < pCard->count; i++)
				{
					BOOK* temp = pCard->pB[numberBook];
					pCard->pB[numberBook + 1] = pCard->pB[numberBook];
					pCard->pB[numberBook + 1] = pCard->pB[numberBook];
				}*/
			}

			// уменьшаем количество книг
			pCard->count--;
		}
		flag = false;
	} while (flag);
	
};


// добавить в файл картотеку
void addInFile(CARD_INDEX* pCard)
{
	FILE* file = fopen("in.txt", "w");		//открываем файл
	const char* arr[] = { "Adventure", "Fantastic", "Fantasy", "History", "Sports", "Detectives" };
	if (file)
	{
		for (size_t i = 0; i < pCard->count; i++)
		{		
			fprintf(file, "Автор: %s\nНазвание: %s\nГод: %d\nЦена: %.2f\nКатегория: %s\n\n",
			pCard->pB[i]->autor, pCard->pB[i]->title, pCard->pB[i]->year, pCard->pB[i]->price, arr[pCard->pB[i]->category]);
		}
		printf("\nЗаписано!\n");
		fclose(file);
	}
	else {
		printf("Ошибка открытия файла!");
	}
};


// добавить из файла книги
void addOutFile(CARD_INDEX* pCard)
{
	FILE* file = fopen("out.txt", "r");
	if (file)
	{
		BOOK* pBook = new BOOK;
		
		fscanf(file, "Books i %d\nautor: %s\ntitle: %s\nyear: %d\nprice: %.2f\ncategory: %s\n\n",
			   &pCard->count, pBook->autor, pBook->title, &pBook->year, &pBook->price, &pBook->category);

		pCard->pB[pCard->count] = pBook;

		fclose(file);
	}
	else {
		printf("Не получилось считать файл!");
	}
};

// Если файл существует и его удалось открыть
//if()
//{
//Чтение данных из файла
//а) считали количество элементов
//б) создали массив требуемой размерности
//в) считали данные из файла в массив

////////////////////////////////////////////////////////////////////////

// для Задания 3

void sortByAll(CARD_INDEX* pCard, eSwap numberSort)
{
	switch (numberSort)
	{
	case 1:
		for (size_t i = 0; i < pCard->count; i++)
		{
			for (size_t j = 0; j < pCard->count - i - 1; j++)
			{
				// если не первый автор больше второго
				if (strcmp(pCard->pB[j]->autor, pCard->pB[j + 1]->autor) > 0)
				{
					BOOK* tmp = pCard->pB[j];	// обмен элементов 
					pCard->pB[j] = pCard->pB[j + 1];
					pCard->pB[j + 1] = tmp;
				}
			}
		}
		break;
	case 2:
		for (size_t i = 0; i < pCard->count; i++)
		{
			for (size_t j = 0; j < pCard->count - i - 1; j++)
			{
				// если не первый автор больше второго
				if (strcmp(pCard->pB[j]->title, pCard->pB[j + 1]->title) > 0)
				{
					BOOK* tmp = pCard->pB[j];	// обмен элементов 
					pCard->pB[j] = pCard->pB[j + 1];
					pCard->pB[j + 1] = tmp;
				}
			}
		}
		break;
	case 3:
		//deleteBook(&card);
		break;
	case 4:
		//addInFile(&card);
		break;
	case 5:
		//addOutFile(&card);
		break;
	default:
		printf("\nЧто-то не сработала сортировка\n");
	}

	printf("Отсортировано!!!\n");
};