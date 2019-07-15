#include"Tank.h"
#include<iostream>

using namespace std;

int Tank::g_iCount=0;
Tank::Tank(string code)
{
	m_strCode = code;
	g_iCount++;	
}
Tank::~Tank()
{
	g_iCount--;
}
void Tank::attack()
{
	if(g_iCount>3)
	cout <<"fire!!!" <<endl;
	else
	cout <<"go!!!"<<endl;
}
int Tank::getCount()
{
	return g_iCount;
}
