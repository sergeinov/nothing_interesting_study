#pragma once
class Shape
{
public:
	enum eColor { RED = 1, YELLOW, GREEN, BLACK };
	Shape();
	virtual ~Shape();

	void GetShape();
	void WhereAmI();
	virtual void WhereAmIVirtual();
	
protected:

};

