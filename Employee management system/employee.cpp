#include "employee.h"

Employee::Employee(int id, string name, int dID)  //利用构造函数初始化普通员工身上的属性
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}

//子类重写父类中的纯虚函数/虚函数, virtual在子类中可删可不删
void Employee::showInfo() //显示个人信息
{
	cout << "职工编号： " << this->m_ID
		<< "\t职工姓名： " << this->m_Name
		<< "\t职工岗位： " << this->getDeptName()    //如果用this->DeptID返回int型数字岗位没有意义，所以调用getDeptName()获取岗位名称
		<< "\t岗位职责： 完成经理交给的任务" << endl; 
}
string Employee::getDeptName() //获取岗位名称
{
	return string("员工");

}