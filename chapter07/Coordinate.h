#pragma once
#include<ostream>
using namespace std;
class Coordinate
{
	friend ostream &operator<<(ostream &out,Coordinate &coor); 
public:
	Coordinate(int x = 0,int y = 0);//赋初值成为默认的构造函数 
private:
	int m_iX;
	int m_iY;
};

