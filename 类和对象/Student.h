#include <iostream>
#include <string>
using namespace std;

class Student
{
	public:
		Student();
		Student(const Student &stu); //�������캯�� 
		~Student();//��������ʱ�����������Զ����� 
		void setName(string name);
		string getName();
		void setAge(int Age);
		int getAge();
		void study();
	private:
		string m_strName;
		int m_iAge;
};

