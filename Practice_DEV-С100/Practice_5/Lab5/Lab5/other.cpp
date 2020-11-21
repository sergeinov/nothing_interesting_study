//#include "other.h"


#define _CRT_SECURE_NO_WARNINGS 1
//#include  <cstdlib>
#include  <cstring>
#define	  stop __asm nop
#include <iostream>

//Severity	Code	Description	Project	File	Line	Suppression State
//Error	C4996	'strcpy': This function or variable may be unsafe.Consider using strcpy_s instead.
//To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
//See online help for details.Lab5_2020	D : \C++\NEW COURSE(C100 - C110)\C100\LABS\Lab5\Lab5_2020\Lab5_2020\other.cpp	75

//для задания 1.2
int x = 10;
int& ref = x;	


// определение функций для задания  2.1.
// а) по значению
int IncByValue(int value)
{
	value += 1;
	return value;
}
// б) по ссылке
void IncByReference(int& value)
{
	value += 1;
}
// в) по указателю
void IncByPointer(int* value)
{
	*value += 1;
}


// определение функций для задания для задания  2.2
void Swap(int* nX, int* nY)
{
	int temp = *nX;
	*nX = *nY;
	*nY = temp;
}

void Swap(int& nX, int& nY)
{
	int temp = nX;
	nX = nY;
	nY = temp;
}


// для задания 3.1
void PrintArray(const int ar[], size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << ar[i] << " ";
	}
}

// для задания 3.2
int Min(const int ar[], size_t size2)
{
	int max = ar[0];

	for (size_t i = 1; i < size2; i++)
	{
		if (max > ar[i]) {
			max = ar[i];
		}
	}
	return max;
}

// для задания 3.3
int MyStrCmp(const char* arr1, const char* arr2)
{
	while (*arr1 || *arr2) {
		if ((*arr1 > * arr2) || (*arr1 != 0 && *arr2 == 0))
		{
			return 1;
		}
		else if ((*arr1 < *arr2) || (*arr1 == 0 && *arr2 != 0)) {
			return -1;
		}
		arr1++;
		arr2++;
	}

	return 0;
}


//для задания 5
int* addr_min(const int* arrMM, size_t size_MM)
{
	const int* pMaxInt = arrMM;

	for (size_t i = 0; i < size_MM; i++)
	{
		if (*pMaxInt > arrMM[i]) {
			pMaxInt = &arrMM[i];
		}
	}
	// снимает константность у указателя
	return (const_cast<int*>(pMaxInt));
}



// для задания 1.5
int square(const int& val) 
{ 
	 int tmp= val * val;
	return  tmp;
}

// для задания 4.1
const char* NameOfMonth(int month)
{
	const char* strMonths[] = {"", "January","February","March","April", \
									"May","June","July","August","September", \
									"October","November","December"};

	if ((month > 12) || (month < 1)) {
		std::cout << "Неверный номер месяца!" << std::endl;
		return nullptr;
	}
	else {
		return strMonths[month];
	}
	
}

// для задания 4.2
const char* DataStr(int day, int month, int year)
{
	static char result[11];		// результат вывода

	char strDay[3];				// дни
	_itoa(day, strDay,10);

	char strMonth[3];			// месяцы
	_itoa(month, strMonth,10);

	char strYear[5];			// годы
	_itoa(year, strYear, 10);
	stop
	// дни
	if (day<10)					
		strcpy(result, "0");
	else 
		strcpy(result, "");
	strcat(result, strDay);		//обьединение строки день  01
	strcat(result, ".");
	// месяцы
	if (month < 10)
		strcat(result, "0");
	strcat(result, strMonth);		// обьединение строки месяц  01
	strcat(result, ".");
	// годы
	strcat(result, strYear);		// обьединение строки год

	return result;
}



// для задания 6

void searchEvenAndOddnumber(const int* arr, size_t size_arr, int searchNumber)

{
	int result = 0;

	for (int i = 0; i < size_arr; i++)
	{
		if (searchNumber == arr[i]) {
			result++;
		}
	}
	if (result % 2 == 0) {
		std::cout << searchNumber << " встречается в массиве четное число раз" << std::endl;
	}
	else {
		std::cout << searchNumber << " встречается в массиве нечетное число раз" << std::endl;
	}
}