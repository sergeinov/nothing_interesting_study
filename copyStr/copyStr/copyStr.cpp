// ������� ��������� ����������� ������ ������� � ������ ������

#include <iostream>

char* myStrCopy(char* destination, char* source)
{
    //// ������ ������: ����������� ����.
    //char* res = destination;
    //for (; ;)
    //{
    //    if (!(*destination = *source))
    //    {
    //        break;
    //    }
    //    destination++;
    //    source++;
    //}
    //return res;

    //// ������� ������. ������������ � �������
    //char* res;
    //for (res = destination;  (*destination = *source) ; )
    //{
    //    destination++;
    //    source++;
    //}
    //return res;

    //������ �������
    char* res;
    // ������������ � ������� � ����������� ����������� ������ �� + 1
    for (res = destination; (*destination++ = *source++););

    return res;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char arr1[] = { "String One" };
    char arr2[] = { "String two" };
    myStrCopy(arr1, arr2);

    //����� destination
    std::cout << "����� ����������: " << std::endl;
    for (size_t i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        std::cout << arr1[i ];
    }
}

