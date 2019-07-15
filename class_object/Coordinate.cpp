#include"Coordinate.h"
#include <iostream>
using namespace std;
Coordinate::Coordinate()
{
	m_iX = 0;
	m_iY = 0;
	cout << "Coordinate()" <<endl; 
} 
Coordinate::~Coordinate(){
}
void Coordinate::printinfo()
{
	cout <<"("<<m_iX<<","<<m_iY<<")"<<endl; 
}

