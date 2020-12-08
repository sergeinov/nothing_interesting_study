#pragma once

enum CATEGORY2 { Боевики = 1, Детективы, Приключения, Фантастика, Фэнтези, История, Спорт };

struct BOOK2
{
	char autor[50] = "Сергей Семонович Труш";
	char title[100] = "Трясина";
	unsigned short year = 2011;
	float price = 55.45;
	CATEGORY2 category = Фантастика;
};


// для Задания 1.3
void printBOOK2(const BOOK2* book);


// для Задания 1.4
void editBook2(BOOK2* book);

////////////////////////////////////////////////

// для Задания 2

enum eCATEGORY { Detectives = 1, Adventure, Fantastic, Fantasy, History, Sports };

struct BOOK
{
	char autor[50] = {0};
	char title[100] = {0};
	unsigned short year;
	float price;
	eCATEGORY category;
};

struct CARD_INDEX
{
	BOOK** pB;				// указатель на картотеку BOOK* pB
	size_t count = 0;		// количество книг
	size_t cap;				// емкость картотеки
};

// функция вывода меню
void outputMenu();

// функция для распечатки картотеки
void printBOOK(const CARD_INDEX* pCard, int size);

// функция добавления книги
void addBook(CARD_INDEX* pCard);