// ¬ариант программы копировани€ строки массива в другой массив

#include <iostream>

char* myStrCopy(char* destination, char* source)
{
    //// первый способ: бесконечный цикл.
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

    //// вариант второй. ѕрисваивание в условии
    //char* res;
    //for (res = destination;  (*destination = *source) ; )
    //{
    //    destination++;
    //    source++;
    //}
    //return res;

    //третий вариант
    char* res;
    // присваивание в условии с постфиксным увеличением адреса на + 1
    for (res = destination; (*destination++ = *source++););

    return res;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char arr1[] = { "String One" };
    char arr2[] = { "String two" };
    myStrCopy(arr1, arr2);

    //вывод destination
    std::cout << "¬ывод результата: " << std::endl;
    for (size_t i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        std::cout << arr1[i ];
    }
}

