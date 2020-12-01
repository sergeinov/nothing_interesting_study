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
// ��� �������  2
int DayOfYear(int day, int month, int year, int(*nDayTab)[12]) 
{
	bool isLeapYear = ((year % 400 == 0) || ((year % 4 == 0) && (!(year % 100 == 0))));		// �������� ����������� � �� ����������� ����
	int res = 0;		// ��� ������ ����������  ����������� ��� ����
	if (isLeapYear == 1)
	{
		for (size_t i = 0; i < month; i++)
		{
			res += nDayTab[1][i];			// ���������� ���������� ���� � ������ �� �������
		}
		res += day;							// ���������� ������� ���� ������ 
	}
	else {
		for (size_t i = 0; i < month; i++)
		{
			res += nDayTab[0][i];			// ���������� ���������� ���� � ������ �� �������
		}
		res += day;							// ���������� ������� ���� ������ 
	}

	return res;
};

void DayOfMonth(int year, int dayOfYear, int(*nDayTab)[12], int* resDayMonth, int* resMonth)
{
	int count = 0 ;			// ������� ���  ������
	bool isLeapYear = ((year % 400 == 0) || ((year % 4 == 0) && (!(year % 100 == 0))));		// �������� ����������� � �� ����������� ����

	if (isLeapYear == 1)
	{
		while (!(dayOfYear <= 31))
		{
			dayOfYear -= nDayTab[1][count];		// �������� �� ����������� ��� ���� ���������� ���� � ������
			count++;							// ����������� ����� �� ����
		}
		*resDayMonth = dayOfYear;		// ����������� ���������  ��� ������
		*resMonth = count;				// ����������� ���������  ������
	}
	else {
		while (!(dayOfYear <= 31))
		{
			dayOfYear -= nDayTab[0][count];		// �������� �� ����������� ��� ���� ���������� ���� � ������
			count++;							// ����������� ����� �� ����
		}		
		*resDayMonth = dayOfYear;		// ����������� ���������  ��� ������
		*resMonth = count;				// ����������� ���������  ������
	}

};

///////////////////////////////////////////////////
// ��� �������  3
void __cdecl VarArgs(int arg1, ...) 
{
	//int count;
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
//������� 5.a
void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1) * size;
			if ((*Compare)(pPrevious, pCurrent) > 0)//���������
												//�����������
				(*Swap)(pPrevious, pCurrent);
		}
}

void SwapInt(void* p1, void* p2)
{
	int* pp1 = static_cast<int*>(p1);	// �������� ��������� � ���������� ����, � ������� ��������
	int* pp2 = static_cast<int*>(p2);

	// ���������� ��������
	int temp = *pp1;
	*pp1 = *pp2;
	*pp1 = temp;
}

int CmpInt(void* p1, void* p2)
{
	int nResult = 0;
	int* pp1 = static_cast<int*>(p1);	// �������� ��������� � ���������� ����, � ������� ��������
	int* pp2 = static_cast<int*>(p2);

	// ��������� ��������
	if (*pp1 == *pp2)
	{
		nResult = 0;
	} else if(*pp1 > *pp2) 
	{
		nResult = 1;
	}
	else {
		nResult = -1;
	}

	return nResult;
}

//������� 5.�
void SwapDouble(void* p1, void* p2)
{
	double* pp1 = static_cast<double*>(p1);	// �������� ��������� � ���������� ����, � ������� ��������
	double* pp2 = static_cast<double*>(p2);

	// ���������� ��������
	double temp = *pp1;
	*pp1 = *pp2;
	*pp1 = temp;
}

int CmpDouble(void* p1, void* p2)
{
	int nResult = 0;
	double* pp1 = static_cast<double*>(p1);	// �������� ��������� � ���������� ����, � ������� ��������
	double* pp2 = static_cast<double*>(p2);

	// ��������� ��������
	if (*pp1 == *pp2)
	{
		nResult = 0;
	}
	else if (*pp1 > * pp2)
	{
		nResult = 1;
	}
	else {
		nResult = -1;
	}

	return nResult;
}

///////////////////////////////////////////////////
//������� 6
const char* GetString0()
{
	return "����� ������� GetString 0!";
};
const char* GetString1()
{
	return "����� ������� GetString 1!";
};
const char* GetString2()
{
	return "����� ������� GetString 2!";
};
const char* GetString3()
{
	return "����� ������� GetString 3!";
};


///////////////////////////////////////////////////
//������� 7*.
void addVilueInArr(int* pAr, size_t K)
{
	int n;
	// ������ ����� ����� ���������
	std::cout << "\n����� ����� �������� � ������?" << std::endl;
	std::cin >> n;

	// ����������� ������ �������
	K += 1;

	// �������� ��������������� ����� ���� ������
	int* temp = new int[K];

	// ������������ � ����� ������ ����������
	for (size_t i = 0; i < K; i++)
	{
		temp[i] = pAr[i];
	}

	// �������� �������� � ����� ����������� ������
	temp[K - 1] = n;

	// ������� ������ ������
	delete[] pAr;

	// ������������� ��������� �� ����� ������
	pAr = temp;

	// ������� ��������� ���������������� �������
	//delete[] temp;
	temp = 0;

};


///////////////////////////////////////////////////
//������� 8.  
int sumValue(int value)
{
	if (value <= 1)		// ������� ��� ���������� ��������
	{
		return 1;
	}
	else {
		 return value + sumValue(value - 1);		// ���������� �����
	}
};

int quantityNumber(int value2)
{
	if (value2 <= 1)
	{
		return 1;
	}
	else {
		return quantityNumber(value2 / 10) + 1;
	}
};


void reversStr(const char* str)
{
	if (*str)
	{	
		//str++;				// ���������� ����� ��� ��������� �����
		//reversStr(str);
		reversStr(str + 1);
		std::cout << *str;
	}
};