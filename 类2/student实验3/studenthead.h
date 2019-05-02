#include <cstring>
class student
{
	public:
		void show_sum(); // 输出学生的学号姓名 
		void show_aver();//输出学生的平均分 
		void show_classaver(student *);//输出班级的平均分 
		void print_stu();//输出学生的所有信息 
		void get_stu_num();//输入学生的学号 
		void set_stu_inf();//输入学生的姓名和成绩 
		void show_name();//输入学生的姓名 
		void show_escore();//输出学号姓名以及英语成绩 
		void show_mscore();//输出学号姓名以及离散成绩
		void show_cscore();////输出学号姓名以及C++成绩 
		int maxscoree(student *);//找出英语最高分 
		int maxscorem(student *);//找出离散最高分 
		int maxscorec(student *);//找出C++最高分 
		int maxscoresum(student *);//找出总分最高分		 
		int search(student *,int );//找到学号对应的学生位置 
		int index;//记录学生的位置 
	private:
		int num;//学号 
		char name[20];//姓名 
		double escore;//英语成绩 
		double mscore;//离散成绩 
		double cscore;//C++成绩 
		double sum;//总分 
		double aver;//均分 
}; 

