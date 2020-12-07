#pragma once

enum CATEGORY { Боевики = 1, Детективы, Приключения, Фантастика, Fantasy, История, Спорт };

struct BOOK
{
	char autor[50] = "Сергей Семонович Труш";
	char title[100] = "Трясина";
	int year = 2011;
	float price = 55.45;
	CATEGORY category = Fantasy;
};


// для Задания 1.3
void printBOOK(const BOOK* book);


// для Задания 1.4
void editBook(BOOK* book);