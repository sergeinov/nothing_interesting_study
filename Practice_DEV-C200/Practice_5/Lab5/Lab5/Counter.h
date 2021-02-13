#pragma once
class Counter
{
private:
	Counter* pNext;					// указатель на следующий Counter
	char* m_pStr;					// указатель на динамически созданную строку
	unsigned int m_nOwners;			// счетчик пользователей строки

	static Counter* pHead;				// фиктивный страж
	static unsigned int m_curCounters;	// счетчик указателей

	friend class MyString;				// доступ к полям для класса MyString

	/*
	*	конструкторы
	*/
	Counter(const char* p);
	~Counter();

	/*
	*	методы
	*/

	void AddOwner();
	void RemoveOwner();
	static Counter* find(const char* str);

	/*
	*	перегрузки
	*/
	
};



// !TODO
/*
* создать статические методы
•	распечатать все строки
•	во всех объектах MyString изменить регистр
•	вывести строки по алфавиту

*/