#pragma once
#include<utility>
//  Шаблоны

template<typename T> inline void Swap(T& a, T& b)	// шаблон обмена значений
{
	// Для работы с MyString требуется в классе реализовать конструктор пермещения и (?копирования - неэффективно)
	T temp = std::move(a);		// чтобы не использовать конструктор копирования (он затратный)
	a = std::move(b);		
	b = std::move(temp);
}