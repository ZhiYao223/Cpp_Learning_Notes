#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//老板类
class Boss :public Worker
{
public:
	Boss(int id, string name, int dID);//构造函数

	virtual void showInfo();//显示个人信息      //重写父类中的纯虚函数

	virtual string getDeptName();//获取岗位名称
};