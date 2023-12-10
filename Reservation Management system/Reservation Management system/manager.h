#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"

//身份的派生类Manager类
class Manager : public Identity
{
public:
	//默认构造
	Manager();

	//有参构造(管理员姓名、密码)
	Manager(string name, string pwd);

	//选择菜单
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//情况预约纪录
	void cleanFile();
	
};
