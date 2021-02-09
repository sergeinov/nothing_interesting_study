#pragma once
class Counter
{
private:
	Counter* pNext;					// указатель на следующий Counter
	char* m_pStr;					// указатель на динамически созданную строку
	unsigned int m_nOwners;			// счетчик владельцев строки

	static Counter* pHead;				// фиктивный страж
	static unsigned int m_curCounters;	// счетчик указателей

	friend class MyString;				// доступ к пол€м дл€ класса MyString

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
Х	распечатать все строки
Х	во всех объектах MyString изменить регистр
Х	вывести строки по алфавиту

*/