#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<initializer_list>

template<typename T>class MyVector
{
	std::vector<T> v;		// вектор значений
	T beginArr{};			// диапазон значений от
	T endArr{};				// дипазон значений до

public:
	MyVector() = default;
	MyVector(const T& begin, const T& end, std::initializer_list<T> values);

	// методы
	void Add(std::initializer_list<T> values);		// добавляет значения в вектор
	void Delete(std::initializer_list<T> values);	// удаляет значения из вектора
	void Sort(bool val);					// сортирует вектор. true - по возрастанию  false - по убыванию
	void clearValues();								// удаляет все значения в векторе
};



//**********************************************************************//
// реализация

template<typename T>
inline MyVector<T>::MyVector(const T& begin, const T& end, std::initializer_list<T> values) : beginArr(begin), endArr(end)
{
	v.reserve(values.size());			// создает память размер со список инициализаторов
	for ( auto& i : values )			// идем по вектору
	{
		// если входит в диапазон  begin->end
		if ( (i >= beginArr) && (i <= endArr)  )
		{
			// если еще нет в в векторе
			if ( std::find(v.begin(), v.end(), i) == v.end() )
			{
				v.push_back(i);
			}
		}
	}
}

template<typename T>
inline void MyVector<T>::Add(std::initializer_list<T> values) 
{
	v.reserve(values.size() + v.size());					// создаем память больше на 1 элемент
	for ( const auto& i : values )
	{
		// если входит в диапазон чисел begin->end
		if ( ( i >= beginArr ) && ( i <= endArr ) )
		{
			// если нет еще в векторе, то добавляем
			if ( std::find(v.begin(), v.end(), i) == v.end() )
			{				 	
				v.push_back(i);					// добавляем элемент 
			}
		}
	}
	v.shrink_to_fit();
}

template<typename T>
inline void MyVector<T>::Delete(std::initializer_list<T> values)
{
	for ( auto& i : values )
	{
		auto temp = std::find(v.begin(), v.end(), i);		// ищем есть ли значение в векторе
		if ( temp != v.end() )								// проверяем условие, что значение есть
		{
			v.erase(temp);									//  удаляем по адресу итератора найденное значение
		}
	}
}

template<typename T>
inline void MyVector<T>::Sort(bool val)
{
	//if ( val )
	//{
	//	std::sort(v.begin(), v.end(), std::less<T>());			// сортировка по возрастанию
	//}
	//else
	//{
	//	std::sort(v.begin(), v.end(), std::greater<T>());		// сортировка по убыванию
	//	/*std::sort(v.begin(), v.end(),
	//		[](int a, int b)
	//		{
	//			return a > b;
	//		});*/	
	//}
	std::sort(v.begin(), v.end(), [val](int a, int b)
			{
				if ( val )
				{
					return a > b;
				}
				return a < b;
			});
}

template<typename T>
inline void MyVector<T>::clearValues()
{
	v.clear();							// метод cler очищает элементы вектора
}


