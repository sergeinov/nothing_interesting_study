#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    Circle();
    Circle(double diametr, eColor color);
    ~Circle();

    const double GetDiametr() const;
    const double GetColor() const;
    void SetColor(eColor color);
private:
    double m_diametr;
    eColor m_color;
};

