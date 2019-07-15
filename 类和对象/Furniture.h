#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Furniture   
{
public:
	Furniture(string name);
	~Furniture(); 
	void setName(string name);
	string getName(); 
private:
	string m_strFur;
};
