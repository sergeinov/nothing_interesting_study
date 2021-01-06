#pragma once
class Shape
{
public:
	enum eColor { RED = 1, YELLOW, GREEN, BLACK };

	Shape();
	Shape(eColor color);
	virtual ~Shape();

	void GetShape();
	void WhereAmI() const;
	virtual void WhereAmIVirtual() const;

	// чисто виртуальный метод изменения размера фигуры
	//virtual void Inflate(int) = 0;
	
protected:
	eColor m_color;
};

