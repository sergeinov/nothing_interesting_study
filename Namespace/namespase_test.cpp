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
// использование директивы using
using namespace Second;

namespace Third
{
	int version = 9;
}
// использование псевдонима
namespace ver = Third;

int main()
{
	setlocale(LC_ALL, "ru");

	std::cout << First::version << std::endl;
	// появляется возможность использовать пространство Second без оператора ::
	std::cout << version << std::endl;

	std::cout << "----------------" << std::endl;

	std::cout << ver::version << std::endl;

	return 0;
}