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
		cout<<"\t\t�������������������������"<<endl;
		cout<<"\t\t\t��ӭ����ѧ������ϵͳ���"<<endl;
		cout<<"\t\t�������������������������"<<endl;
		cout<<"\t\t��                                            ��"<<endl;
		cout<<"\t\t��                                            ��"<<endl;
		cout<<"\t\t��         ��  1��¼��ѧ����ȱ�μ�¼��        ��"<<endl;
		cout<<"\t\t��                                            ��"<<endl;
		cout<<"\t\t��         ��  2���޸�ĳ��ѧ����ȱ�μ�¼��    ��"<<endl;
		cout<<"\t\t��                                            ��"<<endl;
		cout<<"\t\t��         ��  3����ѯĳ��ѧ����ȱ�����      ��"<<endl;
		cout<<"\t\t��                                            ��"<<endl;
		cout<<"\t\t��         ��  4������ѧ�����������δ���      ��"<<endl;
		cout<<"\t\t��                                            ��"<<endl;
		cout<<"\t\t��         ��  5����ѧ�������˴�              ��"<<endl;
		cout<<"\t\t��                                            ��"<<endl;
		cout<<"\t\t��         ��  6. �˳�                        ��"<<endl;
		cout<<"\t\t��                                            ��"<<endl;
		cout<<"\t\t�������������������������" <<endl <<endl <<"\t\t";
		cout<<"\t �� ******��ѡ��������Ҫ����Ϣ******��"<<endl;
		cin>>i;
		switch(i)
		{
			case 1:get_info();break;
			case 2:modify();break;
		}
	}

} 
