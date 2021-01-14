#pragma once

class Point
{
private:
	int m_x;
	int m_y;
public:
	// �����������
	explicit Point() { m_x = 0; m_y = 0; };
	Point(int x, int y);
	//����������
	// ����������� �����������
	Point(const Point& other);

	// ���������� ��������� +=
	Point& operator+=(const Point& RightObject);
	Point& operator+=(const int value);

	// ���������� ��������� -=  � ������� ������������� �������. � ���������� �������  main.cpp
	friend Point& operator-=(Point& leftObject, const int value);
	friend Point& operator-=(Point& leftObject,Point& RightObject);

	//���������� ��������� +
	Point operator+(const Point& RightObject);
	Point operator+(const int value);

	// ���������� ��������� + � ������� ���������� �������
	friend Point& operator+(const int value, Point& RightObject);

	// ���������� ��������� - � ������� ���������� �������
	friend Point operator-(Point& leftObject, const int value);
	friend Point operator-(Point& leftObject, Point& RightObject);

	// ����������� �������� ��������� + (+pt1;)
	Point& operator-();

	// ����������� �������� ��������� - (-pt1;)
	Point& operator+();

};

