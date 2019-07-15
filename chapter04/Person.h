#include<string>
#include<iostream> 
using namespace std;

class Person
{
public:
	Person(int age);
	~Person();
	int getAge() const;
protected:
	int m_iAge;
};
