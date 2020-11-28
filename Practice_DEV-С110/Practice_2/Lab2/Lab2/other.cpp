#include "other.h"
#include <iostream>
#include <cstdarg>
#include <cmath>
///////////////////////////////////////////////////

//���������-��������� ��� ������� 5�
//��� ������������� ��������
/*
void VarArgs(int arg1,...)
{
	int number = 0;	//������� ���������
	//�������� ��������� �� int � ��������������� ��� �������
	//������� ���������
	
	//���� �� ��������� ����� ������:
	// �) ������ �������� ���������� ���������
	// �) ����������� ��������� (�� ������ ��������� ��
	//��������� �������� ������)
	// �) ��������� ������� ���������




	//������ ����� ���������

}
*/
//#include "other.h"

///////////////////////////////////////////////////
// ��� �������  1
void PrintArray(int (*pArr)[M], size_t sizeN) 
{
	for (size_t i = 0; i < sizeN; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << pArr[i][j] << "  ";
		}
		std::cout << std::endl;
	}
};

void PrintArray2(int **pArr2, size_t sizeN, size_t sizeM) 
{
	// ��������� ���������� �������� � �������
	for (size_t i = 0; i < sizeN; i++)
	{
		for (size_t j = 0; j < sizeN ; j++)
		{
			pArr2[i][j] = i * j+ 1;
			std::cout << pArr2[i][j] << "  ";
		}
		std::cout << std::endl;
	}
};
///////////////////////////////////////////////////
// ��� �������  3
void __cdecl VarArgs(int arg1, ...) 
{
	int count;
	int* p = &arg1;		// ��������������� ��������� �� ������ �������

	while (*p)
	{
		std::cout << *p << " ";		// �������� ��������
		p++;						// ���������� ���������
	}
}
// ��� �������  3.�
void __cdecl VarArgs2(int arg1, ...) 
{
	int i = arg1;
	va_list p;				// ������������� ���������
	va_start(p, arg1);		// ������ ��������� �� ������ �������

	while (i != 0)
	{
		std::cout << i << " ";	// �������� ��������
		i = va_arg(p, int);		// ���������� ��������� �� ��������� � �����������  i
	}
	va_end(p);					// �������� ���������
}

///////////////////////////////////////////////////
//������� 4
double Sum(double number1, double number2)
{
	return number1 + number2;
};
double Sub(double number1, double number2)
{
	return	number1 - number2;
};
double Mul(double number1, double number2)
{
	return	number1 * number2;
};
double Div(double number1, double number2)
{
	return	number1 / number2;
};
double PowDouble(double number1, double number2)
{
	return pow(number1, number2);
};



///////////////////////////////////////////////////
void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1)*size;
			if ((*Compare)(pPrevious, pCurrent) > 0)//���������
												//�����������
				(*Swap)(pPrevious, pCurrent);
		}
}

void SwapInt(void* p1, void* p2)
{


}

/*int CmpInt(void* p1, void* p2)
{
	int nResult;




	return nResult;
}*/



