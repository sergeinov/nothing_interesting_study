// круговой буффер


#include <iostream>

int main()
{
	int arrCircle[] = { 4, 5, 6, 7, 8, 9, 10 };
	int sizeArr5 = sizeof(arrCircle) / sizeof(arrCircle[0]);  // размер массива  // 7

	int last = sizeArr5 - 1;

	for (int i = 0; i < sizeArr5; i++)
	{
		// используем вывод по индексу
		std::cout << arrCircle[(last++) % sizeArr5] << " ";  // 6, 0 , 1, 2, 3, 4, 5
	}
}

