#include"Farmer.h"
Farmer::Farmer(string name,int age):Human(name)
{
	m_iAge = age;
	cout <<"Farmer()"<<endl;
}
Farmer::~Farmer()
{
	cout<<"~Farmer()"<<endl;
}
int Farmer::getAge()
{
	return m_iAge;
}
