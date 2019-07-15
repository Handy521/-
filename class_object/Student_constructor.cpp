#include <iostream>
#include <stdlib.h>
using namespace std;

class Student
{
	public :	
		Student()//构造函数 
		{
			cout << "Student" << endl;
		 } 
		Student(string name, int age=10);
		void setName(string name);
		string getName();
		void setAge(int Age);
		int getAge();
		void study();
		
	private:
		string m_strName;
		int m_iAge; 
		void play()//外部不能访问 
		{
			cout << "play" << endl; 
		}
};
Student::Student(string name, int age)
{
	m_iAge = age;
	m_strName = name;
	cout <<"Student(string name, int age)"<< endl;
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
	Student stu;
	Student *q=new Student("jimams");
	Student *p = new Student("tim",20);
	/*stu.setName("jim");
	stu.setAge(10);
	//stu.study();
	cout << stu.getName() << endl;
	cout << stu.getAge() << endl;	*/	
	cout << p->getName() << endl;
	cout << p->getAge() << endl;
	delete p;
	delete q; 
	system("pause");
	return 0;
}
