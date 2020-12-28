#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    // конструктор
    Circle();
    Circle(int x, int y, double diametr, eColor color);
    // деструктор
    virtual ~Circle();

    const double GetDiametr() const;
    const char* GetColor() const;
    
    void SetPosition(int x, int y);
    void SetDiametr(double diametr);
    void SetColor(eColor color);

    void WhereAmI();
    virtual void WhereAmIVirtual();

private:
    double m_diametr;
    int m_x;
    int m_y;
    eColor m_color;
};

