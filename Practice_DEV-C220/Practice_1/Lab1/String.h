#pragma once
#include<iostream>

class String
{
	size_t len;
	char* str;
public:
	String() : len(0), str(nullptr) { };

	const char* operator-(char* s)
	{	
		for ( size_t i = 0; i < strlen(s); i++ )
		{
			s[i] = toupper(s[i]);
		}
		return s;
	}

	friend std::ostream& operator<<(std::ostream& out, const String& s);

};

