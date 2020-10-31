//  пример сортировки выбором на с++ от меньшего к большему

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int arr[] = { 7, 2, -5, 6, 0, 3, 2, 5, 3, -9, 99, 100 };  // массив чисел
    int sizeArr = sizeof(arr) / sizeof(int);  // размер массива

    // проходим по всему массиву
    for (int i = 0; i < sizeArr - 1; i++)
    {
        // здесь индекс с наименьшим элементом
        int indexMin = i;

        // поиск наименьшего из оставшихся неупорядоченных чисел
        for (int j = i + 1; j < sizeArr; j++)
        {
            if (arr[j] < arr[indexMin])
            {
                indexMin = j;
            }
        }
        // обмен местами значения текущего и минимального элементов
        int temp = arr[indexMin];
        arr[indexMin] = arr[i];
        arr[i] = temp;

        // вывод массива
        std::cout << i + 1 << " круг: \t";
        for (auto& i : arr)
        {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }
}
