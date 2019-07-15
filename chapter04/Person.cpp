#include"Person.h"

Person::Person(int age)
{
	m_iAge = age;
	cout<<"Person()"<<endl;	 
}
Person::~Person()
{
	cout<<"~Person()"<<endl;
}
int Person::getAge() const
{
	return m_iAge;
}


