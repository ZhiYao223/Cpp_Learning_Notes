#pragma once
#include <iostream>
using namespace std;
#include <string>

//职工抽象类
class Worker    //基类
{
public:
	virtual void showInfo() = 0;//显示个人信息   纯虚函数

	virtual string getDeptName() = 0;//获取岗位名称   纯虚函数

	int m_ID;//职工编号

	string m_Name;//职工姓名

	int m_DeptID;//部门编号
};