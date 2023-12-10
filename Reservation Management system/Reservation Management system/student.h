#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"

//身份的派生类Student类
class Student :public Identity
{
public:
	//学号
	int m_id;

	//默认构造函数
	Student();

	//有参构造(学号、姓名、密码)
	Student(int id, int name, string pwd);

	//菜单界面,父类中有纯虚函数，子类中必须重写
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOder();

	//查看所有预约
	void showAllOrder();

};