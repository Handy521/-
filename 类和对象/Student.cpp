#include "Student.h"
void Student::setName(string name)
{
	m_strName = name;
}
Student::Student()
{
	cout <<"Student"<<endl;
}
Student::Student(const Student &stu)
{
	cout<<"Student(const Student& stu)"<<endl;
}
Student::~Student()
{
	cout <<"~Student()"<< endl;
}
string Student::getName()
{
	return m_strName;
}
void Student::setAge(int Age)
{
	m_iAge= Age;
}
int Student::getAge()
{
	return m_iAge;
}
void Student::study()
{
	cout << "study" << endl;
}
