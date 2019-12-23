#include"big1.cpp"
#include<string>
using namespace std;
int main()
{ 
	string s;
	string ss;
	ss+='0';//用于分母是否为0的判断
  int y;
  char choice='1';
  while(choice!='0')
  {
     cout<<"\t\t 1:输入计算 \n\t\t 2:从文件读取计算 \n\t\t 0:退出\n";
	 cout<<" 请输入(以第一个数字为准)：";
	 cin>>s;
	 choice=s[0];
	 //cin>>choice;
	 while(choice!='1' && choice!='0' && choice!='2'&&s[1]!=0)
	 {
		 cout<<"输入错误，请重新输入:";
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
		 cout<<" 请输入式子:";
		 cin>>s;
		 //检查输入的字符串是否含有错误的字符
		 for(i=0;i<s.length();i++)
			 if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='^')
			 {
				 if(s[i]>57 || s[i]<48 )
				 {
					 cout<<"错误的输入\n";
					 judge=1;
					 break;
				 }
			 }
		 //将输入的字符串分成2个整数字符串和1操作字符
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
					 cout<<"分母不能为0。"<<endl;
					 break;
				 }
		         //进行运算
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
				 for(;cout<<" 请选择输出到1.屏幕 2.文件： "&&cin>>y;)
				 {
					 if(y==1)
					 {
						 cout<<" 结果为：";
						 num3.printNumber();
					     break;
					 }
				     if(y==2)
					 {
						 cout<<" 储存成功。"<<endl;
				         num3.printTxt();
					     break;
					 }
				     else
					 {
					     cout<<" 输入错误，请重新输入。"<<endl;
					 }
				 }
				 break;
			 }
	 case '2':
		 for(;!in.eof();)
		 {
			 in>>s;
			 cout<<"计算式为："<<s<<endl;
			 for(i=0;i<s.length();i++)
			 if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='^')
			 {
				 if(s[i]>57 || s[i]<48 )
				 {
					 cout<<" 错误的输入\n";
					 judge=1;
					 break;
				 }
			 }
		 //将输入的字符串分成2个整数字符串和1操作字符
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
		         //进行运算
				 if(s2==ss)
				 {
					 cout<<"分母不能为0。"<<endl;
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
		         for(;cout<<" 请选择输出到1.屏幕 2.文件： "&&cin>>y;)
				 {
					 if(y==1)
					 {
						 cout<<" 结果为：";
						 num3.printNumber();
					     break;
					 }
				     if(y==2)
					 {
						 cout<<" 储存成功。"<<endl;
				         num3.printTxt();
					     break;
					 }
				     else
					 {
					     cout<<" 输入错误，请重新输入。"<<endl;
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

