//����������

//�������: 
	//		������� �������,
	//		������� �������,


#include <tchar.h>
#include<iostream>
//#include <stdexcept>
#include"Template.h"
#include"MyString.h"
#include"MyStack.h"
//#include"MyArrayError.h"
//#include"MyEmptyStack.h"

#define stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{
	


////////////////////////////////////////////////////////////////////////////
	//����. ������� �������.
	//�������� ������ ������� ������������ ������� ����
	//�������� - Swap(). ��������� ����������������� ����������
	//������� � ������� ������������ ���� ��������� ����.
	//��������� 1: ���������� ������� ���������� ��������� � .h-����.

	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);


	//��������� 2: ���������, ��� ����� �����������, ��� ����,
	//			����� ��������� ����� ������� � ��������� MyString
	//			�� ������ ���������, �� � ����������
	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	//Swap("ABS", "DCB");


/////////////////////////////////////////////////////////////////////
	
	//����. ������� �������.
	//������� 1.
	//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
	//���������: 1.�������� ����� ���-�� ������� - ������� � ������� ���������
	//			��� �������� ��������������� ������������� � ������ ���������
	//			�������� ������, 
	//			2.��� ������� ������������� ������� ����� ����� ���� �����������
	//			��������-��������� �������
	//			3.������������� ���������� �� ������ �������� "push" � "pop". ���
	//			����, ����� ������������� ���������� ���������� ���� �������� 
	//			������ ���� �� ������������ ���������� � ��������� ��������
	//			4. ������������� ���������� operator[] ����� �������, ����� ������������
	//			��� ������/�������� �������� ������ ��� ���������, ������� �� ����������

	MyStack<int, 5> stack;
	try
	{
		stack.push(5);
		stack.push(10);
		stack.push(15);

		int res = stack.pop();
		std::cout << res << std::endl;

		int res2 = stack.pop();
		std::cout << res2 << std::endl;

		int res3 = stack[ 0 ];
		std::cout << res3 << std::endl;

		std::cout << "������:" << std::endl;
		std::cout << stack << std::endl;
	}
	catch(MyStackFullError& error){

		std::cout << "My stack is full! Current size is" << error.m_size << std::endl;
	}
	catch ( MyArrayError& error )
	{
		std::cout << "Index out of range! " << "Current: " << error.m_wrong_Index << " Must be >= 0  or " << error.m_MaxIndex << std::endl;

	}
	catch(MyEmptyStack& error)
	{
		std::cout << "Stack is empty: " << error.m_number << std::endl;

	}
	catch ( ... )
	{
		std::cout << "Something wrong" << std::endl;
	}
	


	//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
	//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
	//push() � pop(), operator[]




	//������� 2. ���������� ������ ����� - MyStack2 ����� �������, ����� 
	//��� �������� ��������� ������������� ����������� ������.
	//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
	//������������






	

	return 0;
}

