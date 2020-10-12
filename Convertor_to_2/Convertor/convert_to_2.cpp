// Программа конвертирования  в двоичную систему 

#include <iostream>

//TODO перезагрузить функцию под разные типы данных

// функция конвертирования в двоичную
long convert_to_2(int x) {
	int i;
	int mod;
	long result = 0;

	for (i = 0; x > 0; i++) {

		mod = x % 2;
		x = (x - mod) / 2;
		result += mod * pow((double)10, i);
	}
	return result;

}

int main()
{
	setlocale(LC_ALL, "ru");

	std::cout << convert_to_2(10);

	return 0;
}