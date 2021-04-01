
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
	MyUniquePTR<MyString> p1(new MyString(УabcФ));
	std::cout << p1->GetString();
	p1->SetNewString(УqwertyФ);
	MyString  s2 = *p1;
	MyUniquePTR< MyString > p2 = p1; //здесь компил€тор должен выдавать ошибку =>  //»справьте!

		if(p1) //а это должно работать
		{ 
			std::cout << ФNo object!Ф 
		} 

	MyUniquePTR< MyString > p3(new MyString(УvvvФ));
	p3 = p2;	//и здесь компил€тор должен выдавать ошибку

	vector< MyUniquePTR< MyString >> v; //как проинициализировать???
	list< MyUniquePTR< MyString >> l;   //как скопировать из v в l ???
	*/
}


