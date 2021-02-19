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
#include "MyStack2.h"
//#include"MyArrayError.h"
//#include"MyEmptyStack.h"

#define stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");


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
		std::cout << stack << std::endl;

		int res = stack.pop();
		std::cout << stack << std::endl;

		stop

		int res2 = stack.pop();
		std::cout << stack << std::endl;

		stop

		int res3 = stack[ 0 ];
		std::cout << "�������� �� �������: "<<res3 << std::endl;

		stop

		std::cout << "������:" << std::endl;
		std::cout << stack << std::endl;

		stop
	}
	catch(MyStackFullError& error){

		std::cout << "My stack is full! Current size is" << error.GetSize() << std::endl;
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
	{
		std::cout << "\n**************������� 2***********" << std::endl;

		MyStack2<int> list;

		list.push(3);
		list.push(5);
		list.push(22);
		std::cout << "\n������!\n" << std::endl;
		for ( size_t i = 0; i < list.GetSize(); i++ )
		{
			std::cout << list[ i ] << " ";
		}

		stop

		std::cout << "\n\n������� ������� ������ ������!\n" << std::endl;
		list.pop();
		for ( size_t i = 0; i < list.GetSize(); i++ )
		{
			std::cout << list[ i ] << " ";
		}

		std::cout << "\n\n������� ������!\n" << std::endl;
		list.clear();
		for ( size_t i = 0; i < list.GetSize(); i++ )
		{
			std::cout << list[ i ] << " ";
		}


	}



	

	return 0;
}

