// ����:
// ���������� ����������.
// ���������� ������� 

//#include "stdafx.h"	//���� �� ����������� �������������� ������������
					//������, ���������������� ��� �������
#include<iostream>
#include <tchar.h>
#include"MyString.h"
#include "Point.h"

#define	  stop __asm nop

// ���������� ��������� -=
Point& operator-=(Point& other, const int number)
{
	other.m_x = other.m_x - number;
	other.m_y = other.m_y - number;
	return other;
};
Point& operator-=(Point& other, Point& other2)
{
	other.m_x = other.m_x - other2.m_x;
	other.m_y = other.m_y - other2.m_y;
	return other;
};

int _tmain(int argc, _TCHAR* argv[])
{
//////////////////////////////////////////////////////////////////////


	//������� 1.���������� ����������.

	//���������� � ������� ����� MyString.cpp � MyString.h
	//������ MyString, �������������� ���� �� ���������� �������
	//9a. ����������� �������� ������������ ��� ������ MyString
	//��������� ������������ ������ �������������� ���������

	{
		MyString s1("AAA"), s2;
		s2=s1;		// MyString& operator=();
		//s2.operator=(s1);
		s1="CCC";	// MyString(���������) -> MyString& operator=() -> ~MyString(); 
		//s1.operator=("CCC");
		s2= MyString("tmp"); // MyString(���������) -> MyString& operator=() -> ~MyString();
		//s2.operator=(MyString("tmp"));
		s1=s1;			// MyString& operator=();
		//s1.operator=(s1);
		stop
	}




	//2.�������� ����� Point, ������� ����� ��������� ����������
	//"�����". �������� ����������� (������������) ������   

	//2b. "�����������" �������� += ���, ����� ��� ����������
	//�������� ���� pt2+=pt1; ������������
	//����������� ���������� �������� pt1 � pt2, � �����
	//������������� ��������������� ���������� ������� pt2 ���
	// � ������  pt2+=1; ��� ���������� ������� pt2 ������������� ��
	// ��������� ��������
	//a) � ������� ������ ������ (�������� +=)
	//�) � ������� ���������� ������� (�������� -=)
	//��������� ������������ ������ �������������� ���������
	{
		//(�������� +=)
		Point pt1(1, 1);
		Point pt2(2, 2);
		pt2+=pt1;		//pt2 = {m_x=3 m_y=3 }// ����� Point::operator+=(const Point& other)
		pt2+=1;			//pt2 = {m_x=4 m_y=4 }		
		Point pt3(3, 3);
		pt2+=pt1+=pt3;	//pt2 = {m_x=8 m_y=8 } // ����� Point::operator+=(const Point& other)
		stop
		//(�������� -= ) // � ������� ���������� �������
		pt2 -= pt1;		//pt2 = {m_x=4 m_y=4 }
		pt2 -= 1;		//pt2 = {m_x=3 m_y=3 }
		pt2 -= pt1 -= pt3;	//pt2 = {m_x=2 m_y=2 }
		stop
	}

	//������� 2c. ����������� �������� +/- 
	//a)� ������� ������� ������ (�������� +)
	//�) � �������  ���������� ������� (�������� -)
	//���, ����� ����� �� ������������������ �����
	//���� ����������� ���������
	{
		Point pt1(1, 1);
		Point pt2(2, 2);
		Point pt3;

		pt3 = pt1 + 5;
		//pt3 = 2 + pt1;	// ������ � ������� ���������� �������
		pt3 = pt1 + pt2;
		 
		//	pt3 = pt1 - 5;
		//	pt3 = pt1 - pt2;
		stop

			//������� 1d. ����������� ������� �������� +/- 
		//	pt3 = -pt1;
		//	pt3 = +pt1;

	}

/*
	//������� 2d. ����������� �������� << (������ � �����) ���
	//������ MyString ����� �������, ����� ��� ���������� ����������� ������
	//�� ����� ���� ��������:
	//contents:  "QWERTY"

	MyString s("QWERTY");
	cout<<s<<endl;


	stop
*/
/*//������� 2e*. ����������� ��������� + � += ��� ������ MyString ����� �������,
  //����� ����������� ������������ �����
	MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
	s3 = s1+s2;
	s4 += s1; 
	stop

*/
	//������� 3. ����������� "���� ������" � ����������� ����������� ��������������
	//�������. ������ �������� ������� (���� � ������� ��������, ������� ���������� ��������
	//� ���� ���� �� �����), � �������: ���, �������, ���������, ��������...
	//����������:
	//���������� ����������� � ����
	//����������
	//����� ���������� � ���������� ����������
	//����� ���� (��� ������������) ���������� � ���� �����������
	//��������:
/*
		BD bd;	//�������� ������ ����
		bd["Ivanov"] = Data(30,MALE,<��������� ������>);	//���� Ivanov-� � ���� ��� ���, ��
						//����������, ���� ��� ����, �� ������ ��� ����������
		std::cout<<bd;	//����� ���������� ��� ���� �����������

*/
	
	return 0;
}//endmain

