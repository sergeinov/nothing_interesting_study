
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
	//vec.Add({24, 35, 9});			// reserve
	//vec.Delete({ 10, 5 });
	//vec.Sort(true);					// true - по возрастанию  false - по убыванию

	MyQueue<int> que;
	MyQueue<int>::iterator itb = que.begin();

	__asm nop

}


