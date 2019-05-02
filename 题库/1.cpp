#include<iostream> 
using namespace std; 
int main()
{
	int y, m, d;
	while (cin>>y>>m>>d)
	{
		
		if (y > 1999)
		{
			int a = 0;
			a += (y - 1999) * 365+(y-1997)/4;
			switch (m)
			{
				case 12:a += 30;
				case 11:a += 31;
				case 10:a += 30;
				case 9:a += 31;
				case 8: a += 31;
				case 7:a += 30;
				case 6:a += 31;
				case 5:a += 30;
				case 4:a += 31;
				case 3:a += 28 + y % 4;
				case 2:a += 31;
				case 1:break;
			}
			a += d - 1;
			if (a % 7)cout << a / 7 + 1 << endl;
			else cout << a / 7<<endl;
		}
		if (y == 1999)
		{
			int a = 0;
			switch (m)
			{
			case 12:a += 30;
			case 11:a += 31;
			case 10:a += 30;
			case 9:a += 31;
			case 8: a += 31;
			case 7:a += 30;
			case 6:a += 31;
			case 5:a += 30;
			case 4:a += 31;
			case 3:a += 28;
			case 2:a += 31;
			case 1:break;
			}
			a += d - 1;
			if (a % 7)cout << a / 7 + 1 << endl;
			else cout << a / 7<<endl;
		}
		if (y < 1999)
		{
			int a = 0;
			a += ( 1999-y) * 365;
			if (y % 4 == 0)
				if (m < 3)
					a += (2000 - y) / 4;
				else a += (2000 - y) / 4 - 1;
			else a += (2000 - y) / 4;
			switch (m)
			{
			case 12:a -= 30;
			case 11:a -= 31;
			case 10:a -= 30;
			case 9:a -= 31;
			case 8: a -= 31;
			case 7:a -= 30;
			case 6:a -= 31;
			case 5:a -= 30;
			case 4:a -= 31;
			case 3:a -= 28;
			case 2:a -= 31;
			case 1:break;
			}
			a -= d - 1;
			if (a % 7)cout << a / 7 + 1 << endl;
			else cout << a / 7<<endl;
		}
	}
}

