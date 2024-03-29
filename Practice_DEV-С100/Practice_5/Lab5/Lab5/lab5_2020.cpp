
/*************************************************************
	������������ ������� �5. �������.
	����������, �����������, �����.
	�������� ����������. ����������� ��������.
	
*************************************************************/
#include <iostream>
#include <tchar.h>
//#include <cstdio>
//#include <cstdarg>
#include "other.h"


#define	  stop __asm nop

int _tmain()
{
	setlocale(LC_ALL, "Russian");
	/////////////////////////////////////////////////////////////////////////////
	// ������� 1. ������.
	// 1.1. �������� ������ �� ��� double. ����������� ������ �������� ��������
	double value = 2.5;
	double& refVal = value;
	refVal = 3.5;


	// 1.2. ����������������  ��������� �������. 
	//��� ������� �������, ����� linker �� ������� ������ ��� �������� exe-�����?
	// ���������: ref - ��� ������� �� ��������� � ������� ����� ������!
	//���������, ��� ���� �������� ��� ������� ������, � ��� �� ����������.
	

	ref++;		// 11 

	// 1.3. ���������������� ��������� ������. 
	//��� ������� �������, ����� ���������� �� ������� ������ 
	//int& ref1 = 1;

	const int& ref1 = 1;			// ������� �����, �������� ������ �� sizeof(int)

	// 1.4. ����� ���������:
	char c='A';
	char* pc = &c;

	//�������� ������ �� ���������. ����������� ������ ��������
	//�) �������� �� ������
	//�) ��� �����

	char*& refPc = pc;
	*refPc = 'B';
	refPc++;



	 // 1.5. �������� � ���������� �������, ����������� ������� �����, ����������� � �������� ���������.
	 //  �������� ������ ���� �������. �������� ������� � ��������� ���� �����������
	//��������� (!!!):
	// ���������� ������� ������� �������� � ������������ ���� (.h),
	// � ����������� �������- � ���� ���������� (.cpp)
	// � ������� ����������� ����� other.cpp � other.h. 
	//��� ����� ����� ������������ ��� ����������  ����� �������.
	 {
		//std::cout << "\n������� 1.5" << std::endl;
		int x = 10;
		int res1 = square(x);	 // 100		// ����������� const& int � ������� & int
		int res2 = square(5);    // 5		// 5 ��� ����������� �������� �� ������
		stop
	}


////////////////////////////////////////////////////////////////////////////	
	
	//������� 2. ������� ��� �������� ���������� 
	//�) �� ��������, �) �� ������, �) �� ���������

	// 2.1. �������� � ���������� ��� �������, ������� ����������� ��������
	//� ������� ��������� �������� �� 1 
	// �) - IncByValue(),
	// �) - IncByPointer(), 
	//�) - IncByReference() . 
	//��������� ������������ � ������� ���������.
	//
	 {
		// std::cout << "\n������� 2.1" << std::endl;
		 int val = 1;//�������� ���� ���������� ������ ���� ��������� � �������
					 //������ �� ������� �� �������
		 
		 val = IncByValue(val);	     // val = 1
		 IncByReference(val);		// val = 2
		 IncByPointer(&val);		   // val = 3
		
		 stop
	 }
		
	// 2.2 �������� ���������� c ������� ��������� � �� ������.
	//�������� ������� (�������) Swap(), ������� ������ ��������
	//���������� nX � nY �������.
	
	// �)������� ������ ��������� ��� ��������� �� int  � �������� ����� �����������
	//   ������ ������ �������� ���������� � ���������� (!) ���������

	// �)������� ������ ��������� ��� ������ �� int � �������� ����� ��������
	//   ������ ������ �������� ���������� � ���������� (!) ���������
	//��������� ������������ � ������� ������������ ���� ���������.
	 {
		 //std::cout << "\n������� 2.2" << std::endl;
		 int nX = 1;
		 int nY = -1;
		 Swap(&nX, &nY);  //�������� ������� �������� nX � nY � ������� ���������� �� nX � nY
		 Swap(nX, nY);    //� ������ ������� � ������� ������ �� nX � nY
		 stop
	 }
		////////////////////////////////////////////////////////////////////////////

		//������� 3. ������� � �������� ����������.
		// 3.1. �������� ������� ������ ��������� �� ���������� ���������� �������

		//��������:
		//int ar[N] = {������ ���������������};//��������� - ��� � ��� ������ ���� ������ N
		//PrintArray(ar, ... ����� ����, ����������� �������� ��� �����-������ ������);
	 {
		 std::cout << "\n������� 3" << std::endl;
		 const int N = 6;		// ������ �������
		 int ar[N] = { 10, 20 ,30 ,40, 50 };
		 PrintArray(ar, N);
		 stop
	 }
		// 3.2. �������� ������� ������ ������������ �������� �� ���������� ���������� �������

		//��������:
		//int ar[N] = {������ ���������������};//��������� - ��� � ��� ������ ���� ������ N � M
		//int res = Min(ar, ... ����� ����, ����������� �������� ��� �����-������ ������);
	 {
		// std::cout << "\n������� 3.2" << std::endl;
		 int ar[] = { 10, 4, 22, 5, 6 };
		 size_t size2 = sizeof(ar) / sizeof(ar[0]);
		 int res = Min(ar, size2);
		 stop
	 }
	
		// 3.3. �������� ������� ��������� ���� ����� - MyStrCmp():
		//������� ������ ��������� ��� ��������� �� ������������ ������ 
		//(�������� �� ������ ������� �����������, ��� ������� �� ����� ����� �������������� 
		//���������� �����)

		//������� ������ ���������� ������������� ��������, ����
		//������ ������ ����������������� ������ ������, 0 - ����
		//��� ����� � ������������� ��������, ���� ������ ������
		//������ ������.
		//���������: ��� ������������������ ������� ������������ ���� �������� (!!!), � �� ����� �����
		// ���� ���  ������� ������ ������ > ���������������� ���� ������� ������ ������, 
		// �� ������ ������ > ������ 
		//���������, ��� ��������� ����� ������ �������� ������� ����.

		//�������� ��� ������ ��� ���������:
		//�������� ������� ���������
		//�������� ��������� ��������� � ������� cout:
	 {
		 std::cout << "\n������� 3.3" << std::endl;

		 char arr1[] = "HELLO";
		 char arr2[] = "HELLo";
		 int result = 0;
		 std::cout << MyStrCmp(arr1, arr2);

		 stop
	 }
////////////////////////////////////////////////////////////////////////////
	//������� 4. ������� ������ �� ��������

		// 4.1. �������� � �������� �������, ������� ��������� � �������� ��������� 
		//���������� ����� - nN - ������, 
		//� ����������  ��������� �� ���������� ������, ���������� �������� ��������� ������. 
		//���������: 
		//-��� ����, ����� ������ ������� �������� ���������, ����� ����� � ��� ��������� ������,
		//��������� �� ������� ��������� �������.
		//����� ����, ���� �� ������� ������������� ������ ��� ������������ �������� ������.
		{
		 std::cout << "\n������� 4.1" << std::endl;

			 const char* mStr = NameOfMonth(7);
			std::cout << mStr << std::endl;
			stop
		}

		// 4.2. �������� � �������� �������, ������� �� ��������� ������������� ����������
		// (����, �����, ���)
		//��������� ��������������� ������ 
		//��������, 12, 11, 2020 => "12.11.2020" 
		//  ���  1, 1, 2020 => "1.1.2020"   (� ����� "01.01.2020")

		// ��������� � 
		// 1) ��� �������� ������ ����� � ��������� ������������� ����� ������������ ������� 
		// ����������� ���������� _itoa(), 
		// ������������ ���� <cstdlib>� ������ MSDN).
		// char* _itoa( int value, char * buffer,  int radix );

		// 2) ��� ������������ �������������� ������ ��� ������ ����� ����������� ������� ����������� 		
		// ���������� strcpy() � strcat
		//������������ ���� <cstring>� ������ MSDN).
		// char * strcpy( char * dest, const char * source); 
		// - ��������  �� ������ source, ������� ����������� ������� ������, � ������ dest
		// char * strcat( char * dest, const char * source);  
		//- ����������� �����. ����� ������ source  ����������� � ����� ������ dest. 
		// ������� ������ ����� ������ dest ���������� ������ �������� ������ source
		// � ����� dest ����������� ������ ����� ������ ('\0').

		// 3) !!! ������ �����, ��� ������������� ���� �������, �� �������� ��������� �����������:
		//Severity	Code	Description	Project	File	Line	Suppression State
		//Error	C4996	strcpy': This function or variable may be unsafe.Consider using strcpy_s 				//instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
		//��� ����, ����� ��� ��������� �� ����������, ����� ����� #include �������� 
		//  #define _CRT_SECURE_NO_WARNINGS
	

		//� ������� �������� ����������, ����������� � ����� �������.
		{
			std::cout << "\n������� 4.2" << std::endl;

			std::cout << DataStr(22,9,2020) << std::endl;
			stop
		}

		//  <cstdlib> ��� _itoa() ��������� ��� � �������� <iostream>

////////////////////////////////////////////////////////////////////////////
	//������� 5. ����������� ������.
	//�������� �������, ������� ������� ����� ������������ �������� � �������,
	// ����� �������, ����� �� ����� ����� ���� ������������ ����� �� ����� 
	// ���������: *MyMin(���������) = 0;
		{
			//std::cout << "\n������� 5" << std::endl;
			int arrMM[] = { 33, 4, 6, 10, 12, 2 };
			int size_MM = sizeof(arrMM) / sizeof(arrMM[0]);

			int* pMin = addr_min(arrMM, size_MM);

			// ����� ������� ����� �� ����� 
			*addr_min(arrMM, size_MM) += 1;			// 3  (2 + 1)

			//std::cout << (*addr_min(arrMM, size_MM) += 1) << std::endl;
		}
////////////////////////////////////////////////////////////////////////////
	//������� 6 (*).
	//��� ���������� ������ �� N ���������
	//��������: �������� ��������� ����� ���� ������ � ��������� 0, 1, 2 �., 30, 31.  
	//�������� ��� ������� :
	//������� - ��������� ����� �������� ����������� � ������� ������ ����� ���, 
	//� ����� � ��������(��� ���� ��� ���������� ����� ������������ ������ ���� int) = >
	//int   f1(���������);
	//������� �  ������� ���������(��������: 0 ����������� � ������� ������ ����� ���)

	//� ������� �������� ����������, ����������� � ����� �������.
		{
			std::cout << "\n������� 6" << std::endl;
			int arrNumber[31];
			int sizeArr = sizeof(arrNumber) / sizeof(arrNumber[0]);  // ������ �������

			// ���������� ������� ���������� �������
			for (int i = 0; i < sizeArr; i++)
			{
				//  ��������� ����� �� 1 - 31
				arrNumber[i] = (rand() % 31 + 1);
			}

			int searchNumber = 1;

			// ������� ����� ����������� ��� � �������
			searchEvenAndOddnumber(arrNumber, sizeArr, searchNumber);
		}
		
	return 0;
}//main
