#include"Coordinate.h"
Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
}
ostream &operator<<(ostream &out,Coordinate &coor)
{
	out <<"("<<coor.m_iX<<","<<coor.m_iY<<"£©"<<endl;
	return out; 
}
