#include "Binomial.h"
Binomial::Binomial(int a,int b)
{
	m_iA = a;
	m_iB = b;
}
Binomial::~Binomial()
{
}
Binomial::geta()
{
	return m_iA;
}
Binomial::getb()
{
	return m_iB;
}

/*Binomial Binomial::operator-() //负号运算符重载成员函数 
{
	this->m_iA = -(this->m_iA);// this指针指向下边的成员和成员函数 
	this->m_iB = -(this->m_iB);
	return *this;//返回一个对象 	
}*/
Binomial operator-(Binomial &bin)//负号运算符重载友元函数 
{
	bin.m_iA = -bin.m_iA;
	bin.m_iB = -bin.m_iB;
	return bin;
}
/*Binomial Binomial::operator++()//前置++；表达式为++之后的值 
{
	this->m_iA++;// this指针指向下边的成员和成员函数 
	this->m_iB++;
	return *this;//返回一个对象 
}*/
Binomial operator++(Binomial &bin)//前置++运算符重载友元函数 
{
	bin.m_iA++;
	bin.m_iB++;
	return bin;
}
Binomial Binomial::operator++(int)//后置++；表达式为++之前的值 
{
	Binomial old(*this);//实例化一个对象 
	this->m_iA++;// this指针指向下边的成员和成员函数 
	this->m_iB++;
	return old;//返回一个对象 
}
/*Binomial Binomial::operator+(Binomial &bin1)
{
	Binomial temp(0,0);
	temp.m_iA = bin1.m_iA + m_iA;//将传入后的值和当前二项式的值相加 
	temp.m_iB = bin1.m_iB + m_iB;
	return temp;
}*/
Binomial operator+(Binomial &bin1,Binomial &bin2)
{
	Binomial temp(0,0);
	temp.m_iA = bin1.m_iA + bin2.m_iA;//将传入后的值和当前二项式的值相加 
	temp.m_iB = bin1.m_iB + bin2.m_iB;
	return temp;
}
ostream &operator<<(ostream &out,Binomial &bin)
{
	out << bin.m_iA<<"x + ("<<bin.m_iB<<")"<<endl;
	return out;
}
int Binomial::operator[](unsigned int i)
{
	if (i == 0)
		return m_iA;
	else if (i == 1)
		return m_iB;
	else
		throw 1;
}
bool Binomial::operator==(Binomial &bin)
{
	if(m_iA == bin.m_iA && m_iB == bin.m_iB)
		return true;
	else 
		return false;
}
Binomial &Binomial::operator=(Binomial &bin)//系统提供了默认的=运算符重载 
{
	this->m_iA = bin.m_iA; 
	this->m_iB = bin.m_iB; 
	cout<<"operator="<<endl;
	return *this;
}
