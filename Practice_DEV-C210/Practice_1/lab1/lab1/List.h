#pragma once

#include"Node.h"

enum eParametrs {Color, Area };

class List
{
private:
	Node Head;
	Node Tail;
	size_t m_size;
public:
/*
*	 онструкторы
*/
	List();
	List(const List& otherList);	// конструктор копировани€
	List(List&& otherList);			// конструктор перемещени€ move
	~List();

/*
*	методы
*/
	void AddToHead(const Shape& figure);	// добавить в начало списка
	void AddToEnd(const Shape& figure);		// добавить в конец списка
	bool RemoveOne(const Shape& figure);	// удалить один из списка
	void ClearList();						// очистить список от объектов
	void Sort(eParametrs param);			// сортировку по возрастанию площади объекта		// TODO
	//int RemoveAll(const Shape& figure);		// удалить все списка	

/*
*	перегрузки
*/
	friend std::ostream& operator<<(std::ostream& os, const List& list);	// вывод списка		// TODO
	friend std::ifstream& operator>>(std::ifstream& iff, List& list);	// чтение из файла		// TODO

	List& operator=(const List& otherList);		//ѕерегрузка оператора присваивани€ = дл€ обьекта

	//List& operator=(List&& otherList);			// перегрузка оператора move



};


//! TODO  !Done
/*
Х	добавить новую фигуру в начало списка  /
Х	добавить новую фигуру в конец списка
Х	исключить фигуру, совпадающую с параметром
	- ¬ывод списка в файл и чтение из файла
	-сортировку по возрастанию площади объекта (по цвету, по удалению от начала координатЕ).
*/