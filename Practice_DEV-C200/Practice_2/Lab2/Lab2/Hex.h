#pragma once

class Hex 
{
private:
	unsigned char he0:4;
	unsigned char he1:4;
	void ShowHex() const;
	friend union MyByte;
};

