
/*************************************************************
	������������ ������� �2 ���� �110. �������.
	��������� �� �������

*************************************************************/
#include <iostream>
#include <tchar.h>
//#include <cstdio>
//#include <cstdarg>
#include "other.h"
#include <cmath>


#define	  stop __asm nop
				
int _tmain()
{
	{
		setlocale(LC_ALL, "Rus");
		//������� 1. 
		//��������� �� ������� � �������� ����������.
		//�������� ��� �������� ������� ������ ���������
		//1. �� ���������� ��������� �������
		//int ar[N][M] = {������ ���������������};//��������� - ��� � ��� ������ ���� ������ N � M
		//PrintArray(ar, ... ����� ����, ����������� �������� ��� �����-������ ������);
		std::cout << "������� 1.�..." << std::endl;
		int ar[N][M] = { {1,2,3,4},
						 {4,5,6,7},
						 {12,13,14,15},
						 {21,22,23,24} 
		};
		PrintArray(ar, N);			// ������ �������
			
		//2. � ������������ ��������� ������� (��� ����������� �����������)
		std::cout << "\n������� 1.� ..." << std::endl;

		// ����������� N  �  M
		int** par2 = new int*[N];
		for (size_t i = 0; i < N; i++)
		{
			par2[i] = new int[M];
		}
		PrintArray2(par2, N, M);


		std::cout << "\n����������� ������ ������������� �����������..." << std::endl;
		for (size_t i = 0; i < N; i++)
		{
			delete[] par2[i];
		}
		delete[] par2;
		par2 = 0;

	}
/////////////////////////////////////////////////////////////////////////////
	//������� 2.
	std::cout << "\n������� 2..." << std::endl;
	//�������� ��������� �� ���������� ������ � �������� ��������� �������.
			//�������� ��� ����������������� ���� ����� �������:
			//1.  ... DayOfYear(...)
			//- ����������� ���� ������ (�����,����� � ��� �������� � �������� ����������)
			//� ���������� ���� ����(������������ ��������)
			//2. ... DayOfMonth(...) - ������� ����������� ���������� ���� ���� � ���� ������
			// (��������� ��� � ���������� ���� ���� � �������� ���������� � ������ ������������
			// ���� ������ � ����� ������ � �����-�� ������� �������� ��� �������� ���������� ���������)

			//��������� ����������������� ����� ������� � ������� ���������� ���������:


			//� �������� ���������� ��� �������� ��������� "���������� - ������������" ���.
			//��� �������� "������������" ���� ����� ����� ������� ������� (isLeepYear)
			//��� ����� ������������ � ������ ������� � �������� ������ �� ���������� ����������
			//������ ������������ ���� ����������� ������� nDayTab

	int nDayTab[2][12] = {
		{31,28,31,30,31,30,31,31,30,31,30,31},		//������������ ���
		{31,29,31,30,31,30,31,31,30,31,30,31} };	//���������� ���

	int day = 12;
	int month = 1;
	int year = 2000;
	int dayOfYear = 0;		// ��� ������ ����������  ����������� ��� ����
	
	//����� ������� DayOfYear
	dayOfYear = DayOfYear(day, month, year, nDayTab);
	std::cout << "���������� ���� ����: " << dayOfYear << std::endl;

	//�������� ���������� �������� �������� DayOfMonth
	int resDayMonth;
	int resMonth;
	DayOfMonth(year, dayOfYear, nDayTab, &resDayMonth, &resMonth);
	std::cout << "���� ������: " << resDayMonth << " �����: " << resMonth << std::endl;

	stop
/////////////////////////////////////////////////////////////////////////////
	//������� 3.
	//������� 3�. ������� � ���������� ������ ����������.
	//�������� ������� (���� ��������� VarArgs, �� ������������
	// �������), ������� ��������� ���������� ����� ����������
	// ���� int � ������� �� ������ ����� �������� ���������� �
	// �� ��������.
	// ��������� ����� ������ �������� ������� ��������.
	{
		std::cout << "\n������� 3..." << std::endl;

		int nN1 = 5, nN2 = 11, nN3 = 4, nN4 = 7, nN5 = -1;
		VarArgs(nN1,0);
		std::cout << std::endl;
		VarArgs(nN1,nN2,0);
		std::cout << std::endl;
		VarArgs(nN1,nN2,nN3,nN4,nN5,0);
		stop
		std::cout << std::endl;

		//������� 3�. ������������� ������� 3� � ������� ��������
		// va_start, va_arg, va_end
		std::cout << "\n������� 3.�..." << std::endl;

		VarArgs2(nN1, 0);
		std::cout << std::endl;
		VarArgs2(nN1, nN2, 0);
		std::cout << std::endl;
		VarArgs2(nN1, nN2, nN3, nN4, nN5, 0);

	}
///////////////////////////////////////////////////////////////////
	//���� ��������� �� �������
	{
		//������� 4. ��������� �� �������. "�����������".
		//�������� �������:
		//1)Sum - ��������� ��� �������� double � ���������� �����
		//���� ��������
		//2)Sub- ��������� ��� �������� double � ���������� ��������
		//���� ��������
		//3)Mul - *
		//4)Div - /
		//5)� ��� ���������� � ������� ������ ������������ ������� ����������� ����������
		//		- pow(). ��������� 1: �������� ������� ��������� � <cmath>.
		//		��������� 2: ����������� ���������� ������������� ��������� �������������
		//		��������� ���� �������, � ��� ����������� ������������ ��������� �� 
		//		double pow(double, double);

		//������������ ������������	��������� �����������:
		//���� ������������ ����� ������������ �������� ������ ������������,
		//�� ����� ������� ��� �������� � ���� ��������
		//� �� �������� ���������. ��������� ��������� ����������� ������
		//��������������� ����� ������� �� ���������.
		//������������� ����������� ����� ������������������ ����� ��������
		std::cout << "\n\n������� 4..." << std::endl;
		char question;								// ��� ���������� �����
		char sign;									// �������� ���������
		double number1, number2;					// ������� ��������� �������
		double res;									// ���������/�����
		double (*pf)(double, double) = nullptr;		// ��������� �� �������  pf

		std::cout << "�����������." << std::endl;
		do
		{
			std::cout << "������� ������ �����:" << std::endl;
			std::cin >> number1;
			std::cout << "������� ����:" << std::endl;
			std::cin >> sign;
			std::cout << "������� ������ �����:" << std::endl;
			std::cin >> number2;

			switch (sign) {
			case '+':
				pf = &Sum;							// ��������� ��������� ����� �������
				//res = (*pf)(number1, number2);		//  ������� ������� � ��������� ��������� res
				//std::cout << res << std::endl;		//  ����������� ��������� res
				break;

			case '-':
				pf = &Sub;							// ��������� ��������� ����� �������
				//res = (*pf)(number1, number2);		//  ������� ������� � ��������� ��������� res
				//std::cout << res << std::endl;		//  ����������� ��������� res
				break;
			case '*':
				pf = &Mul;							// ��������� ��������� ����� �������
				//res = (*pf)(number1, number2);		//  ������� ������� � ��������� ��������� res
				//std::cout << res << std::endl;		//  ����������� ��������� res
				break;
			case '/':
				pf = &Div;							// ��������� ��������� ����� �������
				//res = (*pf)(number1, number2);		//  ������� ������� � ��������� ��������� res
				//std::cout << res << std::endl;		//  ����������� ��������� res
				break;
			case '^':
				pf = &PowDouble;							// ��������� ��������� ����� �������
				//res = (*pf)(number1, number2);		//  ������� ������� � ��������� ��������� res
				//std::cout << res << std::endl;		//  ����������� ��������� res
				break;
			default:
				std::cout << "�������� ���� ��������!" << std::endl;
				break;
			}
			if (pf)
			{
				res = (*pf)(number1, number2);
				std::cout << res << std::endl;
			}
	
			stop

			std::cout << "������� 'q' ��� ������. ��� ����� ������ ��� �����������" << std::endl;
			std::cin >> question;
		} while (!(question == 'q'));
		
		// �������� ���������
		pf = nullptr;
	}
///////////////////////////////////////////////////////////////////
	{
		//������� 5. ��������� �� ������� � �������� ���������.
		//���� ��������� ������� ���������� ����� �������� - Sort.
		//������� ��������� ��������� ���������:
		//1) ��������� �� ������ ����������� �������
		//2) ���������� ����������� ���������
		//3) ������ �������� � ������
		//4) ��������� �� ������� ������������ ���������
		//5) ��������� �� ������� ��������� ���������

		//5a. �������� ������� ������������ ���� ����� �������� -
		// SwapInt, ������� ��������� ��� void ��������� � 
		//������ �������� �������

		//�������� ������� ��������� ���� ����� �������� -
		// CmpInt, ������� ��������� ��� void ��������� �
		//���������� int ��������� ���������: 
		//<0 - ������ ������� ������, ��� ������
		//=0 - �����
		//>0 - ������ ������� ������, ��� ������
		std::cout << "\n������� 5.a..." << std::endl;

		int nAr[] = { 4, 45, 22, 3, 9, 10, 55 };	//������ ��� ����������

		//������ ��������� �������
		std::cout << "�������� ������:" << std::endl;
		for (size_t i = 0; i < sizeof(nAr) / sizeof(nAr[0]); i++)
		{
			std::cout << nAr[i] << " ";
		}

		//����� ����������
		int nTotal = sizeof(nAr) / sizeof(nAr[0]);		//���������� ��������� � �������
		Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);

		//������ ����������� ����������
		//������ ��������� �������
		std::cout << "\n��������������� ������:" << std::endl;
		for (size_t i = 0; i < sizeof(nAr) / sizeof(nAr[0]); i++)
		{
			std::cout << nAr[i] << " ";
		}

		stop

		
		//������� 5�. �� �������� � 5� �������� ���������������
		//������� - SwapDouble � CmpDouble � �������� ������� Sort
		//��� ���������� ������� ������������ ��������.
		std::cout << "\n\n������� 5.�..." << std::endl;
		double nAr2[] = { 4.4, 45.2, 22.1, 3.3, 3.1, 4.2, 5.9 };	//������ ��� ����������

		//������ ��������� �������
		std::cout << "�������� ������:" << std::endl;
		for (size_t i = 0; i < sizeof(nAr2) / sizeof(nAr2[0]); i++)
		{
			std::cout << nAr2[i] << " ";
		}
		//����� ����������
		int nTotal2 = sizeof(nAr2) / sizeof(nAr2[0]);		//���������� ��������� � �������
		Sort(reinterpret_cast<char*>(&nAr2[0]), nTotal2, sizeof(double), SwapDouble, CmpDouble);

		//������ ����������� ����������
		//������ ��������� �������
		std::cout << "\n��������������� ������:" << std::endl;
		for (size_t i = 0; i < sizeof(nAr2) / sizeof(nAr2[0]); i++)
		{
			std::cout << nAr2[i] << " ";
		}

		stop


		/*
		//������� 5�*. �� �������� � 5� �������� ���������������
		//������� - SwapStr � CmpStr � �������� ������� Sort
		//��� ���������� ������� ���������� �� ������.

		const char* arStr[] = { "QQQ", "SDF", "ABC","Abba", "ENFR","En",. . . };
		//���������:
		//� ������� ������� ����� ������ �����, ���� �������� ����� �������,
		// �� �������������� ���������� ����� ������������� (!!!)
		Sort(reinterpret_cast<char*>(const_cast<???>(&arStr[0])), nTotal, sizeof(???), SwapStr, CmpStr);
		*/
	}
///////////////////////////////////////////////////////////////////
	{
		std::cout << "\n\n������� 6..." << std::endl;
		//������� 6. ������� ���������� �� �������.
		//�������� ��������� ������� ����
		//const char* GetString1();
		//const char* GetString2();
		//		...., ������ �� ������� ���������� ��������� �� ���� ������
		//(��������� - ����� ����� �� ������ ����� ���������� �� �������)
		

		//�������� � ������������������ ������ ���������� �� �������
		//GetString1,GetString2...
		const char* res2 = nullptr;																// ��������� ���  ������ ����������
		const char* (*FuncAr[]) (void) = {GetString0, GetString1, GetString2, GetString3};		// ������ ���������� �� �������

		//������� ����� �������, ������� �� ������ �������:
		int n;
		std::cout << "������� ����� ������� 0,1,2 ��� 3: " << std::endl;
		std::cin >> n;

		// �������� �������
		if (n >=0 && (sizeof(FuncAr) / sizeof(char* (*) (void))))
		{
			const char* res2 = FuncAr[n]();				// ����� � ������������ ������

			//������������ ���������
			while (*res2)
			{
				std::cout << *res2;
				res2++;
			}
			if (n == 3)
			{
				delete[] res2;
			}
		}

	}
////////////////////////////////////////////////////////////////////////////
	{
		std::cout << "\n\n������� 7..." << std::endl;
		//������� 7*.
		//�������� ���������� ������ (����������� ����������� � ��������
		//���������� ���������), ��������� ��� ����������.
		//�������� �������, ������� ��������� � ������ ����� �������� ������ (!) ��� �������,
		//��� ������ �������� � ������� ��� ���. 
		//���������: ��� ���� ������  ������� ������ �����������!
		//��� �������� �������� �������, ������� ������� �������� ���� ��������� �� �����
		size_t K = 5;
		int* pAr = new int[K];
		
		// ���������� �������
		for (size_t i = 0; i < K; i++)
		{
			pAr[i] = (i * 2) + 1;
		}
		// ����� ������������� �������
		std::cout << "������������ ������:" << std::endl;
		for (size_t i = 0; i < K; i++)
		{
			std::cout << pAr[i] << " ";
		}

		// ��������� �������
		addVilueInArr(pAr, K);

		std::cout << "\n���������� ������:" << std::endl;
		for (size_t i = 0; i < K; i++)
		{
			std::cout << pAr[i] << " ";
		}
	}

///////////////////////////////////////////////////////////////////////////

	//������� 8.  
	{
		std::cout << "\n\n������� 8..." << std::endl;
		//����������� �������.
		
		

		//8.1.�������� ����������� ������� ���������� ����� ������ N ����������� �����. 
		int value = 7;
		value = sumValue(value);
		std::cout << "����� ������������ ����� ����� = " << value << std::endl;

		//8.2.�������� ����������� ������� ���������� ���������� ���� 10-����� ������������ ����� 
		int value2 = 4563867234;
		int result = 0;
		result = quantityNumber(value2);
		std::cout << "\n���������� ���� ������������ �����: "  << result << std::endl;

		//8.3.�������� ����������� ������� ��� ������ �� ����� ������ � �������� �������. 
		const char str[] = "�������";
		std::cout << "\n�������" << std::endl;
		reversStr(str);

		//8.4.�������� ����������� ������� ��� ������ �� ����� ������ � ������ (!) �������.
		const char str2[] = "������ ����";
		std::cout << "\n\n������ ����" << std::endl;
		reversStr2(str2);
		stop
	}

	return 0;
}//main

