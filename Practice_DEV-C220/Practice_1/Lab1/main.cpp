//�������� 1:
// enum class
// initializer_list � ������������� ������ �������������
// auto
// decltype
// lambda 
// template variable

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
#include <set>
#include"template.h"
#include"String.h"
#include <list>
#include <deque>


std::ostream& operator<<(std::ostream& out, const String& s) 
{ 
	return out << s.str;
};

// ������� 10
// �������������
template <> std::map<std::string, COLOR> mp<COLOR> { {"GREEN", COLOR::GREEN }, {"YELLOW", COLOR::YELLOW}};
template <> std::map<std::string, DAYS> mp<DAYS> { {"MONDAY", DAYS::MONDAY}, {"TUESDAY", DAYS::TUESDAY}};


int main()
{
	//������� 1. 
	{
		enum class months { January, February, March/*...*/ };
		enum class weekDays { Monday, Tuesday /*...*/ };

		months m = months::January;			// ������� ���������
		//�) ������� �������� (��� ������, ��� ���������� ��
		//������ ��������� ������������ ������������ �������
		//���������!)
		// �������� � ���������  ������ ����� enum
		// ����� �++17 ��������� ����������� �������� � ������������ class

		// if (m == Monday)	// ������
		// if ( m == weekDays::Monday ) // ������ d ���������  ������ ����� enum
		if ( static_cast< weekDays >(m) == weekDays::Monday )		// ���������� ���� months -> weekDays
		{ 
			/*...*/ 
		}

		//�) ������������� ������������� ������
		{
			enum class months : unsigned char { January, February, March/*...*/ };
			months year[] = { months::January, months::February, months::March };

			size_t n = sizeof(year); // !  3  ��� ����������� // 12

			__asm nop
		}
	}


/**********************************************************/
	//������� 2. �������� � � ������� ������ �������������
	//��������� ���������� ������ � ���������� - string
	//� ������� range-based for ������������ ��� ����� � 	
	//������� ������� � ��������� ������� ������ ��������
	//�����������
	{
		std::vector<std::string> vect{"robot3", "car1", "plane12", "bus34"};
		for ( auto& i : vect )
		{
			for ( auto& j : i )
			{
				j = toupper(j);
			}
		}
		for ( const auto& i : vect )
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		__asm nop
	}


/**********************************************************/
	///������� 3. �������� � ��������� ����������
	//map ����� �������, ����� �� �������� � �������� �����
	//�����, � � �������� �������� ��������������� �� 
	//�������� ������������ ���� (string), ������������ �
	//���� �����
	
	//3�. ������������������ map "�������" ����������� ������ �������������
	//� ������� range-based for � structured binding
 	//������������ ����������, ��������: A: any, apple, away
	{
		//const char* words[] = { "Abba", "Alfa", "Beta", "Beauty" };
		std::map<char, std::set<std::string>> mp = { 
													{'W', {"Wer", "Was"}},
													{'A', {"Art"," Apple"} } 
													};
		for ( const auto& [ letter, word ] : mp)
		{
			std::cout << letter << ":";
			for ( const auto& i : word )
			{
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}
		
		//PrintAll(mp);
		__asm nop
	}

	//3�. �������� ������ map � ����������� �������� ������
	//��� ���������� �������.
	//� ������� range-based for � structured binding
	//������������ ����������, ��������: A: any, apple, away
	{
		//���� (��������):
		const char* s[] = { "yong", "away", "bar", "any", "son", "apple" };
		std::map<char, std::set<std::string>> mp2;
		for ( const auto i : s )
		{
			mp2[ tolower(i[ 0 ]) ].insert(i);
		}
		// ��������
		for ( const auto& [letter, word] : mp2 )
		{
			std::cout << static_cast<char>(toupper(letter)) << ":";
			for ( const auto& i : word )
			{
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}


		__asm nop
	}


/*********************************************************/
	//������� 4. ������� ������� ��� ������ �� ������
	//��������� �������������������, �������� ����:
	{
		std::vector<double> vd = { 1.1,2.2,3.3 };
		PrintAnyCont(vd);

		std::string s("abc");
		PrintAnyCont(s);

		int ar[] = { 1, 2, 3 };
		PrintAnyCont(ar);

		std::initializer_list<int> il{ 3,4,5 };
		PrintAnyCont(il);		

		__asm nop
	}


/********************************************************/
	///������� 5. 	
	//C������ ������� ��� "���������" ��������, ��������:
	//����: {1, -2, 5}, �����: {-1, 2, -5})
	//��������� �������� ���� std::string ����� ��������� "aBc1" -> "AbC1"
	//��������� �������������������, �������� ����:

	//  ����������� operator-  ��� string/  ��� ��������� ������������ tolower/toupper
	{
		std::cout << "\n" << "Negative convertor:" << std::endl;
		std::vector<double> vd{ 1.1,2.2,3.3 };
		NegateAll(vd);
		PrintAnyCont(vd);

		std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
		NegateAll(ls);
		PrintAnyCont(ls);

		int ar[]{ 1, 2, 3 };
		NegateAll(ar);
		PrintAnyCont(ar);

		__asm nop

	}

	
/********************************************************/
	//������� 6. ����������� ������� ���������� �� ������
	//��������� �������������������, �������� ����
	//���������� ��� ���������� ����� ������������ ����������
	//�������� sort(), � ��� ������� ������� - ������-�������
	{
		std::cout << "\n" << "Sort:" << std::endl;
		std::vector<double> vd = { -3.3,  2.2, -1.1 };
		absSort(vd);
		PrintAnyCont(vd);
		__asm nop

		int ar[] = { -3, 2, -1 };
		absSort(ar);
		PrintAnyCont(ar);
		__asm nop
	}


/********************************************************/
	//������� 7.
	//�������� �������, ������� ����� ����������� �
	//���������� ������, ������ ������� 
	//�������� �������� ������ ��������� ���� 
	//������������������� ������ �����
	//� � ���������� ������� ����.

	//��������� 1: ��� ��� ������������������ ����� ����
	//������ �����, ������� ������� ������ ���������������
	//������� ������������ �� ����
	 
	//��������� 2: ��������� � ����������� �������������
	//���������� copy() � transform(), � ������� 
	//���������������� �������� ������ � ���� �������
	//�������� ������-��������

	//��������:
	{
		std::cout << "\n" << "Sort:" << std::endl;

		std::vector<int> v{ 1,2,3,4 };
		std::list<double> lt{ 1.1, 2.2, 3.3, 4.4, 5.5 };

		auto resultVector = SumCont(v, lt);
		PrintAnyCont(resultVector);

		std::list<int> ll{ 1, 2, 3, 4, 5, 6, 7, 8 };
		double ar[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		auto resultVector2 = SumCont(ar, ll);
		PrintAnyCont(resultVector2);

		std::set<std::string> s{ "abc", "qwerty", "my"};
		std::deque<const char*> d{ "111", "22" };
		auto resultVector3 = SumCont(s, d);
		PrintAnyCont(resultVector3);

		__asm nop
	}


/********************************************************/	
	//������� 8. ���������� �������, ������� ��������� ��������� ���������:	
	//�������������� ������������������ ������ ���� � ���������� ������ ����, 
	//��� (������) ���������� ������ ���� �� vector, list, deque, set 
	//� ���������� ���� �� ����, ��� � � �������������� ������������������ 

	//������� ������ "���������" �������� �������� ������������������ � ��� ������ ���������� 
	//�������� ��������� �������. ������� ������ �����-��������
	//�������� ������������������ ��� ���� �� ��������
	{
		std::cout << "\n" << "Separate:" << std::endl;
		////��������:
		std::vector<int> v{ 1,2,3,4,5 };
		std::list<int> l; //���� ������
		std::deque<int> d; //� ���� ��������
		Separate(v, l, d, [](auto num) 
			{
				return  num % 2;
			});

		PrintAnyCont(l);
		PrintAnyCont(d);
		__asm nop
	}


/********************************************************/
	//������� 9. C ������� ��������� for_each()!!! 
	//(� �� count_if()) ��������� ������� ���� � �������
	//��������.
	//  ������������ ������ �������
	{
		char s[] = "Hello World!";


		//for_each

		int count = 0;
		auto result = std::for_each(s, std::end(s), [&count] (char v)
			{ 
				if ( isupper(v) )		// �������� ��������, ��� ����� �������
				{
					count++;			// ������� ������� ����
				}
			});
		
		std::cout <<  "\n" << "count: " << count << std::endl;
		__asm nop
	}


/********************************************************/
	//������� 10. ����������� ����������� enum � ��������� �������������  - enumToString
	// � �������� - stringToEnum

	//���������: 
	//***********
	//1. ��������������� ����������� ���������� ������ ��� ����� ����� ���-�� ������� =>
	//1.1 ����������� ��������� � ������������ ������ ���� ����������� => ��������������� ������
	//���� ������ ���� �����������, => ���������� ������ ����� ���� ������������ � ��������
	//����� � std::map
	
	//1.2 � ��� �������� (��������������� ���������� ����������)
	//����� ���� ������ � ���� ����� ����������� (�������� ������, ������, ��� �������� �� �����������) 
	//=> �������� ��������� std::map<string,<��������> >
	
	//1.3 �������� ��������� �++11 ���������� ������������� ���� ����� ���� ������� ������� � ����,
	//� �������� �� ���������� ������������� ����������� 
	
	//***********
	//2. ��� ��� ���� ������������ ������, �� enumToString � stringToEnum ������ ���� ����������
	//2.1 ������������ ����� ��������� ��� ������������ �������� � ������� ��������, �������
	//   ������ �� ������������� => ������!
	//2.2 � �������� enumToString � stringToEnum (� ����������� �� ���� ������������) ����� �����
	//   ������������� ��������������� ������������� ���� ������������ ���������
	
	//***********
	//3. ����� �������� � map<string, <��������> > �� �������� �� ���� ������������, ��������� ��� ��������������
	//��������� ���������� (� ��������� ��������� � ����������� ������������� ��������� ����������)
	

	//***********

	{
	//��������:

		COLOR c1;
		try {
			c1 = stringToEnum<COLOR>("GREEN");
		}
		catch (...)
		{
			std::cout << "Pair undefined" << std::endl;
		}
		std::string Str;
		try
		{
			Str = enumToString(c1);
		}
		catch ( const char* )
		{
			std::cout << "error" << std::endl;
		}


		__asm nop
	}

	return 0;
}