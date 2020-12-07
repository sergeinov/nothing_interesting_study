#pragma once

enum CATEGORY{ Боевики, Детективы, Приключения, Фантастика, Фэнтези,  История, Спорт };

struct BOOK
{
	char autor[50];
	char title[100];
	int year;
	double price;
	CATEGORY category;
};