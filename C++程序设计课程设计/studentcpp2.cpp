#include <iostream>
#include <fstream>
#include <iomanip>
#include "student.h"
int main()
{
	student a[10000];
	int i;
   	while(1)
	{
		cout<<"\t\t★★★★★★★★★★★★★★★★★★★★★★★★"<<endl;
		cout<<"\t\t\t☆☆欢迎进入学生考勤系统☆☆"<<endl;
		cout<<"\t\t★★★★★★★★★★★★★★★★★★★★★★★★"<<endl;
		cout<<"\t\t★                                            ★"<<endl;
		cout<<"\t\t★                                            ★"<<endl;
		cout<<"\t\t★         ※  1、录入学生的缺课记录；        ★"<<endl;
		cout<<"\t\t★                                            ★"<<endl;
		cout<<"\t\t★         ※  2、修改某个学生的缺课记录；    ★"<<endl;
		cout<<"\t\t★                                            ★"<<endl;
		cout<<"\t\t★         ※  3、查询某个学生的缺课情况      ★"<<endl;
		cout<<"\t\t★                                            ★"<<endl;
		cout<<"\t\t★         ※  4、旷课学生姓名及旷课次数      ★"<<endl;
		cout<<"\t\t★                                            ★"<<endl;
		cout<<"\t\t★         ※  5、有学生旷课人次              ★"<<endl;
		cout<<"\t\t★                                            ★"<<endl;
		cout<<"\t\t★         ※  6. 退出                        ★"<<endl;
		cout<<"\t\t★                                            ★"<<endl;
		cout<<"\t\t★★★★★★★★★★★★★★★★★★★★★★★★" <<endl <<endl <<"\t\t";
		cout<<"\t ※ ******请选择您所需要的信息******※"<<endl;
		cin>>i;
		switch(i)
		{
			case 1:get_info();break;
			case 2:modify();break;
		}
	}

} 
