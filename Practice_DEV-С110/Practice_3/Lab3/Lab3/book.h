#pragma once
/*
enum CATEGORY2 { Боевики = 1, Детективы, Приключения, Фантастика, Фэнтези, История, Спорт };

struct TBook2
{
	char autor[50];
	char title[100];
	unsigned short year;
	float price;
	CATEGORY2 category;
};


// для Задания 1.3
void printBOOK2(const TBook2* book);


// для Задания 1.4
void editBook2(TBook2* book);
*/


////////////////////////////////////////////////

// для Задания 2

enum eCATEGORY { Detectives = 1, Adventure, Fantastic, Fantasy, History, Sports };

// книга
struct BOOK
{
	char autor[50] = {0};
	char title[100] = {0};
	unsigned short year;
	float price;
	eCATEGORY category;
};

//картотека
struct CARD_INDEX
{
	BOOK** pB;				// указатель на книгу BOOK* pB
	size_t count;		// количество книг
	size_t cap;				// емкость картотеки
};

// функция вывода меню
void outputMenu(int* answer);

// распечатать книгу
void print(const BOOK* book);

// функция для распечатки картотеки
void printBOOK(const CARD_INDEX* pCard);

// функция добавления книги
void addBook(CARD_INDEX* pCard);

// функция добавления полей в книгу
void addFieldsBook(BOOK* book);

// удалить книгу
void deleteBook(CARD_INDEX* pCard);

// добавить в файл картотеку
void addInFile(CARD_INDEX* pCard);

// добавить из файла книги
void addOutFile(CARD_INDEX* pCard);

//////////////////////////////////////////////////////////////////////

// для Задания 3

enum eSwap { autor = 1, title, year, price, category };

void sortByAll(CARD_INDEX* pCard, eSwap numberSort);
//void sortByTitle(CARD_INDEX* pCard, eSwap numberSort);
//void sortByYear(CARD_INDEX* pCard, eSwap numberSort);
//void sortByPrice(CARD_INDEX* pCard, eSwap numberSort);
//void sortByCategory(CARD_INDEX* pCard, eSwap numberSort);