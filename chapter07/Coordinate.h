#pragma once
#include<ostream>
using namespace std;
class Coordinate
{
	friend ostream &operator<<(ostream &out,Coordinate &coor); 
public:
	Coordinate(int x = 0,int y = 0);//����ֵ��ΪĬ�ϵĹ��캯�� 
private:
	int m_iX;
	int m_iY;
};

