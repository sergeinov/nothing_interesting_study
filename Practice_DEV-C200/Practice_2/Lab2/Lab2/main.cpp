// ����:
// ������� ������������. ����������� �������. ����������� ������.
// ������� ����.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <tchar.h>
#include"MyString.h"

#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	//������� 1.������ �������� ������.
	{
	//�������� � ������������������ ������ ar �� ��������
	 //���� MyString. 
		const int N=5;
		MyString str1[N] = {MyString("Egor"), MyString("Ivan"),MyString("Kolja") };
  
	//�������� - ������ �����-������ ������
		for (size_t i = 0; i < N; i++)
		{
			std::cout << str1[i].GetString() << std::endl;	// Egor
															// Ivan
															// Ivan
															// empty...
															// empty...
		}
				
	//�������� ������ const int N=5; , �� ������� ������ ���������������.
			
	}
	stop

	//������� 2.������ ���������� �� ������� ������.
	{
	//�������� � ������������������ ������ arPtr �� N
	//���������� �� ������� ���� MyString (���� ������� 
	//��������� �����������!).
		const int M = 5;
		MyString* str2[M] = {new MyString("Egor"), new MyString("Ivan"), new MyString("Kolja") };
		//������ �����-������ ������
		for (size_t i = 0; i < M; i++)
		{
			if (str2[i])
			{
				std::cout << str2[i]->GetString() << std::endl;	// Egor
																// Ivan
																// Kolja
			}
			else
			{
				std::cout << "str2" << "[" << i << "]"  << " - (0x00000000 <NULL>)" << std::endl;
			}
		}				
		// ���  str2[3]->GetString()  str2[4]->GetString()
		// ������ // �� �������� ������, this  = nullptr. str2[3] - (0x00000000 <NULL>)
		// ������ // �� �������� ������, this  = nullptr. str2[4] - (0x00000000 <NULL>)

		for (size_t i = 0; i < M; i++)
		{
			delete str2[i];
		}

		//�������� ������ const int N=5; , �� ������� ������ ���������������.

	}
	stop


	//������� 3.������� ������������.��������� ������������,
	// ������������ � ������� �����.

	//�������� �������� �������:
	//������� ����� Shape (������� ��������� ����� ������)
	//� ��� ����������� ������ Rect � Circle.
	//���������: ����� ������ � ������ ����� ������ � �������
	//� ����������� ������ (��������, ����� ������ ����� �������
	//������� => � ������� ������ ����� ������ ����������, �������
	//����� ���������� ���� ������.
	//���������: ��� �������� ����� �������� ������������ (RED,GREEN,BLUE...);
	

	
	//� ������������� ����������� ������� ������������� ��������
	//���������-����� ������������ �������� ������.
	//��� �������� � ����������� ������� ������������ ���� ����������
	//������������������ ������� ������������� � ������������ ��������
	//� ������������ �������
	



	stop
//////////////////////////////////////////////////////////////////////
/*
	//������� 4.����������� �������.
	//4�) ������������� ������ Shape,Rect � Circle:
	//�������� � ������ ����� public ����� void WhereAmI().
	//���������� ������ ������� ������ �������� ��������� 
	//���������� ���� "Now I am in class Shape(Rect ��� Circle)".
	//��������� ����������� ��������, ��������� ���������.


	{
		Shape s(...);
		Rect r(...);
		Circle c(...);

	
		//����� ������ ������ ���������� � ��������� ��������???
		s.WhereAmI();	//	???
		r.WhereAmI();	//	???
		c.WhereAmI();	//	???
		stop


		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
    	pShape->WhereAmI();	//	???
		pRect->WhereAmI();	//	???
		pCircle->WhereAmI(); //	???
		stop


		//��������� ... �������� ������������
		Shape& rShape = ...; //��������� s
		Shape& rRect = ...; //��������� r
		Shape& rCircle = ...; //��������� c
    	...WhereAmI();	//����� ����������� rShape	???
		...WhereAmI();	//����� �����������	rRect	???
		...WhereAmI(); //����� ����������� rCircle	???
		stop
	}

	//4�) �������� � ������� � ����������� ������ �����������
	// ����� WhereAmIVirtual(). �� �������� � 4� ��������
	// ����������� ����� ����������� ��������, ���������� �
	// ������, ������������ � ���������� ���������.
	//��������� ����� ��������, ��������� �������.

*/

//////////////////////////////////////////////////////////////////////
/*
	//������� 5.����������� �����������.
	//������������� ������:
	//a) ������� ���������������
	// ����������� (��� ��������� ����� virtual).
	//���������� ������� �����������
	//������ �������� ��������� ���������� ����
	// "Now I am in Shape's destructor!" ���
	// "Now I am in Rect's destructor!"
	//��������� ��������. ��������� ���������.

	// b) �������� � ���������� ������������ �������� ����� virtual 
	//��������� ��������.��������� �������.

	
	//���������: ����� ������������ ���������� � ��������� ������?
		//���� � ������������� ������� �����-�� �������������
		//�� ������� - ����������
		//���� �� ��������, ��� � ����������� ��������� ����-��
		//�� ������� - ��������

		Rect r(<���������>);
		Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };
		//�������� ��� ������� �������� ������� ����� WhereAmIVirtual()
	

	stop
*/

/*
	//������� 6*. � ��� ����������� ������� 1) � 2)
	{
		Shape* pShapes = new Rect[10];//1)
		Rect* pRects = new Rect[10];//2)

		//���������� ������� ����� WhereAmIVirtual() ��� ������� �������� ����� �������� -
		//� ��� ����������� ��������???


		//���������� ����������� ����������� ������

	}

*/

//////////////////////////////////////////////////////////////////////
/*
	//������� 7.����������� ������� � �������� ���������� ������� ���������. 

	{
		Rect r(...);
		Shape* p = &r;	
		p->WhereAmIVirtual();//...
		stop
	
		
		//4a �������� ���������� ������� ���������.
		//����������� ������� r � ��������� p �������� ����������� �������
		//WhereAmIVirtual()������ Shape
		
		
	}
*/

//////////////////////////////////////////////////////////////////////
/*
	//������� 8.����� ����������� �������. 
	//������� � ������� ����� ����� void Inflate(int); ���������:
	//����� �� ����������� ����� ����� ��� �������� ������? => ��� ��� ����� ��������.
	//���������� ���� ����� ��� ����������� �������.
	{
		Rect r(...);
		Shape* p = &r;
		p->Inflate(5);
		Circle c(...);
		p = &c;
		p->Inflate(5);
	}
*/


//////////////////////////////////////////////////////////////////////
	//������� 9. �������� ���������� �������, ������� ����� ��������� �����
	//���������� ���������� �� ������, � ���������� ������ MyString,
	//� ������� ������ ����� ������������� ����������

////////////////////////////////////////////////////////////////////////
/*
	//������� 10.����������� (union) C++. ������� ����.
	//1.
	//�������� ��������� ������ ��� ��������� ������������� �������� �����:
	//Bin - ��� ��������� �������������
	//Hex - ��� ����������������� �������������
	//Oct - ��� ������������� �������������.
	//��������� 1: - ��� �������� ����������� ������� ����.
	//��������� 2: - ������������� � ����� ��������������� ������� ���� �� ������,
	//��� ��� ��� ��� ����� ������� ����������� (union).
	//2.
	//� ������ ������ ������� ����� Show, ������� ������ �������� �������� �
	//��������������� ����
	//3.
	//����������� ����������� MyByte ������������ ������������ ����������� ��������������
	//����� � ��� �� ��������� ��-�������:
	//�) ��������: ����������, �����������������, ������������, �������� �������� ����� 
	//          � ����� ������, ��������������� ��������� �������� (���� ���� ������������);
	//�) �������� ��������� (��������� ����������� ���������) �����������������,
	//			������������, �������� �����;
	//�) �������� ��������� ��������, ������������ ��� ����������������� �����;

	MyByte byte(0x1f);
	byte.ShowHex();
	byte.ShowBin();
	//...


*/
	return 0;
}//endmain
