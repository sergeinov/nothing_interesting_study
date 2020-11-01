//  пример пузырьковой сортировки на с++

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int arr[] = {7, 2, -5, 6, 0, 3, 2, 5, 3, -9, 99, 100};  // массив чисел
    int sizeArr = sizeof(arr) / sizeof(int);  // размер массива

    // проходим по всему массиву
    for (size_t i = 0; i < sizeArr; i++)
    {
        // поиск из оставшихся неупорядоченных чисел
        for (size_t j = 0; j < sizeArr - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
            // обмен местами значения текущего и минимального элементов
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            }
        }
  
        // вывод массива
        std::cout << i+1 << " круг: \t";
        for (auto& i : arr)
        {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }
    // второй вариант без лишней сортировки
    /*
     for (size_t i = 0; i < sizeArr; i++)
    {
    bool flag = false;
        // поиск из оставшихся неупорядоченных чисел
        for (size_t j = 0; j < sizeArr- 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
            // обмен местами значения текущего и минимального элементов
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
