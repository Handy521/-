#include "Coordinated.h"
class Circle
{
	public:
		Circle(int x, int y,int r);
		Circle(const Circle &c);//Éî¿½±´ 
		~Circle();
		void printinfo();
	private:
		Coordinated *m_pCenter;
		int m_iR;
};
