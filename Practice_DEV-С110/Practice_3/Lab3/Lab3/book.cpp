#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"



// для Задания 1.3
void printBOOK(const BOOK* book) 
{
	printf("Автор : %s\nНазвание : %s\nГод : %d\nЦена : %.2f\nКатегория : %d",
			book->autor, book->title, book->year, book->price,
			(((book->category == 1) ? "Боевики" : (book->category == 2) ? "Детективы" :
			(book->category == 3) ? "Приключения" : (book->category == 4) ? "Фанта стика" : 
			(book->category == 5) ? "Фэнтези" : (book->category == 6) ? "История" : "Спорт")));
};


// для Задания 1.4
void editBook(BOOK* book) 
{
	bool flag = true;
	while (flag) 
	{
		printf("Введите автора, название книги, год, цену, категорию(1,2,3,4,5,6,7):\n");
		scanf("%49s %99s %d %f %d", book->autor, book->title, &book->year, &book->price, &book->category);

		if (book->year < 1445)
		{
			printf("Не допустимый год издания.Не меньше 1445г\n");
			continue;
		}
		else if (book->price < 0)
		{
			printf("Цена не может быть отрицательной!\n");
			continue;
		} 
		else if (book->category < 0 || book->category > 6)
		{
			printf("Категория не верна!\n");
		}
		flag = false;
	}
	
};