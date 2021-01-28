#pragma once
class Point
{
public:

	Point();
	Point(int x, int y);
	//~Point();

	// перегрузка оператора==
	bool operator==(const Point& point) const;

private:
	int m_x;
	int m_y;
};

