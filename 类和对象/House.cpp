#include "House.h"

House::House(string code,string furName):m_strName(code),m_furBed(furName)
{
	cout << "House(string code)"<< endl;
}
House::~House()
{
	cout << "~House()"<< endl;
}
void House::setCode(string code)
{
	m_strName= code;
}
string House::getCode()
{ 
	return m_strName;
}
void House::setFur(Furniture fur)
{
	m_furBed= fur;
}
Furniture& House::getFur()//和头文件一致 
{
	return m_furBed;
}
