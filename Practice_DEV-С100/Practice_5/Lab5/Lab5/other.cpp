//#include "other.h"
#define _CRT_SECURE_NO_WARNINGS   //  до всех   #include !!!!
#include  <cstdlib>
#include  <cstring>
#define	  stop __asm nop
#include <iostream>

//Severity	Code	Description	Project	File	Line	Suppression State
//Error	C4996	'strcpy': This function or variable may be unsafe.Consider using strcpy_s instead.
//To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
//See online help for details.Lab5_2020	D : \C++\NEW COURSE(C100 - C110)\C100\LABS\Lab5\Lab5_2020\Lab5_2020\other.cpp	75

//дл€ задани€ 1.2
int x = 10;
int& ref = x;	


// определение функций дл€ задани€  2.1.
// а) по значению
int IncByValue(int value)
{
	return value + 1;
}
// б) по ссылке
int IncByReference(int& value)
{
	if (value == 0) return -1;
	value += 1;
}
// в) по указателю
int IncByPointer(int* value)
{
	if (value == 0) return -1;
	*value += 1;
}


// определение функций дл€ задани€ дл€ задани€  2.2
int Swap(int* nX, int* nY)
{
	if (nX == 0 && nY == 0) return -1;

	int temp = *nX;
	*nX = *nY;
	*nY = temp;
}

int Swap(int& nX, int& nY)
{
	if (nX == 0 && nY == 0) return -1;

	int temp = nX;
	nX = nY;
	nY = temp;
}


// дл€ задани€ 3.1
void PrintArray(const int ar[], size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << ar[i] << " ";
	}
}

// дл€ задани€ 3.2
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

// дл€ задани€ 3.3
int MyStrCmp(const char* arr1, const char* arr2)
{
	int result = 0;
	int result2 = 0;
	while (*arr1 && *arr2) {
		result += static_cast<int>(*arr1);
		arr1++;
		result2 += static_cast<int>(*arr2);
		arr2++;
	}

	return result - result2;
}


//дл€ задани€ 5
int* addr_min(const int* arrMM, size_t size_MM)
{
	const int* p = arrMM;

	for (size_t i = 0; i < size_MM; i++)
	{
		if (*p > arrMM[i]) {
			p = &arrMM[i];
		}
	}
	return (const_cast<int*>(p));
}



///////////////////////////////////////////////////
int square(const int& val) 
{ 
	 int tmp= val * val;
	return  tmp;
}

//------------------------------------------------------
const char* NameOfMonth(int month)
{
	const char* strMonths[] = {"", "January","February","March","April", "May","June","July","August","September","October","November","December"};
	if ((month > 12) || (month < 1)) {
		std::cout << "Wrong month number!" << std::endl;
		return nullptr;
	}
	else {
		return strMonths[month];
	}
	
}
//-----------------------------------------------------------------------
const char* DataStr(int day, int month, int year)
{
	static char resStr[11];		// результат вывода

	char strDay[3];				// дни
	_itoa(day, strDay,10);

	char strMonth[3];			// мес€цы
	_itoa(month, strMonth,10);

	char strYear[5];			// годы
	_itoa(year, strYear, 10);
	stop
	// дни
	if (day<10)					
		strcpy(resStr, "0");
	else 
		strcpy(resStr, "");
	strcat(resStr, strDay);		//обьединение строки день  01
	strcat(resStr, ".");
	// мес€цы
	if (month < 10)
		strcat(resStr, "0");
	strcat(resStr, strMonth);		// обьединение строки мес€ц  01
	strcat(resStr, ".");
	// годы
	strcat(resStr, strYear);		// обьединение строки год
	return resStr;
}





