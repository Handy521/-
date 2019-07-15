#include "Furniture.h"

Furniture::Furniture(string name):m_strFur(name)
{
	cout << "Furniture(string code)"<< endl;
}
Furniture::~Furniture()
{
	cout << "~Furniture()"<< endl;
}
void Furniture::setName(string name)
{
	m_strFur= name;
}
string Furniture::getName()
{
	return m_strFur;
}
