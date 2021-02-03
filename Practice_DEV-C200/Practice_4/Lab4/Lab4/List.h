#pragma once

#include"Node.h"
#include<iostream>

class List
{
private:
	Node Head;				// признак начала списка (страж)
	Node Tail;				// признак конца списка (страж)
	size_t m_size;			// количество элементов в списке
public:

	// конструкторы
	List();
	List(const List& otherList);	// конструктор копирования
	List(List&& otherList);			// конструктор перемещения move
	~List();



	// методы
	void AddToHead(const Circle& figure);	// добавить в начало списка
	void AddToEnd(const Circle& figure);	// добавить в конец списка
	bool RemoveOne(const Circle& figure);	// удалить один из списка
	int RemoveAll(const Circle& figure);	// удалить все списка

	// перегрузки
	List& operator=(const List& otherList);		//Перегрузка оператора присваивания = для обьекта
	friend std::ostream& operator<<(std::ostream& os, List& list);	// вывод списка

	//TODO
	// присваивания
	// перемешающий

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
		ifstream fout(ar);
		fout >> l;
		fout.close();
	*/
};

