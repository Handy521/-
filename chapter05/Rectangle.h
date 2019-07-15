#pragma once
#include"Shape.h"
class Rectangle: public Shape
{
public:
	Rectangle(double width,double height);
	~Rectangle();
	double calcArea();
protected:
	double m_dWidth;
	double m_dHeight;
};
