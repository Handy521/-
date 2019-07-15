#include <iostream>
using namespace std;
class Coordinated
{
public:
	Coordinated(int x,int y)
	{
		m_iX = x;
		m_iY = y;
		cout << "Coordinated()"<< endl; 
	};
	~Coordinated()
	{
		cout << "~Coordinated"<<endl;
	} 
	int m_iX;
	int m_iY;
};
/*Coordinate::Coordinate(int x,int y)
{
	m_iX = x;
	m_iY = y;
	cout << "Coordinate()"<< endl; 
}
Coordinate::~Coordinate()
{
	cout << "~Coordinate"<<endl;
}*/

