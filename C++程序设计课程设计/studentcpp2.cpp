#include <iostream>
#include <fstream>
#include<algorithm> 
#include <iomanip>
#include <map>
#include "student.h"
student a[1000000];
int count1,count2,counttea;//count1�ǿ���ѧ����count2�Ǳ����γ�����counttea����ʦע���� 
const int admin =  6666;
struct safesystem
{
	string zhanghao;
	string mima;
}tea[1000];
struct students
{
	string classnames;//�����Ŀγ� 
	string namee;//����ѧ��name 
	int countname;//���δ���ͳ�� 
	int countclass;//�ÿγ̱�������ͳ�� 
}stu[10000];
bool cmp(students a,students b)
{
	return a.countname>b.countname;
}
bool cmp1(students a,students b)
{
	return a.countclass>b.countclass;
}
int main()
{
	//����ϵͳ	
	cout<<"�������������: ";
	int ad;
	cin>>ad;
	if(ad == admin)	
	{
		cout<<"welcome to the system teacher\n";
		cout<<"1��register in 2��log on\n";
		int choice;
		cin>>choice;
		if(choice == 1)
		{
			cout<<"������ע���˺ţ��Ƽ�ʹ�ý�ʦid): ";
			cin>>tea[counttea].zhanghao;
			cout<<"�������½����: ";
			cin>>tea[counttea].mima;
			cout<<"\nregister successfully\n";
			ofstream out("��ʦ�˺�.txt",ios::app|ios::out);
			out<<tea[counttea].zhanghao<<" "<<tea[counttea].mima<<" "<<endl;
			out.close();
		}
		else if(choice == 2)
		{ 
			ifstream in("��ʦ�˺�.txt");
			int i=0;
			while(in>>tea[i].zhanghao>>tea[i].mima)
			{
				i++;
			}
			string zh,mm;
			cout<<"�������˺ţ�"; 
			cin>>zh;
			cout<<endl;
			cout<<"���������룺"; 
			cin>>mm;
			int flag = 0;//ȷ���Ƿ�����˺� 
			int spot;//��¼����˺�λ�� 
			for(int j = 0;j<=1000;j++)
			{
				if(tea[j].zhanghao == zh )
				{
					flag = 1;
					spot = j;
				}
			}
			if(flag)
			{
				if(tea[spot].mima == mm)
				{
					cout<<"welcome sir\n";
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
				}
				
				else 
				{
					cerr<<"wrong key\n";
					return 0;
				}
			}
			else
			{
				cerr<<"wrong cipher\n";
				return 0; 
			}
		}
	}
	else 
	{
		cout<<"big key wrong\n";
		return 0;
	}
	
	//������� 
	int cnt=0;
	int i;
	cout<<"\t\t\t�������������������������"<<endl;
	cout<<"\t\t\t\t��ӭ����ѧ������ϵͳ���"<<endl;
	cout<<"\t\t\t�������������������������"<<endl;
	cout<<"\t\t\t��                                            ��"<<endl;
	cout<<"\t\t\t��                                            ��"<<endl;
	cout<<"\t\t\t��         ��  1��¼��ѧ����ȱ�μ�¼��        ��"<<endl;
	cout<<"\t\t\t��                                            ��"<<endl;
	cout<<"\t\t\t��         ��  2���޸�ĳ��ѧ����ȱ�μ�¼��    ��"<<endl;
	cout<<"\t\t\t��                                            ��"<<endl;
	cout<<"\t\t\t��         ��  3����ѯĳ��ѧ����ȱ�����      ��"<<endl;
	cout<<"\t\t\t��                                            ��"<<endl;
	cout<<"\t\t\t��         ��  4������ѧ�����������δ���      ��"<<endl;
	cout<<"\t\t\t��                                            ��"<<endl;
	cout<<"\t\t\t��         ��  5����ѧ�����ογ̺��˴�        ��"<<endl;
	cout<<"\t\t\t��                                            ��"<<endl;
	cout<<"\t\t\t��         ��  0. �˳�                        ��"<<endl;
	cout<<"\t\t\t��                                            ��"<<endl;
	cout<<"\t\t\t�������������������������" <<endl <<endl <<"\t\t";
	cout<<"\t      �� ******��ѡ��������Ҫ����Ϣ******��"<<endl;
   	while(1)
	{
		cout<<"����������ѡ����\n"; 
		cin>>i;
		switch(i)
		{
			case 0:return 0; 
			
			case 1:
			{
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				cout<<"��ѡ����1������¼��2����¼\n";
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				int c;
				cin>>c;
				if(c == 1)
				{
					cout<<"/---------------------------------------------------------------------------------------/\n" ;	
					cout<<"������˴�¼���ѧ������\n";
					cin>>cnt;
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
					for(int i=0;i<cnt;i++)
					{
						a[i].get_info();
						cout<<endl;
					}
				}
				else if(c == 2)
				{
					cout<<"������˴�¼���ѧ������\n";
					int b;//��¼��ѧ������
					cin>>b;
					for(int i=0;i<cnt;i++)
					{
						if(a[i].check_id() == 0)
						{
							a[i].get_info();
							b--;
						}
					} 
					for(int i = cnt;i<cnt+b;i++)
					{
						a[i].get_info();
					} 
					cnt+=b;
				}
				cout<<"�Ƿ񵼳��ı�1��yes 0��no\n";
				int i;
				cin>>i;
				if(i == 1)
				{
					ofstream outfile("���δ���.txt",ios::out|ios::app);
					for(int j=0;j<cnt;j++)
					{
						outfile<<a[j].check_name()<<" "<<a[j].check_id()<<" "<<a[j].check_time()
							<<" "<<a[j].check_order()<<" "<<a[j].check_classname()<<" "<<a[j].check_abstype()<<endl;
					}				
				}
				else if(i == 0)
				break;
				break;
			}
			case 2://�޸�ĳ��ѧ����ȱ�μ�¼�� 
			{
				string name,classname,abstype;
				int datee,orderr;
				long long idd;
				int i = 0;
				ifstream in("���δ���.txt",ios::in);
				//���ú����������ݣ���ʱû�и��õİ취 
				while(in>>name>>idd>>datee>>orderr>>classname>>abstype)
				{
					a[i].chuanru_name(name);
					a[i].chuanru_id(idd);
					a[i].chuanru_date(datee);
					a[i].chuanru_order(orderr);
					a[i].chuanru_classname(classname);
					a[i].chuanru_abstype(abstype);
					i++;
				}
				int id,date,order;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"��������Ҫ�޸ĵ�ѧ��ѧ�š�ȱ��ʱ��Ϳ�ʱ\n";
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				cin>>id;
				cin>>date;
				cin>>order;
				for(int j=0;j<=i;j++)
				{
					if(a[j].check(id,date,order))
					{
						a[j].modify();
						break;
					}	
				}
				break;  
			}
			case 3://ѯĳ��ѧ����ȱ����� 
			{
				string name,classname,abstype;
				int datee,orderr;
				long long idd;
				int i = 0;
				ifstream in("���δ���.txt",ios::in);
				//���ú����������ݣ���ʱû�и��õİ취 
				while(in>>name>>idd>>datee>>orderr>>classname>>abstype)
				{
					a[i].chuanru_name(name);
					a[i].chuanru_id(idd);
					a[i].chuanru_date(datee);
					a[i].chuanru_order(orderr);
					a[i].chuanru_classname(classname);
					a[i].chuanru_abstype(abstype);
					i++;
				}
				in.close();
				//������� 
				long long id;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"��������Ҫ��ѯ��ѧ����ѧ��:\n";
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cin>>id;
				for(int j=0;j<=i;j++)
				{
					a[j].search(id); 
				}
				break;
			}
			
			case 4://����ѧ�����������δ��� 
			{	
				string name,classname,abstype;
				int datee,orderr;
				long long idd;
				int cnt = 0;
				ifstream in("���δ���.txt",ios::in);
				//���ú����������ݣ���ʱû�и��õİ취 
				while(in>>name>>idd>>datee>>orderr>>classname>>abstype)
				{
					a[cnt].chuanru_name(name);
					a[cnt].chuanru_id(idd);
					a[cnt].chuanru_date(datee);
					a[cnt].chuanru_order(orderr);
					a[cnt].chuanru_classname(classname);
					a[cnt].chuanru_abstype(abstype);
					cnt++;
				}
				in.close(); 
				//�������
				int cnt2=0;
				int ftime1,ltime1;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"��������ʼʱ�䣨����20000101��\n";
				cin>>ftime1;
				cout<<"���������ʱ�䣨����20000101��\n";
				cin>>ltime1;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				for(int i = 0;i<cnt;i++)
				{
					int time = a[i].check_time();
					if(time>=ftime1 && time <= ltime1)
					{
						if(i == 0)//��һ��ȷ��
						{
							stu[cnt2].namee = a[i].check_name();
							stu[cnt2].countname = 1;
						}
						else 
						{
							int flag = 0;
							for(int j=0;j<=cnt2;j++)
							{
								if(stu[j].namee == a[i].check_name())
								{
									flag = 1;
									stu[j].countname++;//��ѧ�����δ���+1 
									break; 
								}
							}
							if(!flag)//���û���������������ҵ��ÿ���ѧ�� 
							{
								cnt2++;//����ѧ����++�� 
								stu[cnt2].namee = a[i].check_name();
								stu[cnt2].countname = 1;
							}
							count1 = cnt2;//�����ܿ���ѧ���� 
						} 
					}
					else continue;
				}
				sort(stu,stu+count1,cmp);
				for(int i=0;i<=count1;i++)
				{
					cout<<"������ "<<stu[i].namee<<" "<<"���δ����� "<<stu[i].countname<<endl; 
				}
				break;
			} 
			case 5:// ��ѧ�����ογ̺��˴�  
			{
				string name,classname,abstype;
				int datee,orderr;
				long long idd;
				int cnt = 0;
				ifstream in("���δ���.txt",ios::in);
				//���ú����������ݣ���ʱû�и��õİ취 
				while(in>>name>>idd>>datee>>orderr>>classname>>abstype)
				{
					a[cnt].chuanru_name(name);
					a[cnt].chuanru_id(idd);
					a[cnt].chuanru_date(datee);
					a[cnt].chuanru_order(orderr);
					a[cnt].chuanru_classname(classname);
					a[cnt].chuanru_abstype(abstype);
					cnt++;
				}
				in.close(); 
				//�������
				int cnt3 = 0;
				int ftime2,ltime2;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"��������ʼʱ�䣨����20000101��\n";
				cin>>ftime2;
				cout<<"���������ʱ�䣨����20000101��\n";
				cin>>ltime2;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				for(int i=0;i<=cnt;i++)
				{
					int time = a[i].check_time();
					if(time>=ftime2 && time <= ltime2)
					{
						if(i == 0)//��һ������ 
						{
							stu[cnt3].classnames = a[i].check_classname();
							stu[cnt3].countclass = 1;
						}
						else 
						{
							int flag1 = 0;
							for(int j = 0;j<=cnt3;j++)//cnt3�ǵ����ܼ�¼�µ����������ڱȽϺ���������Ƿ����ظ� 
							{
								if(stu[j].classnames == a[i].check_classname())
								{
									flag1 = 1;
									stu[j].countclass++;
									break;
								}
							}
							if(!flag1)
							{
								cnt3++;
								stu[cnt3].classnames = a[i].check_classname();
								stu[cnt3].countclass = 1;
							}
							count2 = cnt3;
						}
					}
					else continue;
				}
				sort(stu,stu+count2,cmp1);
				cout<<"�����γ�                  ��������\n";
				for(int i=0;i<count2;i++)
				{
					cout<<stu[i].classnames<<"                            "<<stu[i].countclass<<endl;
				} 
				break;
			}
			
		}
	}
	return 0;
} 
