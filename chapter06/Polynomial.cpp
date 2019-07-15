#include"Binomial.h"

/*********************************/
/*负号的运算符重载（分别通过成员函数和友元函数重载） 
	递增运算符的重载 （前置++和后置++） 
	加号运算符的重载 
	<<运算符的重载（只能友元函数重载） 
	[]重载 (只能成员函数重载)
	==运算符重载 
	=赋值运算符重载
/*******************************/ 
/*int main()
{
	//Binomial bin(5,3);//实例化对象 
	Binomial *bin = new Binomial(5,3);
	Binomial *bin2 = new Binomial(0,0);
	//Binomial bin2(0,0);
	*bin2 = -*bin;//运算符重载 bin->operator-() 友元函数相当于调用operator(bin)
	cout<<bin->geta()<<"  "<<bin->getb()<<endl;
	cout<<bin2->geta()<<"  "<<bin2->getb()<<endl;
	return 0;
 }*/
/*int main()
{
	Binomial bin(5,3);
	Binomial bin2(0,0);
	//bin2 = ++bin;
	bin2 = bin++;
	cout<<bin.geta()<<"  "<<bin.getb()<<endl;
	cout<<bin2.geta()<<"  "<<bin2.getb()<<endl;
	return 0;
  }  */ 
/*int main()
{
	Binomial bin(5,3);
	Binomial bin1(6,9);
	Binomial bin2(0,0);
	bin2 = bin1 + bin;//bin.operator(bin)，operator+(bin1,bin) 
	cout<<bin.geta()<<"  "<<bin.getb()<<endl;
	cout<<bin2.geta()<<"  "<<bin2.getb()<<endl;
	return 0;
}   
int main()
{
	Binomial bin(5,3);
	Binomial bin1(6,9);
	Binomial bin2(0,0);
	
	cout<<bin<<endl;//operator<<(cout,bin) 
	cout<<bin2<<endl;
	return 0;
 } 
int main()
{
	Binomial bin(5,3);
	cout<<bin[0]<<"  "<<bin[1]<<endl;
	return 0;
}
int main()
{
	Binomial bin(6,9);
	Binomial bin1(6,9);
	if (bin == bin1)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl; 
	return 0;
}*/
int main()
{
	Binomial bin(6,9);
	Binomial bin1(0,0);
	bin = bin1;
	cout<<bin<<endl;
	
	return 0;
}
