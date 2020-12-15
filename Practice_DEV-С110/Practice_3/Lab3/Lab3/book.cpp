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
	
	bool flag = true;
	do
	{
		if (pCard->count == 0)
		{
			printf("\nВ каталоге пусто! Добавьте книгу!\n");
			flag = false;
		}
		int numberBook = 0;
		printf("\nВведите какую книгу удалить: 0,1,2....\n");
		scanf("%d", &numberBook);

		// проверяем ответ
		if (numberBook > pCard->count - 1)
		{
			printf("\nНеверный номер в каталоге\n");
			continue;
		} else {
			// удаляем структуру
			delete pCard->pB[numberBook];

			// сдвигаем все книги влево на место удаленной
			for (size_t i = numberBook; i < pCard->count; i++)
			{
				pCard->pB[i] = pCard->pB[i + 1];
			}
		}
		// уменьшаем количество книг
		pCard->count--;
		
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
		fprintf(file,"Book is %d\n", pCard->count);
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
	/*switch (numberSort)
	{
	case 1:
		printf("Сортировка по автору....\n");
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
		printf("Сортировка по названию книги....\n");
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
		printf("Сортировка по году издания....\n");
		for (size_t i = 0; i < pCard->count; i++)
		{
			for (size_t j = 0; j < pCard->count - i - 1; j++)
			{
				// если не первый автор больше второго
				if (pCard->pB[j]->year > pCard->pB[j + 1]->year)
				{
					BOOK* tmp = pCard->pB[j];	// обмен элементов 1
					pCard->pB[j] = pCard->pB[j + 1];
					pCard->pB[j + 1] = tmp;
				}
			}
		}
		break;
	case 4:
		printf("Сортировка по цене....\n");
		for (size_t i = 0; i < pCard->count; i++)
		{
			for (size_t j = 0; j < pCard->count - i - 1; j++)
			{
				// если не первый автор больше второго
				if (pCard->pB[j]->price > pCard->pB[j + 1]->price)
				{
					BOOK* tmp = pCard->pB[j];	// обмен элементов 1
					pCard->pB[j] = pCard->pB[j + 1];
					pCard->pB[j + 1] = tmp;
				}
			}
		}
		break;
	case 5:
		printf("Сортировка по категории....\n");
		for (size_t i = 0; i < pCard->count; i++)
		{
			for (size_t j = 0; j < pCard->count - i - 1; j++)
			{
				// если не первый автор больше второго
				if (pCard->pB[j]->category > pCard->pB[j + 1]->category)
				{
					BOOK* tmp = pCard->pB[j];	// обмен элементов 1
					pCard->pB[j] = pCard->pB[j + 1];
					pCard->pB[j + 1] = tmp;
				}
			}
		}
		break;
	default:
		printf("\nОтсортировано с ошибкой!!!\n");
	}*/
	const char* arr[] = { " ", "Автор","Заголовок", "Год", "Цена", "Категория" };

	printf("\nСортировка по %s\n", arr[numberSort]);

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

			// если флаг положительный сортируем 
			if (flag)
			{
				BOOK* tmp = pCard->pB[j];	// обмен элементов 
				pCard->pB[j] = pCard->pB[j + 1];
				pCard->pB[j + 1] = tmp;
			}

		}
	}

	printf("Отсортировано!!!\n");
};