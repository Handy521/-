#include <iostream>
#include <stdlib.h>
using namespace std;

class Student
{
	public :	
		Student(string name, int age,int m=5);
		void setName(string name);
		string getName();
		void setAge(int Age);
		int getAge();
		void study();
		int getMax();
	private:
		string m_strName;
		int m_iAge; 
		const int m_iMax;
	
};
Student::Student(string name, int age,int m):m_strName(name),m_iAge(age),m_iMax(m)//初始化列表 
{
	cout <<"Student(string name, int age)"<< endl;
 } 
int Student::getMax()
{
	return m_iMax;
}
void Student::setName(string name)
{
	m_strName = name;
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

int main()
{
	Student *p = new Student("tim",20);
	/*stu.setName("jim");
	stu.setAge(10);
	//stu.study();
	cout << stu.getName() << endl;
	cout << stu.getAge() << endl;	*/	
	cout << p->getName() << endl;
	cout << p->getAge() << " "<< p->getMax()<< endl;
	delete p;
	system("pause");
	return 0;
}
