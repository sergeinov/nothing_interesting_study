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
Point& operator-=(Point& leftObject, const int value)
{
	leftObject.m_x = leftObject.m_x - value;
	leftObject.m_y = leftObject.m_y - value;
	return leftObject;		// ������� ������ ������������� �������
};
Point& operator-=(Point& leftObject, Point& RightObject)
{
	// c ��������� �������� Point temp; �� ����������  pt2 -= pt1 -= pt3;
	// ���������� ������ ��������  leftObject
	leftObject.m_x = leftObject.m_x - RightObject.m_x;
	leftObject.m_y = leftObject.m_y - RightObject.m_y;
	return leftObject;			// ������� ������ ������������� �������
};

// ���������� ��������� +
Point& operator+(const int value, Point& RightObject)
{
	RightObject.m_x += value;
	RightObject.m_y += value;
	return RightObject;			// ������� ������ ������������� �������
};

// ���������� ��������� - 
Point operator-(Point& leftObject, const int value)
{
	// ��� � ��������� �������� Point temp; ����� 
	Point temp;
	temp.m_x = leftObject.m_x - value;
	temp.m_y = leftObject.m_y - value;
	return temp;		// ����� ����������� ����������� Point(const Point& other);
};
Point operator-(Point& leftObject, Point& RightObject)
{
	Point temp;
	temp.m_x = leftObject.m_x - RightObject.m_x;
	temp.m_y = leftObject.m_y - RightObject.m_y;
	return temp;		// ����� ����������� ����������� Point(const Point& other);
};

// ���������� ��������� << 
//���� �� ����������� ���������� std::ostream �� ��������, �� �������� ������ �����������. 
//��� �������� ��-�� ����, ��� std::ostream ��������� ���� �����������.
std::ostream& operator<<(std::ostream& out, const MyString& RightObject)
{
	out << "m_pName: " << RightObject.m_pName;
	return out;
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
		//pt2.operator+=(pt1);
		pt2+=1;			//pt2 = {m_x=4 m_y=4 }	
		//pt2.operator+=(1);
		Point pt3(3, 3);
		pt2+=pt1+=pt3;	//pt2 = {m_x=8 m_y=8 } // ����� Point::operator+=(const Point& other)
		//pt2.operator+=(pt1.operator+=(pt3));
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

		// (�������� +)
		pt3 = pt1 + 5;
		//pt3.operator+(pt1 + 5);
		pt3 = 2 + pt1;		 // ������ � ������� ���������� �������
		pt3 = pt1 + pt2;
		//pt3.operator+(pt1 + pt2);

		// (�������� - )
		pt3 = pt1 - 5;
		pt3 = pt1 - pt2;
		//pt3.operator+(pt1 - pt2);
		stop

			//������� 1d. ����������� ������� �������� +/- 
		// �������� ����� ������������� ������� ���������� (-) � �������� ���������� (-) ����.
		// �.�. ��� ����� ������ ���������� ����������
		pt3 = -pt1;
		//pt3.operator-();	// ��� �������� �������������� �����??
		pt3 = +pt1;
		//pt3.operator+();
		
		stop

	// ������ ��� ������ ������������?
	}


	//������� 2d. ����������� �������� << (������ � �����) ���
	//������ MyString ����� �������, ����� ��� ���������� ����������� ������
	//�� ����� ���� ��������:
	//contents:  "QWERTY"

	// ���������� �������� ������ ���������� ��������. �.� ������� ����� ������������ �������
	{
		MyString s("QWERTY");
		std::cout << s << std::endl;
		stop
	}

	//������� 2e*. ����������� ��������� + � += ��� ������ MyString ����� �������,
  //����� ����������� ������������ �����
	{
		MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
		s3  = s1 + s2;
		s4 += s1;
		stop
	}

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

