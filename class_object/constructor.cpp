#include<iostream>
#include <stdlib.h>
#include <string>
using namespace std;

clsaa Car
{
	public:
		void init();
	private:
		int m_iSpeed;
		int m_iWheelCount;
 } ;
 void Car::init()
 {
 	m_iSpeed= 0;
 	m_iWheelCount = 0; 
 }

class Student
{
public:
	Student(string name,int age)//有参构造函数 
	{
		m_strName= name;
		m_iAge= age; 
	}
	Student(){}//定义两个构造函数 ，系统产生的和这个一样 
	
private:
	string m_strName;
	int m_iAge;
};
int main(void)
{
	Student stu("jim",20);//实例化对象
	Student *p= NULL;
	//p = new Student("Merry",22);
	p= new Student()//
	system("pause");
	return 0; 
 } 
