#include "other.h"
#include <iostream>
#include <cstdarg>
#include <cmath>
///////////////////////////////////////////////////

//Подсказка-заготовка для задания 5а
//Без использования макросов
/*
void VarArgs(int arg1,...)
{
	int number = 0;	//счетчик элементов
	//Объявите указатель на int и инициализируйте его адресом
	//первого аргумента
	
	//Пока не достигнут конец списка:
	// а) печать значения очередного аргумента
	// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
	// в) увеличить счетчик элементов




	//Печать числа элементов

}
*/
//#include "other.h"

///////////////////////////////////////////////////
// для задания  1
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
	// заполняем значениями элементы и выводим
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
// для задания  2
int DayOfYear(int day, int month, int year, int(*nDayTab)[12]) 
{
	bool isLeapYear = ((year % 400 == 0) || ((year % 4 == 0) && (!(year % 100 == 0))));		// проверка высокосного и не высокосного года
	int res = 0;		// для записи результата  порядкового дня года
	if (isLeapYear == 1)
	{
		for (size_t i = 0; i < month; i++)
		{
			res += nDayTab[1][i];			// прибавляем количество дней в месяце из массива
		}
		res += day;							// прибавляем текущий день месяца 
	}
	else {
		for (size_t i = 0; i < month; i++)
		{
			res += nDayTab[0][i];			// прибавляем количество дней в месяце из массива
		}
		res += day;							// прибавляем текущий день месяца 
	}

	return res;
};

void DayOfMonth(int year, int dayOfYear, int(*nDayTab)[12], int* resDayMonth, int* resMonth)
{
	int count = 0 ;			// счетчик для  месяца
	bool isLeapYear = ((year % 400 == 0) || ((year % 4 == 0) && (!(year % 100 == 0))));		// проверка высокосного и не высокосного года

	if (isLeapYear == 1)
	{
		while (!(dayOfYear <= 31))
		{
			dayOfYear -= nDayTab[1][count];		// отнимаем от порядкового дня года количество дней в месяце
			count++;							// увеличиваем месяц на один
		}
		*resDayMonth = dayOfYear;		// присваиваем результат  дня месяца
		*resMonth = count;				// присваиваем результат  месяца
	}
	else {
		while (!(dayOfYear <= 31))
		{
			dayOfYear -= nDayTab[0][count];		// отнимаем от порядкового дня года количество дней в месяце
			count++;							// увеличиваем месяц на один
		}		
		*resDayMonth = dayOfYear;		// присваиваем результат  дня месяца
		*resMonth = count;				// присваиваем результат  месяца
	}

};

///////////////////////////////////////////////////
// для задания  3
void __cdecl VarArgs(int arg1, ...) 
{
	//int count;
	int* p = &arg1;		// вспомогательный указатель на первый элемент

	while (*p)
	{
		std::cout << *p << " ";		// печатаем значение
		p++;						// перемещаем указатель
	}
}
// для задания  3.б
void __cdecl VarArgs2(int arg1, ...) 
{
	int i = arg1;
	va_list p;				// универсальный указатель
	va_start(p, arg1);		// ставим указатель на первый элемент

	while (i != 0)
	{
		std::cout << i << " ";	// печатаем значение
		i = va_arg(p, int);		// перемещаем указатель на следующий и присваиваем  i
	}
	va_end(p);					// обнуляем указатель
}

///////////////////////////////////////////////////
//Задание 4
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
//Задание 5.a
void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1) * size;
			if ((*Compare)(pPrevious, pCurrent) > 0)//требуется
												//переставить
				(*Swap)(pPrevious, pCurrent);
		}
}

void SwapInt(void* p1, void* p2)
{
	int* pp1 = static_cast<int*>(p1);	// приводим указатель к требуемому типу, с которым работаем
	int* pp2 = static_cast<int*>(p2);

	// обмениваем значения
	int temp = *pp1;
	*pp1 = *pp2;
	*pp1 = temp;
}

int CmpInt(void* p1, void* p2)
{
	int nResult = 0;
	int* pp1 = static_cast<int*>(p1);	// приводим указатель к требуемому типу, с которым работаем
	int* pp2 = static_cast<int*>(p2);

	// сравнение символов
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

//Задание 5.б
void SwapDouble(void* p1, void* p2)
{
	double* pp1 = static_cast<double*>(p1);	// приводим указатель к требуемому типу, с которым работаем
	double* pp2 = static_cast<double*>(p2);

	// обмениваем значения
	double temp = *pp1;
	*pp1 = *pp2;
	*pp1 = temp;
}

int CmpDouble(void* p1, void* p2)
{
	int nResult = 0;
	double* pp1 = static_cast<double*>(p1);	// приводим указатель к требуемому типу, с которым работаем
	double* pp2 = static_cast<double*>(p2);

	// сравнение символов
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
//Задание 6
const char* GetString0()
{
	return "Вызов функции GetString 0!";
};
const char* GetString1()
{
	return "Вызов функции GetString 1!";
};
const char* GetString2()
{
	return "Вызов функции GetString 2!";
};
const char* GetString3()
{
	return "Вызов функции GetString 3!";
};


///////////////////////////////////////////////////
//Задание 7*.
void addVilueInArr(int* pAr, size_t K)
{
	int n;
	// узнаем какое число добавляем
	std::cout << "\nКакое число добавить в массив?" << std::endl;
	std::cin >> n;

	// увеличиваем размер массива
	K += 1;

	// выделяем вспомогательный новый блок памяти
	int* temp = new int[K];

	// переписываем в новый массив содержимое
	for (size_t i = 0; i < K; i++)
	{
		temp[i] = pAr[i];
	}

	// добавили значение в новый увеличенный массив
	temp[K - 1] = n;

	// удаляем старый массив
	delete[] pAr;

	// перенаправили указатель на новый массив
	pAr = temp;

	// Удалили указатель вспомогательного массива
	//delete[] temp;
	temp = 0;

};


///////////////////////////////////////////////////
//Задание 8.  
int sumValue(int value)
{
	if (value <= 1)		// условие для завершения рекурсии
	{
		return 1;
	}
	else {
		 return value + sumValue(value - 1);		// складываем числа
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
		//str++;				// получается вывод без последней буквы
		//reversStr(str);
		reversStr(str + 1);
		std::cout << *str;
	}
};