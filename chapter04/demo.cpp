#include<stdlib.h>
#include"Human.h"
#include"Farmer.h"
#include"Employee.h"
#include"Migrantworker.h"

/********************************************/
/*���μ̳У�һ������̳н���ڴ��˷� 

/********************************************/
int main()
{
	MigrantWorker *mk = new MigrantWorker("JJJ",20,"0001",1000);
	cout<<mk->getAge()<<endl; 
	cout<<mk->getCode()<<endl; 
	cout<<mk->getSalary()<<endl; 
	cout<<mk->getName()<<endl;
	
	
	delete mk;
	mk = NULL;
	system("pause");
	return 0;
}
