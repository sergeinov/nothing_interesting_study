//  Реализация шаблонов

#include"Template.h"


template<typename T> inline void Swap(const T& a, const T& b)	// шаблон обмена значений
{
	// Для работы с MyString требуется в классе реализовать конструктор пермещения и копирования
	T temp = a;
	a = b;
	b = temp;
}
