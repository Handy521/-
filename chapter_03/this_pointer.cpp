#include<string>
#include <iostream>
using namespace std;

class Student
{
public:
	Student(string name);
	Student* getIt1();
	Student& getIt2();
	void getIt3(Student **it);
	void getIt4(Student &it);
	void printname();
	void setName(string name);
private:
	string m_strName;
 } ; 
 
Student::Student(string name)
{
	this->m_strName = name;
 }
void Student::setName(string name)
{
	m_strName = name;
}
void Student::printname()
{
	cout <<m_strName<<endl;
 } 
Student *Student::getIt1()
{
	return this;
}
Student &Student::getIt2()
{
	return *this;
}
void Student::getIt3(Student **it)
{
	*it = this;
	cout <<this<<endl;
 } 
void Student::getIt4(Student &it)
{
	it = *this;//将当前this指针值拷贝给传入参数it的值, 
}
int main()
{
	Student stu("zhangsan");
	/*Student *p = stu.getIt1();
	p->printname();
	Student stu1("LIsi");//实例化第二个对象 
	p = stu1.getIt1();
	p->printname();
	
	Student &stu1 = stu.getIt2();//给stu取别名成stu1 
	stu1.setName("hebe");
	stu.printname();
	
	Student *p = NULL;
	stu.getIt3(&p);//二重指针 获得当前this指针 
	cout<<p<<endl;
	p->setName("yawn");
	stu.printname(); */
	
	Student stu1("zibe");
	stu.getIt4(stu1);//将当前this指针值stu的值，传给stu1, 
	stu1.printname();//打印张三 
	
	system("pause");
	return 0;
}
