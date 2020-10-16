// Test namespace
#include <iostream>

namespace First
{
	int version = 4;
}

namespace Second
{
	int version = 5;
}
// теперь возможно использовать переменную version глобально
using namespace Second;

namespace Third
{
	int version = 9;
}
// псевдоним для пространста имен Third
namespace ver = Third;

int main()
{
	setlocale(LC_ALL, "ru");

	std::cout << First::version << std::endl;
	// использование с пространства имен Second
	std::cout << version << std::endl;

	std::cout << "----------------" << std::endl;
	// использование псевдонима
	std::cout << ver::version << std::endl;

	return 0;
}
