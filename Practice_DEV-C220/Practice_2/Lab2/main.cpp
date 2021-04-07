
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include<iterator>
#include<string>

#include"MyVector.h"
#include"MyQueue.h"
#include"MyString.h"
#include"MyUniquePTR.h"

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

	MyQueue<MyString>  q1{ MyString("AAA"), MyString("qwerty")/*<другие_инициализаторы>*/ };
	for ( const auto& el : q1 ) 
	{ 
		std::cout << el << ' '; 
	}

	MyString s("abc");
	q1.push(s);
	q1.push(MyString("123"));
	MyString s1 = q1.pop();
	q1.push("qqq");
	MyQueue < MyString >  q2 = q1;
	MyQueue < MyString >  q22 = std::move(q1);
	q1.push("Test");
	q22 = std::move(q22);

	MyQueue < MyString >  q3{ 10, MyString("!") }; //очередь должна содержать 10 элементов со строкой «!» 
	q1 = q3;
	q2 = MyQueue < MyString >(5, MyString(" ? "));
	q1 = { MyString("bbb"), MyString("ssss") };

	__asm nop



	//*********************************************************//
	
	MyUniquePTR<MyString> p1(new MyString("abc"));
	std::cout << p1->GetString();
	p1->SetNewString("qwerty");
	MyString  s2 = *p1;
	//MyUniquePTR< MyString > p2 = p1; //здесь компилятор должен выдавать ошибку =>  //Исправьте! // конструктор копирования

		if(p1) //а это должно работать
		{ 
			std::cout << "No object!";
		} 

	MyUniquePTR< MyString > p3(new MyString("vvv"));
	//p3 = p2;	//и здесь компилятор должен выдавать ошибку

	std::vector< MyUniquePTR< MyString >> v; //как проинициализировать???
	v.reserve(2);
	for ( size_t i = 0; i < 2; i++ )
	{
		v.push_back(MyUniquePTR<MyString>(new MyString(std::to_string(i).c_str())));
	}
	std::list< MyUniquePTR< MyString >> l;   //как скопировать из v в l ???
	/*std::copy(std::move_iterator<decltype(v)::iterator>(v.begin()), 
		std::move_iterator<decltype( v )::iterator>(v.end()), std::back_inserter(l));*/
	std::copy(std::move_iterator(v.begin()), 
		std::move_iterator(v.end()), std::back_inserter(l));
}


