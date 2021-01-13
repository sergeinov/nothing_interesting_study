#pragma once
#include "Oct.h"
#include "Hex.h"
#include "Bin.h"

union MyByte
{
private:
	char myC;		// значение для обработки методами
	Bin b_bin;
	Hex h_hex;
	Oct o_oct;
public:
	// конструктор
	MyByte();
	MyByte(char c);

	// методы
	//char getChar() const;

	void ShowBin() const;
	void ShowHex() const;
	void ShowOct() const;
};


