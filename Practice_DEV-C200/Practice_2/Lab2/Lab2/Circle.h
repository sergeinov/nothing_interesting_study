#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    Circle();
    Circle(int x, int y, double diametr, eColor color);
    ~Circle();

    const double GetDiametr() const;
    const char* GetColor() const;
    
    void SetPosition(int x, int y);
    void SetDiametr(double diametr);
    void SetColor(eColor color);
private:
    double m_diametr;
    int m_x;
    int m_y;
    eColor m_color;
};

