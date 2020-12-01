#pragma once
///////////////////////////////////////////////////
// для задания  1
const int N = 4, M = 4;

void PrintArray(int (*pArr)[M], size_t sizeN);
void PrintArray2(int **pArr2, size_t sizeN2, size_t sizeM2);

///////////////////////////////////////////////////
//Задание 2.
int DayOfYear(int day, int month, int year, int (*nDayTab)[12]);

void DayOfMonth(int year, int dayOfYear, int (*nDayTab)[12], int* resDayMonth, int* resMonth);

///////////////////////////////////////////////////
// для задания  3
void _cdecl VarArgs(int arg1, ...);

// для задания  3.б
void _cdecl VarArgs2(int arg1, ...);

///////////////////////////////////////////////////
//Задание 4
double Sum(double number1, double number2);
double Sub(double number1, double number2);
double Mul(double number1, double number2);
double Div(double number1, double number2);
double PowDouble(double number1, double number2);


///////////////////////////////////////////////////
//Задание 5.a
void Sort(char* pcFirst, int nNumber, int size,
		  void(*Swap)(void*, void*), int(*Compare)(void*, void*));

void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);

//Задание 5.б
void SwapDouble(void* p1, void* p2);
int CmpDouble(void* p1, void* p2);

///////////////////////////////////////////////////
//Задание 6
const char* GetString0();
const char* GetString1();
const char* GetString2();
const char* GetString3();

///////////////////////////////////////////////////
//Задание 7*.
const int K = 5;
void addVilueInArr(int* pAr, size_t K);

///////////////////////////////////////////////////
//Задание 8.  
int sumValue(int value);

int quantityNumber(int value2);

void reversStr(const char* str);