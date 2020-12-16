// пример циклической перестановки. Когда мы сдвигаем массив вправо, 
// не теряя выпавший элемент, а ставим его в начало.
// получается кольцевая перестановка

#include <iostream>

int main()
{
	int arrCircle[] = { 4, 5, 6, 7, 8, 9, 10 };
	int sizeArr = sizeof(arrCircle) / sizeof(arrCircle[0]);  // размер массива  // 7

	int temp = arrCircle[sizeArr - 1];		// сохраняем последний элемент

	// кольцевая перестановки в право
	for (int i = sizeArr - 2; i >= 0; i--)
	{
		// сдвигаем вправо на 1 позицию
		arrCircle[i + 1] = arrCircle[i];
	}
	arrCircle[0] = temp;		// ставим элемент вперед

	// вывод массива
	for (int i = 0; i < sizeArr; i++)
	{
		std::cout << arrCircle[i] << " ";
	}
}