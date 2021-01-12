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

	// ������
	char* getChar();

	void ShowBin();
	void ShowHex();
	void ShowOct();
};


