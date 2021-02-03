#pragma once
#include<iostream>
class Point
{
public:

	Point();
	Point(int x, int y);
	//~Point();

	// ���������� ���������==
	bool operator==(const Point& point) const;
	friend std::ostream& operator<<(std::ostream& os, Point& place); // ����� ���������

private:
	int m_x;
	int m_y;
};

