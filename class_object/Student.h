#include <iostream>
#include <string>
using namespace std;

class Student
{
	public:
		Student();
		Student(const Student &stu); //拷贝构造函数 
		~Student();//对象销毁时，析构函数自动调用 
		void setName(string name);
		string getName();
		void setAge(int Age);
		int getAge();
		void study();
	private:
		string m_strName;
		int m_iAge;
};

