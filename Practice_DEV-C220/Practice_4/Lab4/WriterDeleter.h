#pragma once
#include<iostream>
#include<ostream>
#include<fstream>
#include<string>



class WriterDeleter
{
	std::shared_ptr<std::ofstream> sf;
	std::string message;
    static int n_writer;

public:


    WriterDeleter(std::ofstream& f) : sf(&f, [](std::ofstream* p) { p->close(); })
    {
        n_writer++;
        message = std::to_string(n_writer);
    }
    WriterDeleter(const WriterDeleter& other) : sf(other.sf)
    {
        n_writer++;
        message = std::to_string(n_writer);
    }


    void toFile()
    {
        ( *sf ) << message << std::endl;
    }
};

