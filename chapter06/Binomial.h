#include<iostream>
using namespace std;
#include<ostream>
class Binomial
{
	friend Binomial operator-(Binomial &bin);
	friend Binomial operator++(Binomial &bin); //一元运算符重载一个参数，二元就是两个参数当用友元函数重载时 
	friend Binomial operator+(Binomial &bin1,Binomial &bin2); //友元函数需要将两个加数传入二元运算符。成员函数本身即有一个this,只需传入一个加数。 
	friend ostream &operator<<(ostream &out,Binomial &bin);//<<重载 只能使用友元函数重载，成员函数重载时第一个参数需要为本类的对象 
	
public:
	Binomial(int a,int b);
	~Binomial();
	int geta();
	int getb();
	//Binomial operator-();//负号运算符重载 
	//Binomial operator++(); //前置++ 
	Binomial operator++(int);//后置++，当前表达式为++之前的值  
	//Binomial operator+(Binomial &bin1);加法重载 成员函数本身即有一个this,只需传入一个加数。
	int operator[](unsigned int i); 
	bool operator==(Binomial &bin);
	Binomial &operator=(Binomial &bin); 
private:
	int m_iA;
	int m_iB;
}; 
