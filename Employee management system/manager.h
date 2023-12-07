//员工中的经理类
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Manager :public Worker   
{
public:
	Manager(int id, string name, int dID);//构造函数

	virtual void showInfo();//显示个人信息      //重写父类中的纯虚函数

	virtual string getDeptName();//获取岗位名称
};