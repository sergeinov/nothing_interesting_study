#pragma once

// для задания  1
const int N = 4, M = 4;

void PrintArray(int (*pArr)[M], int sizeN);
//void PrintArray2(int (*pArr2)[][M], int sizeN2, int sizeM2);
void PrintArray2(int **pArr2, int sizeN2, int sizeM2);
//Прототипы функций, используемых в данном задании :
//void VarArgs(int arg1, ...);

void Sort(char* pcFirst, int nNumber, int size,
void(*Swap)(void*, void*), int(*Compare)(void*, void*));
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);


