#include <cstring>
class student
{
	public:
		void show_sum(); // ���ѧ����ѧ������ 
		void show_aver();//���ѧ����ƽ���� 
		void show_classaver(student *);//����༶��ƽ���� 
		void print_stu();//���ѧ����������Ϣ 
		void get_stu_num();//����ѧ����ѧ�� 
		void set_stu_inf();//����ѧ���������ͳɼ� 
		void show_name();//����ѧ�������� 
		void show_escore();//���ѧ�������Լ�Ӣ��ɼ� 
		void show_mscore();//���ѧ�������Լ���ɢ�ɼ�
		void show_cscore();////���ѧ�������Լ�C++�ɼ� 
		int maxscoree(student *);//�ҳ�Ӣ����߷� 
		int maxscorem(student *);//�ҳ���ɢ��߷� 
		int maxscorec(student *);//�ҳ�C++��߷� 
		int maxscoresum(student *);//�ҳ��ܷ���߷�		 
		int search(student *,int );//�ҵ�ѧ�Ŷ�Ӧ��ѧ��λ�� 
		int index;//��¼ѧ����λ�� 
	private:
		int num;//ѧ�� 
		char name[20];//���� 
		double escore;//Ӣ��ɼ� 
		double mscore;//��ɢ�ɼ� 
		double cscore;//C++�ɼ� 
		double sum;//�ܷ� 
		double aver;//���� 
}; 

