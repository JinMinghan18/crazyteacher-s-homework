#ifndef POOLHEAD00_H_
#define POOLHEAD00_H_
#include <string> 
class Pool
{
	public:
		void set_cir();
		void show_cir();
		double sum;	//�ܼ� 
	private:
		double cost1 = 10.0;	//��ש���� 
		double cost2 = 10.0;	//Χ������ 
		double r;	//Բ�뾶 
		double c;	//�ߵ��� 
		double wlc;	//Χ���� 
		double dzs;	//�ߵ���� 
}; 
#endif
