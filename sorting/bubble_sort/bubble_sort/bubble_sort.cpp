//  ������ ����������� ���������� �� �++

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int arr[] = {7, 2, -5, 6, 0, 3, 2, 5, 3, -9, 99, 100};  // ������ �����
    int sizeArr = sizeof(arr) / sizeof(int);  // ������ �������

    // �������� �� ����� �������
    for (size_t i = 0; i < sizeArr; i++)
    {
        // ����� �� ���������� ��������������� �����
        for (size_t j = 0; j < sizeArr - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
            // ����� ������� �������� �������� � ������������ ���������
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            }
        }
  
        // ����� �������
        std::cout << i+1 << " ����: \t";
        for (auto& i : arr)
        {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }
    // ������ ������� ��� ������ ����������
    /*
     for (size_t i = 0; i < sizeArr; i++)
    {
    bool flag = false;
        // ����� �� ���������� ��������������� �����
        for (size_t j = 0; j < sizeArr- 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
            // ����� ������� �������� �������� � ������������ ���������
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;

            flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    */
}
