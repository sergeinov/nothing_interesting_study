// Программа посимвольно считывает с файла. 
// Использование: ...exe  file.txt

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".1251");
	using namespace std;

	FILE* file;				// переменная для фалйа потока
	char ch;				// переменная для сивола с файла

	// проверка что есть аргумент argc (В данном случае указываем имя файла)
	if (argc != 2)
	{
		cout << "Укажите имя файла!" << endl;
		return 1;
	}

	// проверить доступность файла
	if ((file = fopen(argv[1], "rt")) == NULL)
	{
		cout << "Ошибка доступа к файлу. Ошибка открытия!" << endl;;
		return 2;
	}

	// чтения из файла посимвольно
	while ((ch = fgetc(file)) != EOF)
	{
		cout << ch;			// вывод символа
	}

	// закрыть файл
	fclose(file);

	return 0;
}
