// Программа

#include <iostream>

namespace First
{
	int version = 4;
}

namespace Second
{
	int version = 5;
}

int main()
{
	setlocale(LC_ALL, "ru");

	std::cout << First::version << std::endl;
	std::cout << Second::version << std::endl;

	return 0;
}