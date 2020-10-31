//  ������ ���������� ������� �� �++ �� �������� � ��������

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int arr[] = { 7, 2, -5, 6, 0, 3, 2, 5, 3, -9, 99, 100 };  // ������ �����
    int sizeArr = sizeof(arr) / sizeof(int);  // ������ �������

    // �������� �� ����� �������
    for (int i = 0; i < sizeArr - 1; i++)
    {
        // ����� ������ � ���������� ���������
        int indexMin = i;

        // ����� ����������� �� ���������� ��������������� �����
        for (int j = i + 1; j < sizeArr; j++)
        {
            if (arr[j] < arr[indexMin])
            {
                indexMin = j;
            }
        }
        // ����� ������� �������� �������� � ������������ ���������
        int temp = arr[indexMin];
        arr[indexMin] = arr[i];
        arr[i] = temp;

        // ����� �������
        std::cout << i + 1 << " ����: \t";
        for (auto& i : arr)
        {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }
}
