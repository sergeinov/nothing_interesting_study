#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

enum WEEKDAY
{
	SUNDAY = 1,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAT,
	FRIDAY,
	SATURDAY
};

WEEKDAY operator+(WEEKDAY day, const int number)		// если day + 2
{
	int temp;											// временная переменная
	int week = 7;										// дней в неделе
	day = static_cast<WEEKDAY>((static_cast<int>(day) + number) % week);
	// Описание:
	// преобразовываем WEEKDAY day в  тип int - static_cast<int>(day) // 1
	// складываем числа		// 1 + 2
	// преобразовываем число в тип перечисления - static_cast<WEEKDAY>(3)	// WEDNESDAY
	// возвращаем перечисление return static_cast<WEEKDAY>(...)	 // WEDNESDAY

	// проверка, если вышли за границы перечисления WEEKDAY
	if (day > 7)
	{
		temp = static_cast<int>(day) - week;
		day = static_cast<WEEKDAY>(temp);
	}
	return day;

};

WEEKDAY operator+(const int number, WEEKDAY day)		// если  2 + day
{
	int temp;											// временная переменная
	int week = 7;										// дней в неделе
	day = static_cast<WEEKDAY>((number + static_cast<int>(day)) % week);
	// другой вариант
	// проверка, если вышли за границы перечисления WEEKDAY
	/*if (day > 7)
	{
		temp = static_cast<int>(day) - week;
		day = static_cast<WEEKDAY>(temp);
	}*/
	return day;
};


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".1251");

	WEEKDAY d = MONDAY;
	d = d + 2;
	d = 5 + d;

	std::cout << d << std::endl;

	return 0;
}