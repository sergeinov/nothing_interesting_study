#pragma once
class Point
{
public:
	enum eColor { RED = 1, YELLOW, GREEN, BLACK };

	Point();
	Point(int x, int y, eColor color);
	virtual ~Point();

private:
	int m_x;
	int m_y;
	eColor m_color;
	
};

