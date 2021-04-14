#pragma once
#include<iostream>
#include<ostream>
#include<fstream>



class WriterDeleter
{
	std::string fileName;
	std::shared_ptr<std::ofstream> fStr;

public:
	//WriterDeleter(const std::string& str, std::ofstream& f) : fileName(str), fStr(&f, &f->close())  { };
	/*void operator()(std::ofstream* fp)
	{
		fp->close();
	}*/
};

