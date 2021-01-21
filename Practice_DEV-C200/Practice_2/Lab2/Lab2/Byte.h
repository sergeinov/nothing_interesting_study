#pragma once
#include "Oct.h"
#include "Hex.h"
#include "Bin.h"

union MyByte
{
private:
	char myC;		// �������� ��� ��������� ��������
	Bin b_bin;
	Hex h_hex;
	Oct o_oct;
public:
	// �����������
	MyByte();
	MyByte(char c);
	MyByte(unsigned char x, unsigned char y)
	{
		h_hex.he1 = x;
		h_hex.he0 = y;
	};

	// ������
	//char getChar() const;

	void ShowBin() const;
	void ShowHex() const;
	void ShowOct() const;
};


