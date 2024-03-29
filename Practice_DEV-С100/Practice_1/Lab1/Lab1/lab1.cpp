//������������ ������ �1 �� ����� Dev-C100
/*
	� ���������� ���������� ������ ������ ��������� �������� ����� ������ �� �����������
	��� ���������� ������ �������, ������� ������� ��������� ��� ������������������ 
	������������������ ������, ������� ��������� ��������������� �����������������, 
	�������  ��� ���� �� ������������ �������.

	��������� ������������������ �������� ��� ������� �������:
	1. �������� (���������, ���������������� ������ ��������) �������� ����� ���������;
	2. �������������� (Build/Compile  ***.cpp ��� Ctrl+F7)
		���������: ���� ���� ���� �������� �������������, �� ������� ��� ����������� 6
			������������, �.�. ��������� ������� ������ (errors) � ��������������
			(warnings), ����������� ��� ���������� ������� ����������� �����;
	3. ����������� ������(Build/Build ***.exe ��� F7)
		��������� 1: ���� ���� ���� ������������, �� ������������ �����������, �.�. 
			��������� ����������������� ������ ���������� ����� � � ������ ����������
			������ ������ ������� ���������� �� ���������� ������������ ���������;
		��������� 2: ����� ���, ��� ������� ������, ������� ���������  � ���, ��� 
			����������� ��� ����� ��������� ���������� ��� ��������� - 
				(Build/Configuration Manager.../Configuration - Debug - ��� ������ �������);
	4. ��������� �� ������������ ��� ������� ��������� ���� ����� �������� (breakpoints) - F9 ��� 
		������ �������� ����� ������� �� ����� ����� ������ ���� ��������������; 
	5. ��������� ��������� � ������ ������� 
		(Debug/Start... ���  F5);
	6."������������" �� ���� �� ����� ������� ����� �� ����� (�� ������ � ������). ��� ����� ����� ������������ ������� F10.
	7. ����� ����, ����� ���������� �� ����� "����� ��������" � ������ ����������� F5.
	8. �����!!! ����� ��������� ��������������� �� ��������� "����� ��������", �� ��� ����������, ����������� �� ��������������� ������
       ��� �� ��������! ��� ����, ����� �� ����������, ��������� ������� "���", �.�. ������ ������� F10 ��� ������ Step Over. 	   

  ���������: ��� ������������� ���� �������� ��������� ���������� ������ � ��������������� 
		������ ����, ������ �� ������ ������� ������� ������� �� �� ����� ����� ������� � 
		������� ������ �� Tool Bar, � ��� ��������� ����� ��������� ��������������.

*/

#include  <climits>
#include <cfloat>


int nTwin=1;			//���������� ����������
extern int nTest;		//?		10 - ������� ����������  � test.cpp

#define	  stop __asm nop	//� ������� ���������������� ������ "������" �������.
							//��� ���������������� ����� ������ ��� ����, �����
							//����� ���� ��������� �� ���� ������ ����� ��������.

int main()
{
	//**********************************************************
	   //������� 1. ������ � ����������. ������� ���� ������. �������� ��������� �� �����, 
	   //������� �� ���������� ���������� � ��������������� ��������� (�������, ��� 
	   //���������� ����, ��������� ��� int, �������-��������).
	   //�������� �������� �� ������ ������������� ���������� signed � unsigned ����� ����� 
	   //������, � ����� �� ���������� ������������� ������������� ����� �����.

	   //����� � ������ ������� ���� �������� �����������, � ������� ������� ��������
	   //���������� ����� ���������� ��������������� ����������
	   //�������, ��� ���� �� ��������� ����� �������� �� �����-�� ������, �� ��������
	   //����������� �� ���������� ����������
	   //����� ������������ �� ���� ��������, ����� ������������ ������� F10 ��� ������ Step Over

	   //��� ����, ����� �� ����� ������� ��������� �� ���������� ����������, ����� ������������ ������ "Autos", "Locals", "Watch"
	   // ������ "Watch" ������ ���, ��� ��� ����� ������� �� ������ ����� ����������� ����������, 
	   //�� � ���������, ������� �� ������ �� ���������
	   // ��� ����, ����� ������� 16-������ ������������� ��������, ���� � ����������� ����  ������ �� ������ "Autos", "Locals", "Watch"
	   // ������� ������ Hexadecimal Display, ��� ����, ����� ��������� � 10-����� ������������� - ����� ������ Hexadecimal Display

	   //���������: ����� ������ ��� ��������� ��������  �� ����� �������� �����, � ���������� ��� �� ���� ���������


	char cByte = 'A'; //65  'A'  ,		cByte	0x41 'A'	char

	cByte = 0x42; //66 'B'  		cByte	0x42 'B'	char

	cByte = 66;  //66 'B'		cByte 0x42 'B'		char

	cByte = -1;  // 0xff '�'						char

	unsigned char ucByte = 0x41;  // 'A' 65 
	ucByte = 'B';				  // 'B'  66   / 0x42 
	ucByte = -1;				  //  '�' 255 / 0xff 

	int iInt = 0xffffffff;		  // -1

	unsigned int uiInt = 0xffffffff; //  4294967295

	float fFloat = 1.f;				 // 1.00000000

	double dDouble = 1.;			 // 1.0000000000000000

	// ��������� ��������, ����������� �����. � ������������ ��������,
	// ��� ������� ��������� � ����������. ��������� ������� ����� ���� 
	// ��������� � ���������������.


	double d = 0.1234567890123456789123456789; //  0.12345678901234568
	float  f = d;							   // 0.123456791   -   �������� float 6 �������� // Warning �������������� "double" � "float", �������� ������ ������



	d = 1.;								      // 1.0000000000000000
	d = 0.999999999999999999999999999999999;  // 1.0000000000000000

	stop		// ��� ����������� �����, ������ ��� ����, ����� ��������� ����� �������� � ���������� �������� ����������

	// � ������������ �������� ���������, ������������ ���������� sizeof ���
	// ���������� ���� wchar_t (�� ������)
		wchar_t cw = L'�';	   //   1060 '�'  /  0x0424 '�'  // 2 �����    Unicode
	size_t n = sizeof(cw); //  2 ����� 

	stop		// ��� ����������� �����, ������ ��� ����, ����� ��������� ����� �������� � ���������� �������� ����������


// **************************************************************
	//������� 2a. ������� ���������� ����� ������.
	//��������� ������� ���������� ��� ���������� (1) � (2):
	//�������� ���� (�������� � ����) ��������������, ������� ������ ��������� ����������

		iInt = 1;
	double dDouble1 = static_cast<double>(iInt / 3);		// ������� �������, ����� ������������ // 0.00000000000000000

	double dDouble2 = static_cast<double>(iInt) / 3.;	//? (2)  0.33333333333333331


	// ��������������� ����������.
	// ��������� ����� C ��������� "����������" ������������
	// (��� � ������� (1) � (2)). ��������� ���������� ���������� ����� (1) � (2)
	// (�������� ���������� dDouble, fFloat, nInt, sShort, cByte), ���������� ������� 
	// ��������� ������������ ��� ���������� ������ � ��������� ���������.
	// ��������� ������, ���� ������������ ������� ����������, ��� ��� ������ �� ����������.
	// ��������� (� ������������) �������������� (warnings) �����������.
	//
	short sShort;
	dDouble = (fFloat = (iInt = (sShort = (cByte = (3.3 / 3)))));	// (1) cByte =1 > sShort =1 > iInt=1 > fFloat=1.00000000 > dDouble=1.0000000000000000

	cByte = (sShort = (iInt = (fFloat = (dDouble = (3.3 / 3)))));	// (2) dDouble =1.0999999999999999  > fFloat=1.10000002 > iInt=1 > sShort=1 > cByte=1

	//���� ��� ��� ������ "����������" ������������� �������� ���������� �����, ��� ����� 
	// �������� � ������������� ����������� - ��������� (� ������������), � �����?
	// �������� ���� ��������������, ������� ������ ��������� ����������
	//����������� �������� ���������� ���� static_cast

	iInt = 257;						//Hexadecimal Display: ???   0x00000101
	cByte = static_cast<char>(iInt);	//Hexadecimal Display:  char cByte = 1   /  0x01   / '\x1'- ������-������������������

	unsigned char cN1 = 255, cN2 = 2, cSum;
	cSum = static_cast<unsigned char>(static_cast<int>(cN1) + static_cast<int>(cN2));	// cSum = 1 	//cN1 = 0xff 255	/  cN2 = 0x02  2	������ ��� ��������� ���������, ������� ������� �� ������� int

	//�������� ���������� ������� � ����������� ����. ��������� (� ������������),
	//������ � ��������� ������ �� ���������� ����� �� ��������� �����
	// �������� ���� ��������������, ������� ������ ��������� ����������
	int iSum = static_cast<int>(cN1) + static_cast<int>(cN2);		//  257

	//��������, ������ ��� �������� ���������� �������� (���������� � �������� �������) 
	// � ������� (1) � (2) ���������� ������ ����������
	// �������� ���� ��������������, ������� ������ ��������� ���������� � ���������,
	// ��� ��� ���� ����������
	char c1 = 0xff, c2 = 2;  // c1 = -1   // c2 = 2  0x02
	unsigned char uc1 = 0xff, uc2 = 2;      // uc1  = 255  0xff  // uc2 =0x02  2
	int iSum1 = static_cast<int>(c1) + static_cast<int>(c2);   //?(1)   1
	int iSum2 = static_cast<int>(uc1) + static_cast<int>(uc2); //?(2)   257

	stop		// ��� ����������� �����, ������ ��� ����, ����� ��������� ����� �������� � ���������� �������� ����������

// ***********************************************************
	//������� 2b. ����� ���������� ����� ������.
	//������������������ ��������� (�������� ���������� dDouble) � ������ (3)
	// �������� ���� ��������������, ������� ������ ��������� ����������
		int nTmp = 100, nn = 3;
	dDouble = 3.3 + static_cast<double>(nTmp / nn); // (3) =?  dDouble= 36.299999999999997


	//�������� ��������� ��� ������ �������� � ������� ��������� ������
	//���������� ����
	double dDouble3 = 3.3 + (static_cast<double>(nTmp) / static_cast<double>(nn));		// (4) 36.633333333333333


// *******************************************************
		// ������� 3. ������� ��������, ������� ��������� �
			//				����� ������������� ����������

			//   � ���� ��������� ���������� ��� ���������� � ����� � ��� �� ������ 
			// nTwin - ���� ���������� (���������� ����, � ������ ������) ������ - ��������� ������ ������� main(), 
			// ������ - ��������� ��������� ������ �����. 
			//   � ������ ������� ��������� � ���������� ������ ��������� ���������� � ����������������,
			// � ����� �� ���������� ���� ��������� (� ����������, � ����� �� ���������),
			//� ����� ���� ������������� � ��������� ��� ���� ����������

			//	��� ���������� ������� ������������� ������������ ������ "Locals" � "Watches"
			// ���������: - � ���� "Watches" ����� ��������� ��� nTwin ��� � ::nTwin

	// ������� 3.1.

	nTwin = 100; // ���������� "����" ��������� -  ����� //  ::nTwin = 100

	nTwin += 1;	//  ���������� "����" ��������� - �����  //  ::nTwin  = 101
	// �������� �������� �� ��������� "����" ���������. ���� ��������� ���������� nTwin
	// �� ��������� ������ ��� �� ���������� (� ��������� ���� �� ����������), �� �����
	// ��� ��� � ����� ������� main ��� �������� (� ��� �����). ���� ������ �  ���� 
	// "Watches" ��������� ������ nTwin, �� �������� ����� ���������� �������� ����, ��� 
	// �� ����������� ��������� ���������� (���-�� ����� -858993460 ��� 0xcccccccc), 
	// ���� ������ ��������� ���������� �������� ���������� ����������, ����������� �����.
	// ���������� ��� ���� ��� ��������� �����.
	// ���� ���� ������� ������ �������� ���������� ����������, �� ���� ���� ������� � ����
	// "Watches" ���������� ������� ���������, �.�. �������� ��� ::nTwin.
	// ����������: ��� ��� ���� �������� �� ��, ����� �� ��������� ��������� ����.
	int nTwin;		//  ���������   
	nTwin = 200;	//  200 
	::nTwin = ::nTwin + 1;	// ���������� ::nTwin 102 
	{
		int nTwin;		//   ����� ���������  
		nTwin = -1;		//  - 1
		::nTwin += 1;	//  ::nTwin = 103   
		nTwin += 1;		//  0  
		stop			// ������ ���� ���� ������� ���������� ���� - nTwin
	}

	nTwin -= 1;	// 199
// ������� 3.2

	//� ���� ��������� ����������  ����� ��� ���������� � ����� � ��� �� ������
	// nTest - ���������� (���������� � ������ ������) ������ - ��������� ������ main,  ������ - ��������� ������ �����, 
	nTest = 1000;		//  ���������� extern - ::nTest = 1000
	int nTest = -2000;   // ����� ��������� ����������
	stop
	{
		int nTest = 200;  // ����� ��������� ����������
		nTest += 2;			// 202
		stop
	}
	nTest += 2;			// -1998



// *******************************************************
	// ������� 4. ������������ ������ ������ - static
	// �) ��� ������ �������� ����� �������� �������� ��������� nLocal# � nStatic#.
	// �) ��������, ����� ����������� ������������� ����������?
	// �) �������� (� �����������) ������� ����� �������� ������������� 
	//     ���������� nStatic1 � nStatic2 

	for (int i = 0; i < 3; i++)
	{
		static int nStatic1 = 100;    // ����� ����������
		int nLocal1 = 100;
		int nLocal2 = 200;
		static int nStatic2 = (nLocal2 += 1) * 2;   // ������� ���������� ���������, ����� ���������� // static ���������������� 1 ��� � �����, ������ ������������
		nStatic1 += 1;
		nStatic2 += 1;
		nLocal1 += 1;
		stop
			//nLocal1=		101		101		101
			//nLocal2=		201		200		200
			//nStatic1=		101		102		103
			//nStatic2=		403		404		405
	}
	// ��������:
	//   �) ��� ���������� ��������� ��������� nStatic1?
	//   �) ��� ��� ���������� ���������������� ?
	for (int i = 0; i < 3; i++)
	{
		static int nStatic1;  //  0    // ��� ����������� ����������� ���������� �������������  0
		nStatic1 = 100;			// ����� �������������   � ����������� ��� ������ �����
		int nLocal1 = 100;		// ����� �������������   � ����������� ��� ������ �����
		nStatic1 += 1;
		nLocal1 += 1;
		stop
			//nLocal1=		101		101		101
			//nStatic1=		101		101		101
	}



	// *******************************************************
		// ������� 5. ������������ - enum
		// �������� �������� �� ����� � ������� ������������� ��������
		// �������� ������� �� �����, ������� �� ����������, �������
		// ��������� ���������� myColors
	{

	enum eColors
	{
		BLACK,
		BLUE,
		GREEN,
		RED = 5,
		YELLOW,
		WHITE = RED + 4
	};

	eColors myColors;	//���������� ���������� ���� eColors 
	myColors = BLACK;		// 0
	myColors = BLUE;		// 1
	myColors = GREEN;		// 2
	myColors = RED;		// 5
	myColors = YELLOW;	// 6
	myColors = WHITE;		// 9

	int nnn = BLACK; //    0    //����� ������������� ���������� ����� ���������
							  //�������� �� ������ ���������������� ��������

	//����������� ��������� ����� ������������ � ����������:
	nnn = BLUE + YELLOW;	//  6 + 1 = 7

	//���������������� ��������� ������ � ��������
	//�������� ��  ������ ��� ���������� 
	myColors = static_cast<eColors>(1);	 // BLUE = 1 // ����� ���������� �� ������� ������, ��������� ����� ���������� ����

	// ��������� ��������� ������������ �� ����� ������������ � ��� ���������� myColors?
	myColors = static_cast <eColors>(123);
	stop

	}

// *******************************************************
	// ������� 6.1 ���������� ��� bool
	// �������� ������� �� �����, ������� �� ����������
	// ���������� b � ��������������� ���������. �������� ��� �������� � ������������

	int nNumber = 1;
	bool b = (nNumber != 0); //  true
	b = (nNumber == 0);		//	false
	b = (nNumber > 0);		//	true
	b = (nNumber > 1);		//  false
	b = 5;					// true b=1

	//�� ������ ������ ������������� ���������� �������� � ������
	//���� ��� ���������� ����� ��� ������� �������������� (������)
	//�������� ��������: ��� �������������� �������� ���������� ���������� ����������?
	int tmp =  b + 1; //  2		b = 5, ������ b = true / 1	  // true = 1;  false = 0



// *******************************************************
	// ������� 7. ����������� const � ����������

	{
		//���������������� ��������� ��� ������� � ��������� (� ������������)
		//������ ��� ���������� 

			const int nN = 0;		//  ��������� ������� ����� ������������� ����������
			//nN = 1;			//  ������ �������������� ���������
	}


	return 0;//��� ���������� ����������
}	// ����� ������� main()

