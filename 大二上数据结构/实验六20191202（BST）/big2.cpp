#include"big1.cpp"
#include<string>
using namespace std;
int main()
{ 
	string s;
	string ss;
	ss+='0';//���ڷ�ĸ�Ƿ�Ϊ0���ж�
  int y;
  char choice='1';
  while(choice!='0')
  {
     cout<<"\t\t 1:������� \n\t\t 2:���ļ���ȡ���� \n\t\t 0:�˳�\n";
	 cout<<" ������(�Ե�һ������Ϊ׼)��";
	 cin>>s;
	 choice=s[0];
	 //cin>>choice;
	 while(choice!='1' && choice!='0' && choice!='2'&&s[1]!=0)
	 {
		 cout<<"�����������������:";
		 cin>>s;
		 choice=s[0];
	 }
     Numberlist num1,num2,num3;
	 int i=0,j=0,k=0;char oper;
	 string s1;
     string s2;
	 int judge=0;
	 ifstream in("shuzi.txt");
	 switch(choice)
	 {
	 case '1':
		 cout<<" ������ʽ��:";
		 cin>>s;
		 //���������ַ����Ƿ��д�����ַ�
		 for(i=0;i<s.length();i++)
			 if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='^')
			 {
				 if(s[i]>57 || s[i]<48 )
				 {
					 cout<<"���������\n";
					 judge=1;
					 break;
				 }
			 }
		 //��������ַ����ֳ�2�������ַ�����1�����ַ�
			 if(judge==1)
				 break;
			 else
			 {
				 for(i=0;s[i]<58 && s[i]>47;i++)
			     s1+=s[i];
		         oper=s[i];
		         for( j=i+1;j<s.length();j++)
			     s2+=s[j]; 
				 if(s2==ss)
				 {
					 cout<<"��ĸ����Ϊ0��"<<endl;
					 break;
				 }
		         //��������
		         num1.inputNumber(s1);
                 num2.inputNumber(s2);
		         switch(oper)
				 {
				 case'+':num3=num1+num2;break;
		         case'-':num3=num1-num2;break;
		         case'*':num3=num1*num2;break;
				 case'/':num3=num1/num2;break;
				 case'^':
					 string sss=num1.mi(num2);
					 num3.inputNumber(sss);
					 break;
				 }
		         num3.checkNumber();
				 for(;cout<<" ��ѡ�������1.��Ļ 2.�ļ��� "&&cin>>y;)
				 {
					 if(y==1)
					 {
						 cout<<" ���Ϊ��";
						 num3.printNumber();
					     break;
					 }
				     if(y==2)
					 {
						 cout<<" ����ɹ���"<<endl;
				         num3.printTxt();
					     break;
					 }
				     else
					 {
					     cout<<" ����������������롣"<<endl;
					 }
				 }
				 break;
			 }
	 case '2':
		 for(;!in.eof();)
		 {
			 in>>s;
			 cout<<"����ʽΪ��"<<s<<endl;
			 for(i=0;i<s.length();i++)
			 if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='^')
			 {
				 if(s[i]>57 || s[i]<48 )
				 {
					 cout<<" ���������\n";
					 judge=1;
					 break;
				 }
			 }
		 //��������ַ����ֳ�2�������ַ�����1�����ַ�
			 if(judge==1)
				 break;
			 else
			 {
				 string s1;
				 string s2;
				 for(i=0;s[i]<58 && s[i]>47;i++)
			     s1+=s[i];
		         oper=s[i];
		         for( j=i+1;j<s.length();j++)
			     s2+=s[j]; 
		         //��������
				 if(s2==ss)
				 {
					 cout<<"��ĸ����Ϊ0��"<<endl;
					 break;
				 }
		         num1.inputNumber(s1);
                 num2.inputNumber(s2);
		         switch(oper)
				 {
				 case'+':num3=num1+num2;break;
		         case'-':num3=num1-num2;break;
		         case'*':num3=num1*num2;break;
			     case'/':num3=num1/num2;break;
				 case'^':
					 string sss=num1.mi(num2);
					 num3.inputNumber(sss);
					 break;
				 }
		         num3.checkNumber();
		         for(;cout<<" ��ѡ�������1.��Ļ 2.�ļ��� "&&cin>>y;)
				 {
					 if(y==1)
					 {
						 cout<<" ���Ϊ��";
						 num3.printNumber();
					     break;
					 }
				     if(y==2)
					 {
						 cout<<" ����ɹ���"<<endl;
				         num3.printTxt();
					     break;
					 }
				     else
					 {
					     cout<<" ����������������롣"<<endl;
					 }
				 }
			 }
		 }
		 in.close();
	 case '0':break;
	 }
  }
  return 0;
}

