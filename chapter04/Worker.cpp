#include <iostream>
#include "Worker.h"
using namespace std;

Worker::Worker(string name,int age):Person(age)
{
	m_strName = name;
	cout <<"Worker"<<endl;
}
Worker::~Worker()
{
	cout<<"~Worker"<<endl;
}
string Worker::getName() const
{
	return m_strName;
}
void Worker::printInfo()
{
	cout<<"Worker::printinfo()"<<endl;
}
