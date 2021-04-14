#pragma once
#include<memory>
#include<iostream>


class human
{
	std::shared_ptr<std::string > perents;
	std::weak_ptr<std::string > child;

public:
	human();



	static void childP();
};

