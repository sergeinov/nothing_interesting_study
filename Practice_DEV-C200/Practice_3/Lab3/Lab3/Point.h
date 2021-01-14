#pragma once

class Point
{
private:
	int m_x;
	int m_y;
public:
	// конструктор
	explicit Point() { m_x = 0; m_y = 0; };
	Point(int x, int y);
	//деструктор
	// конструктор копирования
	Point(const Point& other);

	// перегрузка оператора +=
	Point& operator+=(const Point& RightObject);
	Point& operator+=(const int value);

	// перегрузка оператора -=  с помощью дружественной функции. В глобальной области  main.cpp
	friend Point& operator-=(Point& leftObject, const int value);
	friend Point& operator-=(Point& leftObject,Point& RightObject);

	//Перегрузка оператора +
	Point operator+(const Point& RightObject);
	Point operator+(const int value);

	// перегрузка оператора + с помощью глобальной функции
	friend Point& operator+(const int value, Point& RightObject);

	// перегрузка оператора - с помощью глобальной функции
	friend Point operator-(Point& leftObject, const int value);
	friend Point operator-(Point& leftObject, Point& RightObject);

	// Перегрузика унарного оператора + (+pt1;)
	Point& operator-();

	// Перегрузика унарного оператора - (-pt1;)
	Point& operator+();

};

