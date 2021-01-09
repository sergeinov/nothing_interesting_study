#pragma once

class Point
{
private:
	int m_x;
	int m_y;
public:
	// �����������
	Point() { m_x = 0; m_y = 0; };
	Point(int x, int y);
	//����������
	// ����������� �����������
	Point(const Point& other);

	// ���������� ��������� +=
	Point& operator+=(const Point& RightObject);
	Point& operator+=(const int number);

	// ���������� ��������� -=  � ������� ������������� �������. � ���������� �������  main.cpp
	friend Point& operator-=(Point& leftObject, const int number);
	friend Point& operator-=(Point& leftObject,Point& RightObject);

	//���������� ��������� +
	Point& operator+(const Point& RightObject);
	Point& operator+(const int number);

};

