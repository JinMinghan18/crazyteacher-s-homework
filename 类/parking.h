#ifndef PARKING_H_
#define PARKING_H_
#include <string>
class clock
{
	public:
		void show_time();
		void set_time();
		double diff(const clock t);
	private:
		long long normalize();
		int year;
		int month;
		int day; 
		int sec;
		int hour;
		int minute;
};

#endif
