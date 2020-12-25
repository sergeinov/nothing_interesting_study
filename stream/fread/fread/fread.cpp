// ��������� ����������� ��������� � �����. 
// �������������: ...exe  file.txt
// ������� fread (): ������ ������ �� ������

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cerrno>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".1251");
	using namespace std;

	FILE* file;				            // ���������� ��� ����� ������
	unsigned char buffer[1024];         // ����� �������� ����� ����������� �� ����� (1 ��������)
	int read;                           // ��� ������ ���� � ������

	// �������� ��� ���� �������� argc (� ������ ������ ��������� ��� �����)
	if (argc != 2)
	{
		cout << "������� ��� �����!" << endl;
		return 1;
	}

	// ��������� ����������� �����
	if ((file = fopen(argv[1], "rt")) == NULL)
	{
		cout << "������ ������� � �����. ������ ��������!" << endl;;
		return 2;
	}

	// ������ �� ����� �����������
	do
	{
		read = fread(buffer, 1, sizeof(buffer), file);
		for (size_t i = 0; i < read; i++)
			printf("%02X ", buffer[i]);      //  �������� ���������� ��������, �������������� �������� � �����������������
	} while (read > 0);

	// ������� ����
	fclose(file);

	return 0;
}
