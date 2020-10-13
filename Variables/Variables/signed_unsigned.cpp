// Сравнение знаковых и беззнаковых переменных

#include <iostream>

void signedVariables()
{
	int x = 0x1;			// 1
	int y = 0xffffffff;		// -1

	if (x > y)				// true, т.к. 1 > -1
	{
		std::cout << "(signed) " << x << " больше " << y << std::endl;
	}
	else
	{
		std::cout << "(signed) " << x << " меньше " << y << std::endl;
	}

}

void unsignedVariables()
{
	unsigned int x = 0x1;				// 1
	unsigned int y = 0xffffffff;		// -1

	if (x > y)							// false т.к.  1 < 4294967295
	{
		std::cout << "(unsigned) " << x << " больше " << y << std::endl;
	}
	else
	{
		std::cout << "(unsigned) " << x << " меньше " << y << std::endl;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");

	signedVariables();
	unsignedVariables();

	return 0;
}