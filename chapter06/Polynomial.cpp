#include"Binomial.h"

/*********************************/
/*���ŵ���������أ��ֱ�ͨ����Ա��������Ԫ�������أ� 
	��������������� ��ǰ��++�ͺ���++�� 
	�Ӻ������������ 
	<<����������أ�ֻ����Ԫ�������أ� 
	[]���� (ֻ�ܳ�Ա��������)
	==��������� 
	=��ֵ���������
/*******************************/ 
/*int main()
{
	//Binomial bin(5,3);//ʵ�������� 
	Binomial *bin = new Binomial(5,3);
	Binomial *bin2 = new Binomial(0,0);
	//Binomial bin2(0,0);
	*bin2 = -*bin;//��������� bin->operator-() ��Ԫ�����൱�ڵ���operator(bin)
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
	bin2 = bin1 + bin;//bin.operator(bin)��operator+(bin1,bin) 
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
