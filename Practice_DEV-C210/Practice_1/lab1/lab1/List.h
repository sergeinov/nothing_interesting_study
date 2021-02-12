#pragma once

#include"Node.h"

class List
{
private:
	Node Head;
	Node Tail;
	size_t m_size;
public:
/*
*	Конструкторы
*/
	List();
	List(const List& otherList);	// конструктор копирования
	List(List&& otherList);			// конструктор перемещения move
	~List();

/*
*	методы
*/
	void AddToHead(const Shape& figure);	// добавить в начало списка
	void AddToEnd(const Shape& figure);	// добавить в конец списка
	bool RemoveOne(const Shape& figure);	// удалить один из списка

	//int RemoveAll(const Shape& figure);	// удалить все списка
	//void SortList();
	//void ClearList();

/*
*	перегрузки
*/
	friend std::ostream& operator<<(std::ostream& os, const List& list);	// вывод списка		// TODO

	//List& operator=(const List& otherList);		//Перегрузка оператора присваивания = для обьекта
	//List& operator=(List&& otherList);			// перегрузка оператора move
	//friend std::ifstream& operator>>(std::ifstream& iff, List& list);	// чтение из файла


};


//! TODO
/*
•	добавить новую фигуру в начало списка  // 
•	добавить новую фигуру в конец списка
•	исключить фигуру, совпадающую с параметром
	Вывод списка в файл и чтение из файла
*/