#include"Worker.h"
#include"Electrician.h"

#include<stdlib.h>

/********************************************/
/*���ؼ̳�
	Person�� 
		���ݳ�Ա��m_iAge;
		��Ա���������캯��������������getAge 
/*ͬ������
	Worker��
		���ݳ�Ա��m_strName
		��Ա���������캯��������������getName,printinfo 
	
	Electricain��   
		���ݳ�Ա��m_iSalary
		��Ա���������캯��������������printinfo 
/*******************************************/
int main(void)
{
	//Electrician elec("JIm",200);
	Electrician *elec = new Electrician("JIn",20,2000);
	//elec->Worker::printInfo();
	elec->getName();//protected�̳�ʱ���ܷ��� 
	elec->printInfo();
	delete elec;
	elec = NULL;
	system("pause");
	return 0;
 } 
