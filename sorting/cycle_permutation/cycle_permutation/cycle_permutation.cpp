// ������ ����������� ������������. ����� �� �������� ������ ������, 
// �� ����� �������� �������, � ������ ��� � ������.
// ���������� ��������� ������������

#include <iostream>

int main()
{
	int arrCircle[] = { 4, 5, 6, 7, 8, 9, 10 };
	int sizeArr = sizeof(arrCircle) / sizeof(arrCircle[0]);  // ������ �������  // 7

	int temp = arrCircle[sizeArr - 1];		// ��������� ��������� �������

	// ��������� ������������ � �����
	for (int i = sizeArr - 2; i >= 0; i--)
	{
		// �������� ������ �� 1 �������
		arrCircle[i + 1] = arrCircle[i];
	}
	arrCircle[0] = temp;		// ������ ������� ������

	// ����� �������
	for (int i = 0; i < sizeArr; i++)
	{
		std::cout << arrCircle[i] << " ";
	}
}