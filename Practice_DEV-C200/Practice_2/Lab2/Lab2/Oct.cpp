#include "Oct.h"
#include <iostream>

//�����������


void Oct::ShowOct() const
{
	std::cout << "\nOct: ";
	std::cout.setf(std::ios::oct);
	std::cout << oc;
};