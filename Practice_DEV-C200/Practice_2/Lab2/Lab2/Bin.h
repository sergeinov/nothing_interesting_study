#pragma once
#include "Byte.h"
class Bin
{
private:
	MyByte byte;
	unsigned char b0 : 1;
	unsigned char b1 : 1;
	unsigned char b2 : 1;
	unsigned char b3 : 1;
	unsigned char b4 : 1;
	unsigned char b5 : 1;
	unsigned char b6 : 1;
	unsigned char b7 : 1;
public:
	void ShowBin();
};

