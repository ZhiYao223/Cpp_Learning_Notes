#include "manager.h"

Manager::Manager(int id, string name, int dID)//构造函数
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}
void Manager::showInfo()//显示个人信息      //重写父类中的纯虚函数
{
	cout << "职工编号： " << this->m_ID
		<< "\t职工姓名： " << this->m_Name
		<< "\t职工岗位： " << this->getDeptName()    //如果用this->DeptID返回int型数字岗位没有意义，所以调用getDeptName()获取岗位名称
		<< "\t岗位职责： 完成老板交给的任务，并下发任务给员工" << endl;
}
string Manager::getDeptName()//获取岗位名称
{
	return string("经理");
}