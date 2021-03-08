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
	bool operator<(const Point& point) const;
	bool operator!=(const Point& point) const;


	friend std::ostream& operator<<(std::ostream& os, const Point& place); // ����� ���������
	friend std::ostream& operator<<(std::ostream& os, const Point* place); // ����� ���������
	friend bool NegPoint(const Point& object);

	// ������
	int GetX();
	int GetY();

private:
	int m_x;
	int m_y;
};

