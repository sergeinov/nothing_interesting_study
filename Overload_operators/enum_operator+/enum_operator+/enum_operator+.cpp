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

WEEKDAY operator+(WEEKDAY day, const int number)		// ���� day + 2
{
	int temp;											// ��������� ����������
	int week = 7;										// ���� � ������
	day = static_cast<WEEKDAY>((static_cast<int>(day) + number) % week);
	// ��������:
	// ��������������� WEEKDAY day �  ��� int - static_cast<int>(day) // 1
	// ���������� �����		// 1 + 2
	// ��������������� ����� � ��� ������������ - static_cast<WEEKDAY>(3)	// WEDNESDAY
	// ���������� ������������ return static_cast<WEEKDAY>(...)	 // WEDNESDAY

	// ��������, ���� ����� �� ������� ������������ WEEKDAY
	if (day > 7)
	{
		temp = static_cast<int>(day) - week;
		day = static_cast<WEEKDAY>(temp);
	}
	return day;

};

WEEKDAY operator+(const int number, WEEKDAY day)		// ����  2 + day
{
	int temp;											// ��������� ����������
	int week = 7;										// ���� � ������
	day = static_cast<WEEKDAY>((number + static_cast<int>(day)) % week);
	// ������ �������
	// ��������, ���� ����� �� ������� ������������ WEEKDAY
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