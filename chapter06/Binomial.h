#include<iostream>
using namespace std;
#include<ostream>
class Binomial
{
	friend Binomial operator-(Binomial &bin);
	friend Binomial operator++(Binomial &bin); //һԪ���������һ����������Ԫ������������������Ԫ��������ʱ 
	friend Binomial operator+(Binomial &bin1,Binomial &bin2); //��Ԫ������Ҫ���������������Ԫ���������Ա����������һ��this,ֻ�贫��һ�������� 
	friend ostream &operator<<(ostream &out,Binomial &bin);//<<���� ֻ��ʹ����Ԫ�������أ���Ա��������ʱ��һ��������ҪΪ����Ķ��� 
	
public:
	Binomial(int a,int b);
	~Binomial();
	int geta();
	int getb();
	//Binomial operator-();//������������� 
	//Binomial operator++(); //ǰ��++ 
	Binomial operator++(int);//����++����ǰ���ʽΪ++֮ǰ��ֵ  
	//Binomial operator+(Binomial &bin1);�ӷ����� ��Ա����������һ��this,ֻ�贫��һ��������
	int operator[](unsigned int i); 
	bool operator==(Binomial &bin);
	Binomial &operator=(Binomial &bin); 
private:
	int m_iA;
	int m_iB;
}; 
