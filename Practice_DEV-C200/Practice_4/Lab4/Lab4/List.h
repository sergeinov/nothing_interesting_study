#pragma once

#include"Node.h"
//#include<iostream>
#include <fstream>

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
	void SortList();
	void ClearList();

	// перегрузки
	List& operator=(const List& otherList);		//Перегрузка оператора присваивания = для обьекта
	List& operator=(List&& otherList);			// перегрузка оператора move
	friend std::ostream& operator<<(std::ostream& os, const List& list);	// вывод списка
	friend std::ifstream& operator>>(std::ifstream& iff, List& list);	// чтение из файла


	/*
	TODO
	1.	сортировку по возрастанию площади объекта.
	*/
};

