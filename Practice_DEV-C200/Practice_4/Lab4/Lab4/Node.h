#pragma once

#include"Circle.h"

class Node
{
private:
	Node* pPrev;		// сосед слева
	Node* pNext;		// сосед справа
	Circle m_Data;		// поле данных  (одного типа)

public:
	Node();			// для вспомогательных оберток стражей (Head, Tail)
	Node(Node* p, const Circle* data); // Node* p - добавляет в список data
	
	~Node();

	friend class List;	// для доступа к данным списка

	// перегрузки
	//friend std::ostream& operator<<(std::ostream& os, Node& element); // вывод одного эл
	friend std::ostream& operator<<(std::ostream& os, const List& list);

			

};

