//普通员工文件, 创建Worker类的子类
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Employee :public Worker
{ 
	
public:
	Employee(int id, string name, int dID);  //利用构造函数初始化普通员工身上的属性: 职工编号、名字、部门编号

	//子类重写父类中的纯虚函数/虚函数, virtual在子类中可删可不删
	virtual void showInfo(); //显示个人信息
	virtual string getDeptName(); //获取岗位名称

	
};