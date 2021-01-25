#include <iostream>
#include<tchar.h>
//#include"MyString.h"
#include"MyData.h"
#include"Base.h"

#define	  stop __asm nop

// ���������� ������ ���������� ����������

// MyString
std::ostream& operator<<(std::ostream& os, const MyString& RightObject)
{
	os << RightObject.m_pName;
	return os;
};

// MyData
std::ostream& operator<<(std::ostream& os, const MyData& data)
{
	// ����� ������������� ��������<<  ��� MyString (��� ������ << data.m_job)
	os << "sex = " << (data.sex == data.MALE ? "MALE\n" : data.sex == data.FEMALE ? "FEMALE\n" : "UNDEF\n")
		<< "age = " << data.m_age << "\n"  << "job = " << data.m_job << "\n"
		<< "salary = " << data.m_salary << "\n";
	return os;
};

// Pair
std::ostream& operator<<(std::ostream& os, const Pair& pair)
{
	// ����� ������������� ��������<<  ��� MyData
};

// Base
std::ostream& operator<<(std::ostream& os, const Base& bd)
{
	// ����� ������������� ��������<<  ��� Pair
	for (size_t i = 0; i < bd.count; i++)
	{
		
		//os << bd.pBase[i].
	}

	return os;
};

int _tmain(int argc, _TCHAR* argv[])
{
	//����������:
	//���������� ����������� � ����
	//����������
	//����� ���������� � ���������� ����������
	//����� ���� (��� ������������) ���������� � ���� �����������

	Base myBase;	//�������� ������ ����
	myBase["Ivanov"] = MyData(MyData::Sex::MALE, 28, "Programmer", 150000);			//���� Ivanov-� � ���� ��� ���, ��
																		//����������, ���� ��� ����, �� ������ ��� ����������
	myBase["Petrova"] = MyData(MyData::Sex::FEMALE, 22, "HR" , 80000);				//���������� ���������� � ����
	myBase["Borisov"] = MyData(MyData::Sex::MALE, 35, "Designer" , 100000);		//���������� ���������� � ����
	myBase["Borisov"] = MyData(MyData::Sex::MALE, 35, "Middle Designer", 150000);	//��������� ������ ���������� � ����

	myBase.deletePair("Borisov");				// �������� ����������

	std::cout << myBase["Petrova"];			// ����� ���������� �� ����� ����������, ������������� � ����
	std::cout << myBase["Petrova"];			// ����� ���������� �� ����� ����������, �������� ��� � ����
	std::cout << myBase;						//����� ���������� ��� ���� �����������

	//Base db = myBase;							// ����������� �����������
	//myBase =  db;								// �������� ������������
	//Base db2 = move(db)						// ��������� ����������� move
	//db = move(db2);


	return 0;
}