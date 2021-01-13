#include "Bin.h"
#include<iostream>

void Bin::ShowBin() const
{
	std::cout << "\nBin: ";
	std::cout << static_cast<int>(b7);
	std::cout << static_cast<int>(b6);
	std::cout << static_cast<int>(b5);
	std::cout << static_cast<int>(b4);
	std::cout << static_cast<int>(b3);
	std::cout << static_cast<int>(b2);
	std::cout << static_cast<int>(b1);
	std::cout << static_cast<int>(b0);
};



