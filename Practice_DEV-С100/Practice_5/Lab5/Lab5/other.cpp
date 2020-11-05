//#include "other.h"
#define _CRT_SECURE_NO_WARNINGS   //  до всех   #include !!!!
#include  <cstdlib>
#include  <cstring>
#define	  stop __asm nop

//Severity	Code	Description	Project	File	Line	Suppression State
//Error	C4996	'strcpy': This function or variable may be unsafe.Consider using strcpy_s instead.
//To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
//See online help for details.Lab5_2020	D : \C++\NEW COURSE(C100 - C110)\C100\LABS\Lab5\Lab5_2020\Lab5_2020\other.cpp	75

int x = 10;
int& ref = x;	// определение переменной для задания 1.2


// определение функций для задания  2.1.
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


// определение функций для задания для задания  2.2
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
	if ((month > 12) || (month < 1))
		return nullptr;
	else
		return strMonths[month];
	
}
//-----------------------------------------------------------------------
const char* DataStr(int day, int month, int year)
{
	static char resStr[11];
	char strDay[3];
	_itoa(day, strDay,10);
	char strMonth[3];
	_itoa(month, strMonth,10);
	char strYear[5];
	_itoa(year, strYear, 10);
	stop
	if (day<10)
		strcpy(resStr, "0");
	else 
		strcpy(resStr, "");
	strcat(resStr, strDay);
	strcat(resStr, ".");
	if (month < 10)
		strcat(resStr, "0");
	strcat(resStr, strMonth);
	strcat(resStr, ".");
	strcat(resStr, strYear);
	return resStr;
}





