#pragma once

#include"Node.h"

class List
{
private:
	Node Head;				// признак начала списка (страж)
	Node Tail;				// признак конца списка (страж)
	size_t m_size;			// количество элементов в списке
public:
	List();
	~List();

	
	/*
	TODO
	- метод добавляет элемент к конец списка
	- сделать список пустым. Удалить все объекты
	*/

	// методы
	void AddToHead(const Circle& figure);	// добавить в начало списка
	bool RemoveOne(const Circle& figure);	// удалить один из списка
	int RemoveAll(const Circle& figure);	// удалить все списка



	/*
	TODO
	1.	сортировку по возрастанию площади объекта.
	2.	Вывод текущего состояния списка на консоль
		cout << l;
	3.	Вывод текущего состояния списка в файл(в форматированном виде)
	#include <fstream>
		ofstream fout(ar);
		fout << l;
		fout.close();
	4.	Чтение из файла
	*/
};

