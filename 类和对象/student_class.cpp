#include <iostream>
#include <stdlib.h>
using namespace std;

class Student
{
	public :
		char name[20];
		int age;
		int money;
		void study()
		{
			cout << "study" << endl;
		}
	private:
		void play()
		{
			cout << "play" << endl;
		}
};

struct StudentEx
{
	int age;
public:
	int money;
	void playball()
	{
		cout << "playball" << endl;
	}
};

int main()
{
	StudentEx stu;
	stu.age = 20;
	//stu.study();
	cout << stu.age << endl;
	stu.money = 10;
	cout << stu.money << endl;
	stu.playball();
	
	Student *p = new Student[20];//实例化一群学生 
	p[0].age = 10;
	cout << p[0].age<< endl; 
	delete []p;
	p=NULL;
	system("pause");
	return 0;
}
