#include "vehiclehead.h"
using namespace std;
int main()
{
	motorcycle m(300,0.25,1.1,2); //限速300，车重0.25吨，车高1.1米，限载人数2
	m.show();
	m.vehicle::show();
   	return 0;
}
