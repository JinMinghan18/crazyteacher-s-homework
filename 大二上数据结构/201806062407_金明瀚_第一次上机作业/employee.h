//employee.h
#ifndef EMPLOYEE_H_H
#define EMPLOYEE_H_H
#include <iostream>
#include "mystring.cpp"
class employee
{
	protected:
		mystring name;	//����
		int individualEmpNo;	//���˱��
		int grade;	//����
		float accumPay;	//��н
		static int employeeNo;	//����˾ְԱ���Ŀǰ���ֵ
	public:
		employee();	//���캯��
		~employee();	//��������
		void SetName(mystring);  	//������������
		mystring GetName(); 	//��ȡ��������
		void promote(int);	//��������
		void SetaccumPay (float pa);  	//������н����
		int GetindividualEmpNo();  	//��ȡ��ź���
		int Getgrade();   	//��ȡ������
		float GetaccumPay();  	//��ȡ��н����
};
#endif
