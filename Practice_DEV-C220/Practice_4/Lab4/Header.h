#pragma once
#include<string>

class Mydeleter
{
	size_t size;
public:
	Mydeleter(size_t s) : size(s) { };
	void operator()(std::string** str) {
		for ( size_t i = 0; i < size; i++ )
		{
			delete str[ i ];
		}
	}
};



