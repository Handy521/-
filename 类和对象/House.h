#include <iostream>
#include <string>
#include <stdlib.h>
#include "Furniture.h"
using namespace std;

class House
{
public:
	House(string code,string furName);//�Ҿ߹��캯���в����������ȵ��üҾߵ�����Ҫ���� 
	~House();
	void setCode(string code);
	string getCode();
	void setFur(Furniture fur);
	Furniture &getFur();//ֱ���������֣� 
private:
	string m_strName;
	Furniture m_furBed;
};
