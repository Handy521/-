#include <iostream>
#include <string>
#include <stdlib.h>
#include "Furniture.h"
using namespace std;

class House
{
public:
	House(string code,string furName);//家具构造函数有参数，这里先调用家具的类需要参数 
	~House();
	void setCode(string code);
	string getCode();
	void setFur(Furniture fur);
	Furniture &getFur();//直接引用名字， 
private:
	string m_strName;
	Furniture m_furBed;
};
