#include <iostream>
using namespace std;
#include "workerManager.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
#if 0//测试代码
	
	Worker* worker = NULL;   //预防野指针
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
	//三个不同对象都调用showInfo();函数，结果是不一样的，这就是多态：一个接口有多种形态
#endif 

	WorkerManager wm;//实例化管理者对象
	
	int choice = 0; //用来存储用户的选项
	
	while (true)
	{
		wm.Show_Menu();//调用展示菜单成员函数
		cout << "请输入您的选择：  " << endl;
		cin >> choice; //接收用户的选项呢
		switch (choice)
		{
		case 0:	wm.ExitSystem();	    break;		//退出系统
				
		case 1: wm.Add_Emp();			break;//增加职工
				
		case 2: wm.Show_Emp();			break;//显示职工
				
		case 3:	wm.Del_Emp();           break;//case中代码块过长，需要用{}括起来封装一下
				
		case 4:	wm.Mod_Emp();			break;//修改职工
				
		case 5:	wm.Find_Emp();			break;  //按照编号排序
				
		case 6:	wm.Sort_Emp();		    break;	//查找职工信息
				
		case 7:	wm.Clean_file();		break;   //清空所有文档
		
		default: system("cls");		    break; //清屏
		}
	}
	system("pause");
	return 0;
}