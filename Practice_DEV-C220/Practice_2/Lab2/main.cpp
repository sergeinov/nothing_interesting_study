
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include<iterator>

#include"MyVector.h"
#include"MyQueue.h"

int main()
{
   
	MyVector<int> vec{ 0, 10, {33, 5, 5, 10, 22, 10, 10, 22, 34} };
	vec.Add({24, 1, 9});			
	//vec.Delete({ 10, 5 });
	vec.Sort(true);	
	__asm nop

	vec.Sort(false);
	__asm nop

	vec.clearValues();
	__asm nop
	//*********************************************************//

	MyQueue<int> que;
	MyQueue<int>::iterator itb = que.begin();
	que.push(5);
	que.push(10);
	que.push(12);
	que.push(3);
	for ( const auto& i : que )
	{
		std::cout << i << " ";
	}


	__asm nop



	//*********************************************************//
	/*
	MyUniquePTR<MyString> p1(new MyString(�abc�));
	std::cout << p1->GetString();
	p1->SetNewString(�qwerty�);
	MyString  s2 = *p1;
	MyUniquePTR< MyString > p2 = p1; //����� ���������� ������ �������� ������ =>  //���������!

		if(p1) //� ��� ������ ��������
		{ 
			std::cout << �No object!� 
		} 

	MyUniquePTR< MyString > p3(new MyString(�vvv�));
	p3 = p2;	//� ����� ���������� ������ �������� ������

	vector< MyUniquePTR< MyString >> v; //��� �������������������???
	list< MyUniquePTR< MyString >> l;   //��� ����������� �� v � l ???
	*/
}


