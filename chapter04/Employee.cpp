#include"Employee.h"

Employee::Employee(string name,string code):Human(name)
{
	m_strCode = code;
	cout<<"Employee£¨£©"<<endl; 
}
Employee::~Employee()
{
	cout<<"~Employee()"<<endl;
}
string Employee::getCode()
{
	return m_strCode;
}
