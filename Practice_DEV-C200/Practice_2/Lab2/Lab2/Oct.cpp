#include "Oct.h"
#include <iostream>

//�����������


void Oct::ShowOct() const
{
	std::cout << "\nOct: ";
	std::cout << std::oct << o2 << o1 << o0 ;
};