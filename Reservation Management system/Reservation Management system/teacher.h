#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "Identity.h"

//身份的派生类Teacher类
class Teacher :public Identity
{
public:
	int m_EmpId;	//教师编号
	//默认构造函数
	Teacher();

	//有参构造函数 (职工编号、姓名、密码)
	Teacher(int empId, string name, string pwd);

	//教师操作的菜单界面
	virtual void operMenu();

	//审核预约
	void validOrder();

	//查看所有预约
	void showAllOrder();
						
};