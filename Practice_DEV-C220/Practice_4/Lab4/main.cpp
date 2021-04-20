#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include"Header.h"
#include <list>
#include<ostream>
#include<fstream>
#include"WriterDeleter.h"
#include<stdio.h>
#include"human.h"

size_t SIZE;

void deleterFoo(std::string** str)
{
	for ( size_t i = 0; i < SIZE; i++ )
	{
		delete str[ i ];
	}
}

int main()
{
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	//������� 1. unique_ptr
	{

		//1.� - ���������� ���������� ���������� ���������
		{
			std::vector<std::string*> v = { new std::string("aa"), new std::string("bb"), new std::string("cc") };
			//������������ ��� ������
			for ( const auto& i : v )
			{
				std::cout << *i << " ";
			}
			__asm nop

			for ( auto& i : v )
			{
				delete i;
			}
			//v.clear();
			__asm nop

		} //??? ����������� ��� ����������

		//1.b - ������������� ������� 1.�:
		 //���������� ����������� std::unique_ptr: 
		 //����������� ���������� (��������� ��� ������ ������� ������������ std::unique_ptr), 
		 //���������� �������� ���������� �� ����������� ����������� ������� std::string, 
		 //���������������,
		 //� ������������ ��������
		 //

		{
			//������������ ��� ������
			std::vector<std::unique_ptr<std::string>> vec;
			//{ new std::string("aa"), new std::string("bb"), new std::string("cc") };
			vec.reserve(5);
			vec.push_back(std::unique_ptr<std::string>(new std::string("aa")));
			vec.push_back(std::make_unique<std::string>(std::string("bb")));
			vec.push_back(std::make_unique<std::string>("cc"));


			__asm nop
			//??? ����������� ����������� ��������� ��������?
		 //???

		//1.c - ��������� ������� 1.b �������� ����������� �������� ���������� ������
		 //��������� ������� (��������, �������� ��������� �������: "AAA" -> "AAA_1")  
			for ( auto& i : vec )
			{
				*i += "_1";
			}


			__asm nop
		}

		{//1.d - ������������ ������ ��������	

		 //�������� unique_ptr, ������� �������� �������� ��� ������������� �������
		 //� ���������� std::string
		 //� ������� unique_ptr::operator[] ��������� ��������� ������ ����������
		 //����� ���������� ������������ ������?
			int size = 10;
			std::unique_ptr<int[]> arr(new int[ size ]);
			for ( size_t i = 0; i < size; i++ )
			{
				arr[ i ] = i * 2;
				std::cout << arr[i] << " ";
			}

			__asm nop
		}

		{//1.e - ������� ������������ �������� � ���������������� delete-������� (�������)
		 //����� �������� ������ ���������� �� ����������� ��������� �������
		 //�������� unique_ptr ��� ������ �������
		 //���������� ���������������� delete-������� (�������) ��� ����������� 
		 //������������ ������

			std::string* arStrPtr[] = { new std::string("aa"), new std::string("bb"), new std::string("cc") };

			auto deleter = [ s = std::size(arStrPtr) ](std::string** str)
			{
				for ( size_t i = 0; i < s; i++ )
				{
					delete str[ i ];
				}
			};
			std::unique_ptr<std::string*, decltype( deleter )> arrStr(arStrPtr, deleter);

			
			__asm nop
		}

		{
			// ����� � ������� - �������
			std::string* arStrPtr[] = { new std::string("aa"), new std::string("bb"), new std::string("cc") };

			std::unique_ptr<std::string*, Mydeleter> arrStr(arStrPtr, Mydeleter(std::size(arStrPtr)));	
		}

		{
			// ����� ������� - �������
			std::string* arStrPtr[] = { new std::string("aa"), new std::string("bb"), new std::string("cc") };

			SIZE = std::size(arStrPtr);

			std::unique_ptr<std::string*, decltype( &deleterFoo )> arrStr(arStrPtr, deleterFoo);


			__asm nop
		}

		{//1.f �������� � ��������� ������, ���������� unique_ptr ��� ���������� �� std::string
			//����������� ��������� copy() ���������� �������� ������� � ������ ������ � ���������� 
			//���� �� ����
			//���������: ������������ ��������� � ������ std::make_move_iterator
			std::vector<std::unique_ptr<std::string>> vec;

			vec.reserve(5);
			vec.push_back(std::unique_ptr<std::string>(new std::string("aa")));
			vec.push_back(std::make_unique<std::string>(std::string("bb")));
			vec.push_back(std::make_unique<std::string>("cc"));

			std::list<std::unique_ptr<std::string>> L;
			std::copy(std::make_move_iterator(vec.begin()), std::make_move_iterator(vec.end()), std::back_inserter(L));

			__asm nop

		}
		__asm nop

	}

	////////////////////////////////////////////////////////////////////////////////
	//������� 2.shared_ptr + ���������������� delete-������� 

	//����������� ����������� ������ � ���� ������ (�������) �� ������ ���������� 
	//(��� ��������� ����� ����������� �������� ��� �������)
	//��� ��� ��� "��������" ����� �� ������� ���������� ���� ������ � ���� � ��� �� ����,
	//������� ������������ �� ����������� ������������ ����� � ��� �� ���������� FILE* =>
	//���������� �������� ��� ������ ��������� �������� shared_ptr
	//�. ������ �������� ������ �������/������� ���� ��� ������
	//�. ��� ��������� �������� ������ �������������� � �������������
	//�. ��������� �������� ��������� ������ ������� ����

	//���������: ����������� ������� ������ ����� � ������� ������� rand()
	
	{
	//��������, ��������� ������:
	char ar1[] = "Writer1";
	char ar2[] = "Writer2";


	std::string path = "test.txt";
	std::ofstream fOut(path);
	//fOut.open(path, std::ofstream::app);
	WriterDeleter writer1(fOut);
	WriterDeleter writer2 = writer1;

	for ( int i = 0; i < 10; i++ )
	{
		if ( rand() & 1 )
		{
			writer1.toFile();
		}
		else
		{
			writer2.toFile();
		}
	}

	//"��������":
	//������� writer1, writer2
	/*std::shared_ptr<std::ofstream> writer1(&fOut, WriterDeleter("test.txt"));
	std::shared_ptr<std::ofstream> writer2 = writer1;*/

	

	//fputs(ar1, stdout);
	//fputs(ar2, stdout);

	//�������� ����� �������� ��������� ������� ��������� ������ �� "���������" �������� � ����
	//���� �������
	//���������: ������� ������ ���������� � ���� ����������� ������� fputs()


	__asm nop
	}//�������� �����???

	
/***************************************************************/
//������� 3.
	{
		//��� ������ ��������� ���� string
		std::string strings[] = {"abc", "123", "qwerty", "#$%"};
		//�� ���������� ��������� ������ ������ ������������ � ������������ ����������.
		//��������� ���������� ��������������� �������� �) ��� ����������� � �) ��� ��������� �������
		//��������� � �������!

		auto comp = [](const auto& a, const auto& b)		// ���������� ��� ���������� �������� � set
		{
			return (*a < *b);
		};

		std::set<std::shared_ptr < std::string>, decltype( comp )> s(comp);		// set  ��� ��������  ��������

		//� std::set "����������" �� �������� ������� ��� �����, ������� �������� ������ ����� 
		for ( size_t i = 0; i < sizeof(strings) / sizeof(strings[0]); i++ )
		{
			auto temp = strings[ i ];
			int k = 0;
			bool flag = true;
			while ( temp[k] )
			{
				if ( !std::isalpha(temp[k]) )			//  ���������� ��� ������ �����
				{
					flag = false;
					break;
				}
				k++;
			}
			
			if ( flag )
			{
				s.insert(std::shared_ptr<std::string>(&strings[ i ], [](std::string*) { }));
			}
		}

		__asm nop
		/******************************************************************************************/

		//� std::vector "����������" ������� ��� �����, ������� �������� ������ ����� 
		//������� �� �����
		//������� �����
		
		std::vector<std::shared_ptr < std::string>> vec;
	
		for ( size_t i = 0; i < sizeof(strings) / sizeof(strings[ 0 ]); i++ )
		{
			auto temp = strings[ i ];
			int k = 0;
			bool flag = true;
			while ( temp[ k ] )							// �������� �� �������
			{
				if ( !std::isdigit(temp[ k ]) )			//  ���������� ��� ������ �����
				{
					flag = false;
					break;
				}
				k++;
			}
			if ( flag )
			{
				vec.push_back(std::shared_ptr<std::string>(&strings[ i ], [](std::string*) { }));

			}
		}

		__asm nop

		/******************************************************************************************/
		//���� "����������" ������� ��� �����, ������� �� �������� �� �������� ����, �� �������� ����
		//� ������ �������
		std::vector<std::shared_ptr < std::string>> vec2;
		for ( size_t i = 0; i < sizeof(strings) / sizeof(strings[ 0 ]); i++ )
		{
			auto temp = strings[ i ];
			int k = 0;
			bool flag = true;
			while ( temp[ k ] )							// �������� �� �������
			{
				if ( (std::isalpha(temp[ k ])) || (std::isdigit(temp[ k ])) )			//  ���������� ��� �� ����� �� �����
				{
					flag = false;
					break;
				}
				k++;
			}
			if ( flag )
			{
				vec2.push_back(std::shared_ptr<std::string>(&strings[ i ], [](std::string*) { }));

			}
		}

		__asm nop
	}

	
/******************************************************************************************/
//������� 4. 
	{
		//����:
		std::string ar[] = {"my","Hello", "World"};
		std::vector < std::shared_ptr<std::string>> v = {std::make_shared<std::string>("good"), std::make_shared<std::string>("bye")};
		
		//�) ��������� �������� � ������ ������� ��� ��������� �������, �� ������� �������� �������! 
		v.reserve(std::size(ar) + v.size());	// �������� ������
		for ( auto& i : ar )					// �������� �� �������
		{
			v.push_back(std::shared_ptr<std::string>(&i, [](const std::string*) { }));		// ��������� � ������� �� ������� ������
		}

		//�) ������������� ������ �� �������� � ������� �� �����
		std::sort(v.begin(), v.end(), [](auto& x, auto& y) { return *x < *y; });			// ���������

		__asm nop

		//�) ���������� ���������� ������������ ������
		 // deleter  � ����  ������ [](const std::string*) { }  ������������ ���������� �������� ������.  


	}// ���������� ����������� ������� ����� ������������� ������


	/***************************************************************/
		//������� 5. shared_ptr � weak_ptr
		//������� ��������������� ������ ����������� ������ human. � ������ ��������:
		//��� - string
		//�������� �������: ��� ��� ��� ���...
		//�������� - shared_ptr (�������� �� ������ ��������...)
		//���� - ��������� �� weak_ptr (����� �������� ����������� ������������)

		//������ ������ human:
		//����������� - ��� ������������� ����� � ��������
		//����������� �����������, �������� ������������, move ???
		//����������� ����� child() - 
		//				������ ������� ������� � ������� ������� ��� ����������� ��������
		//				+ ������������ ��� ����� ������� � ���������� � ��������

		//������ ����������� ����������� ��������������� ������ ��� ���������� ����������

	{
		//������� ������ � ����-�� ���������� => "����-���� ��� �� ����, ��������, ���� � ���"
		//(�� ���� �� ����� ���� ��� ���� � ��� ����):


		std::shared_ptr<human> grandM1(new human("Eva"));
		std::shared_ptr<human> grandF2(new human("Adam"));
		auto first = human::childCreate("First", grandM1, grandF2);

		//childCreate();
		//� ��� ��������� ���� - child():


		//� � ����� � ���� ������� ���� ����:


		//...
		__asm nop
	}





	__asm nop

}