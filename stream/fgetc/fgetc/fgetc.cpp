// ��������� ����������� ��������� � �����. 
// �������������: ...exe  file.txt

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".1251");
	using namespace std;

	FILE* file;				// ���������� ��� ����� ������
	char ch;				// ���������� ��� ������ � �����

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
	while ((ch = fgetc(file)) != EOF)
	{
		cout << ch;			// ����� �������
	}

	// ������� ����
	fclose(file);

	return 0;
}
