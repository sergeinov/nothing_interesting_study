#include "Byte.h"

// конструктор
MyByte::MyByte()
{
	myC = 0;
};
MyByte::MyByte(char c)
{ 
	myC = c; 
}

// методы
char* MyByte::getChar()
{
	return &myC;
};

void MyByte::ShowBin() const
{
	b_bin.ShowBin();
};

void MyByte::ShowHex() const
{
	h_hex.ShowHex();
};
void MyByte::ShowOct() const
{
	o_oct.ShowOct();
};
