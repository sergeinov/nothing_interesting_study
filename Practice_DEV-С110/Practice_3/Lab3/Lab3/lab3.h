#pragma once

enum CATEGORY{ �������, ���������, �����������, ����������, �������,  �������, ����� };

struct BOOK
{
	char autor[50];
	char title[100];
	int year;
	double price;
	CATEGORY category;
};