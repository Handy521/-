#include"Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(int x,int y,int r) 
{
	cout << "Circle(int x,int y,int z)"<<endl;
	m_pCenter = new Coordinate(x,y);//实例化圆心 ，在堆中开辟一个地址 
	m_iR = r;
}

Circle::~Circle()
{
	cout <<"~Circle()" << endl;
	delete m_pCenter;
	m_pCenter = NULL;
}
