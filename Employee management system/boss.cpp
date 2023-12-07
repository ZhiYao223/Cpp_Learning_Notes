#include "boss.h"

//构造函数
Boss::Boss(int id, string name, int dID)  //利用构造函数初始化老板身上的属性
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}

void Boss::showInfo()//显示个人信息      //重写父类中的纯虚函数
{
	cout << "职工编号： " << this->m_ID
		 << "\t职工姓名： " << this->m_Name
		 << "\t职工岗位： " << this->getDeptName()    //如果用this->DeptID返回int型数字岗位没有意义，所以调用getDeptName()获取岗位名称
		 << "\t岗位职责： 管理公司所有事务" << endl;
		
}

string	Boss::getDeptName()//获取岗位名称
{
	return string("总裁");
}