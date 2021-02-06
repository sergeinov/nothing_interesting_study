#pragma once

#include"Node.h"
#include<iostream>
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
	List(const List& otherList);	// конструктор копировани€
	List(List&& otherList);			// конструктор перемещени€ move
	~List();

	// методы
	void AddToHead(const Circle& figure);	// добавить в начало списка
	void AddToEnd(const Circle& figure);	// добавить в конец списка
	bool RemoveOne(const Circle& figure);	// удалить один из списка
	int RemoveAll(const Circle& figure);	// удалить все списка

	// перегрузки
	List& operator=(const List& otherList);		//ѕерегрузка оператора присваивани€ = дл€ обьекта
	List& operator=(List&& otherList);
	friend std::ostream& operator<<(std::ostream& os, const List& list);	// вывод списка
	//friend std::ofstream& operator<<(std::ofstream& of, List& list);	// вывод в файл
	friend std::ifstream& operator>>(std::ifstream& iff, List& list);	// чтение из файла


	/*
	TODO
	1.	сортировку по возрастанию площади объекта.
	2.	¬ывод текущего состо€ни€ списка на консоль
		cout << l;
	3.	¬ывод текущего состо€ни€ списка в файл(в форматированном виде)
	#include <fstream>
		ofstream fout(file);
		fout << l;
		fout.close();
	4.	„тение из файла
		ifstream fout(file);
		fout >> l;
		fout.close();
	*/
};

