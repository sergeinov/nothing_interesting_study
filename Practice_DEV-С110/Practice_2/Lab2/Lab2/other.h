#pragma once
///////////////////////////////////////////////////
// дл€ задани€  1
const int N = 4, M = 4;

void PrintArray(int (*pArr)[M], size_t sizeN);
void PrintArray2(int **pArr2, size_t sizeN2, size_t sizeM2);

///////////////////////////////////////////////////
// дл€ задани€  3
void _cdecl VarArgs(int arg1, ...);

// дл€ задани€  3.б
void _cdecl VarArgs2(int arg1, ...);

///////////////////////////////////////////////////
//«адание 4
double Sum(double number1, double number2);
double Sub(double number1, double number2);
double Mul(double number1, double number2);
double Div(double number1, double number2);
double PowDouble(double number1, double number2);


///////////////////////////////////////////////////
void Sort(char* pcFirst, int nNumber, int size,
void(*Swap)(void*, void*), int(*Compare)(void*, void*));
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);


