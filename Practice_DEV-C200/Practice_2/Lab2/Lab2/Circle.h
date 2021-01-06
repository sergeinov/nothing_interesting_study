#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    // конструктор
    Circle();
    Circle(int x, int y, double diametr, eColor color) ;
    // деструктор
    virtual ~Circle();

    const double GetDiametr() const;
    const char* GetColor() const;
    
    void SetPosition(int x, int y);
    void SetDiametr(double diametr);
    //void SetColor(eColor color);

    void WhereAmI() const;
    virtual void WhereAmIVirtual() const;

    // перегрузка чистого вертуального метода
    // метод изменения размера фигуры
    //virtual void Inflate(int quantity);

private:
    double m_diametr;
    int m_x;
    int m_y;
};

