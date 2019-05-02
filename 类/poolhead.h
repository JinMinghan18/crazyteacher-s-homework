#ifndef POOLHEAD00_H_
#define POOLHEAD00_H_
#include <string> 
class Pool
{
	public:
		void set_cir();
		void show_cir();
		double sum;	//总价 
	private:
		double cost1 = 10.0;	//地砖单价 
		double cost2 = 10.0;	//围栏单价 
		double r;	//圆半径 
		double c;	//走道宽 
		double wlc;	//围栏长 
		double dzs;	//走道面积 
}; 
#endif
