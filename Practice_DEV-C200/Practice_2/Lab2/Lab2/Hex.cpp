#include "Hex.h"
#include <iostream>

// конструкторы
Hex::Hex()
{
	byte = 0;
};


void Hex::ShowHex()
{
	std::cout << std::hex << byte.getChar() << std::endl;
};