#include <iostream>
#include<tchar.h>
#include"MyString.h"
#include"MyData.h"
#include"Base.h"

#define	  stop __asm nop

// ���������� ������ ���������� ����������

int _tmain(int argc, _TCHAR* argv[])
{
	//����������:
	//���������� ����������� � ����
	//����������
	//����� ���������� � ���������� ����������
	//����� ���� (��� ������������) ���������� � ���� �����������

	Base myBase;	//�������� ������ ����
	//myBase["Ivanov"] = MyData(MALE, 28, <��������� ������>);	//���� Ivanov-� � ���� ��� ���, ��
	//														//����������, ���� ��� ����, �� ������ ��� ����������
	//myBase["Petrova"] = MyData(FEMALE, 22, <��������� ������>);	//���������� ���������� � ����
	//myBase["Borisov"] = MyData(MALE, 35, <��������� ������>);		//���������� ���������� � ����

	//myBase.deletePair("Borisov");			// �������� ����������

	//std::cout << myBase["Petrova"];		// ����� ���������� �� ����� ����������
	//std::cout << myBase;					//����� ���������� ��� ���� �����������

	//Base db = myBase;						// ����������� �����������
	//myBase =  db;							// �������� ������������
	//Base db2 = move(db)					// ��������� ����������� move
	//db = move(db2);


	return 0;
}