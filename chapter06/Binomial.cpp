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

/*Binomial Binomial::operator-() //������������س�Ա���� 
{
	this->m_iA = -(this->m_iA);// thisָ��ָ���±ߵĳ�Ա�ͳ�Ա���� 
	this->m_iB = -(this->m_iB);
	return *this;//����һ������ 	
}*/
Binomial operator-(Binomial &bin)//���������������Ԫ���� 
{
	bin.m_iA = -bin.m_iA;
	bin.m_iB = -bin.m_iB;
	return bin;
}
/*Binomial Binomial::operator++()//ǰ��++�����ʽΪ++֮���ֵ 
{
	this->m_iA++;// thisָ��ָ���±ߵĳ�Ա�ͳ�Ա���� 
	this->m_iB++;
	return *this;//����һ������ 
}*/
Binomial operator++(Binomial &bin)//ǰ��++�����������Ԫ���� 
{
	bin.m_iA++;
	bin.m_iB++;
	return bin;
}
Binomial Binomial::operator++(int)//����++�����ʽΪ++֮ǰ��ֵ 
{
	Binomial old(*this);//ʵ����һ������ 
	this->m_iA++;// thisָ��ָ���±ߵĳ�Ա�ͳ�Ա���� 
	this->m_iB++;
	return old;//����һ������ 
}
/*Binomial Binomial::operator+(Binomial &bin1)
{
	Binomial temp(0,0);
	temp.m_iA = bin1.m_iA + m_iA;//��������ֵ�͵�ǰ����ʽ��ֵ��� 
	temp.m_iB = bin1.m_iB + m_iB;
	return temp;
}*/
Binomial operator+(Binomial &bin1,Binomial &bin2)
{
	Binomial temp(0,0);
	temp.m_iA = bin1.m_iA + bin2.m_iA;//��������ֵ�͵�ǰ����ʽ��ֵ��� 
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
Binomial &Binomial::operator=(Binomial &bin)//ϵͳ�ṩ��Ĭ�ϵ�=��������� 
{
	this->m_iA = bin.m_iA; 
	this->m_iB = bin.m_iB; 
	cout<<"operator="<<endl;
	return *this;
}
