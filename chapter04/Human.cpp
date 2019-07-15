#include"Human.h"

Human::Human(string name)
{
	m_strName = name;
	cout<< "Human()"<<endl;
}
Human::~Human()
{
	cout<<"~Human()"<<endl;
}
string Human::getName()
{
	return m_strName;
 } 
