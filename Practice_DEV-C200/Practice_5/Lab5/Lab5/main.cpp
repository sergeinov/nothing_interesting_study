// ���� ����� � ��������� ������
// �������: ��������� ����������� ����� MyString ����� �������, ����� ��� ������ ��������� � ������������ ����������. 
// ��� ����� ������� ��� ����������� ������������ ������

#include <tchar.h>
#include<iostream>
#include"MyString.h"


#define stop _asm nop


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	
	MyString str("ABC");

	MyString str1 = str;
	str1 = str;
	MyString str2 = std::move(str1);	// ������������ ����������� move
	str2 = std::move(str1);

	str2.GetString();
	str2.SetNewString("HELLO");


	return 0;
}

