#pragma once
#include<iostream>
class Point
{
public:

	Point();
	Point(int x, int y);
	//~Point();

	// перегрузка оператора==
	bool operator==(const Point& point) const;
	bool operator<(const Point& point) const;
	bool operator!=(const Point& point) const;

	

	friend std::ostream& operator<<(std::ostream& os, const Point& place); // вывод координат
	friend std::ostream& operator<<(std::ostream& os, const Point* place); // вывод координат
	friend bool NegPoint(const Point& object);

	Point operator+(const int val) const;

	// методы
	int GetX() const;
	int GetY() const ;

private:
	int m_x;
	int m_y;
};

