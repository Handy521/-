#include<string>
using namespace std;
class Student
{
public:
	Student(string name);
	void printinfo();
	void printinfo() const;
private:
	string m_strName; 
};
