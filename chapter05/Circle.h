#pragma once
#include"Shape.h"
class Circle: public Shape
{
public:
	Circle(double radius);
	~Circle();
	double calcArea();
protected:
	double m_dRadius;
	
};
