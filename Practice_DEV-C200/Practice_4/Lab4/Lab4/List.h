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

	void AddToHead(const Circle& figure);	// добавить в начало списка
	bool RemoveOne(const Circle& figure);	// удалить от списка
};

