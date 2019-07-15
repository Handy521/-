#include "Coordinate.h"
class Circle
{
	public:
		Circle(int x,int y,int z);
		~Circle();
	private:
		Coordinate *m_pCenter;
		int m_iR;
		
};
