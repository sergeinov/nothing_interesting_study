#include "Hex.h"
#include <iostream>

void Hex::ShowHex() const
{
	std::cout << "\nHex: ";
	std::cout << std::hex<< he;
};