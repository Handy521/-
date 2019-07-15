#pragma once
#include<string>
#include<iostream>
using namespace std;
class Human
{
public:
	Human(string name);
	~Human();
	string getName();
protected:
	string m_strName; 
};
