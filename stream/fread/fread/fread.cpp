// Программа посимвольно считывает с файла. 
// Использование: ...exe  file.txt
// Функция fread (): чтение байтов из потока

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cerrno>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".1251");
	using namespace std;

	FILE* file;				            // переменная для фалйа потока
	unsigned char buffer[1024];         // будет хранится байты прочитанный из файла (1 килобайт)
	int read;                           // для чтения цифр с потока

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
	do
	{
		read = fread(buffer, 1, sizeof(buffer), file);
		for (size_t i = 0; i < read; i++)
			printf("%02X ", buffer[i]);      //  печатаем содержимое побайтно, преобразовывая значения в шестнадцатеричные
	} while (read > 0);

	// закрыть файл
	fclose(file);

	return 0;
}
