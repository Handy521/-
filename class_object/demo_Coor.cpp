#include "Coordinate.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	/*Coordinate coor[3];
	coor[0].m_iX = 20;
	coor[0].m_iY = 30;
	coor[0].printinfo();
	coor[1].printinfo();
	coor[2].printinfo();*/
	
	Coordinate *p = new Coordinate[3];
	p[0].m_iX = 30;
	p[0].m_iY = 40;
	for(int i = 0;i<3;i++)
	p[i].printinfo();
	delete []p;
	p = NULL;
	system("pause");
	return 0;
}
