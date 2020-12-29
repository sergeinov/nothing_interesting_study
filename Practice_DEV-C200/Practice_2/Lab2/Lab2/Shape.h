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
	
protected:
	eColor m_color;
};

