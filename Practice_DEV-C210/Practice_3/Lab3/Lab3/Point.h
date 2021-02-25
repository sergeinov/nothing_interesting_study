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
	friend std::ostream& operator<<(std::ostream& os, const Point& place); // вывод координат
	friend std::ostream& operator<<(std::ostream& os, const Point* place); // вывод координат

private:
	int m_x;
	int m_y;
};

