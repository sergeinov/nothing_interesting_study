#pragma once


template<typename T, size_t size> class MyArray
{
	T ar[ size ]{};			//как обеспечить инициализацию элементов базового типа по умолчанию нулем?

public:
	MyArray() = default;
	MyArray(const T* val, size_t size2) { };

};

template<typename T, size_t size> MyArray(const T(& temp)[ size ])->MyArray<T, size>;
