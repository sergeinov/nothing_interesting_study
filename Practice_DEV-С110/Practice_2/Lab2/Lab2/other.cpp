#include "other.h"
#include <iostream>

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
void PrintArray(int (*pArr)[M], int sizeN) {
	for (size_t i = 0; i < sizeN; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << pArr[i][j] << "  ";
		}
	}
};

void PrintArray2(int **pArr2, int sizeN2, int sizeM2) {

	// ��������� ���������� ��������
	for (size_t i = 0; i < sizeN2; i++)
	{
		pArr2[i] = new int[sizeM2];
		for (size_t j = 0; j < sizeN2; j++)
		{
			pArr2[i][j] = i * j;
		}
	}
};


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

int CmpInt(void* p1, void* p2)
{
	int nResult;




	return nResult;
}



