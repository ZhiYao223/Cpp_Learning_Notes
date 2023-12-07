//封装函数显示界面，如void showMenu()
//在main函数中调用封装好的函数
//退出功能： 根据用户不同的选择，进入不同功能，选择是switch分支结构，搭建框架，当选择0时，执行推出
//实现添加联系人功能，联系人上限为1000人，联系人信息包括(姓名、性别、年龄、联系电话、家庭住址）

//设计联系人结构体
//设计通讯录结构体
//main函数中创建通讯录
//封装添加联系人函数
//测试添加联系人功能

//按照姓名进行删除指定联系人
//封装检测联系人是否存在
//封装删除联系人函数
//测试删除联系人功能
//设计思路：删除联系人前，我们需要先判断用户输入的联系人是否存在，如果存在，删除；不存在提示用户没有要删除的联系人，
//因此我们可以把检测联系人是否存在封装成一个函数中，如果存在，返回联系人在通讯录中的位置，不存在返回-1

#include <iostream>
#include <string>

using namespace std;

#define MAX 1000   //最大人数

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  7、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
//显示菜单界面
struct Person
{
	string m_name; 
	string m_sex;
	int m_age;
	string m_Phone;
	string m_Addr;
};

//通讯录结构体
struct Addressbooks
{
	struct Person PersonArray[MAX]; //通讯录中保存的联系人数组
	int m_size; //通讯录中当前纪录人员个数
};

//添加联系人
void addPerson(Addressbooks * Addrbook)    //abs
{
	//判断通讯录是否没满，若满则不再添加
	if (Addrbook->m_size == MAX)
	{
		cout << "通讯录已满，无法添加!" << endl;
		return;
	}
	else
	{   //输入姓名
		string name; 
		cout << "请输入姓名：" << endl;
		cin >> name;
		Addrbook->PersonArray[Addrbook->m_size].m_name = name;
		//输入性别
		cout << "请输入性别： " << endl;
		cout << "1----男" << endl;
		cout << "0----女" << endl;
		string sex = "0";// 若定义成int型，则输入字母时，在if中也为真，会进入死循环
		//在错误提示前，输入cin.clear(); cin.ignore();清空cin的缓冲区
		while (true)
		{
			//如果输入的是1或2则退出循环，如果输入有误，则重新输入
			cin >> sex;
			if (sex == "0" || sex == "1")
			{
				Addrbook->PersonArray[Addrbook->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		    //输入年龄
			cout << "请输入年龄： " << endl;
			int age = 0;
			cin >> age;
			Addrbook->PersonArray[Addrbook->m_size].m_age = age;
			//输入联系电话
			cout << "请输入联系电话： " << endl;
			string phone;
			cin >> phone;
			Addrbook->PersonArray[Addrbook->m_size].m_Phone = phone;   
			//cout << "格式错误，请输入正确的联系电话" << endl; 
			//输入家庭住址
			cout << "请输入家庭住址： " << endl;
			string address;
			cin >> address;
			Addrbook->PersonArray[Addrbook->m_size].m_Addr = address;

			//更新通讯录人数
			Addrbook->m_size++;    //自增1，使人员信息按顺序存入结构体数组PersonArray[]
			cout << "添加成功" << endl;
			system("pause"); //请按任意键继续
			system("cls");   //清屏操作
		
	}
}
//2、显示所有联系人信息
void showPerson(Addressbooks* Addrbook)
{
	if (Addrbook->m_size == 0)
	{
		cout << "当前记录为空" << endl; 
	}
	else
	{
		for (int i = 0; i < Addrbook->m_size;i++)
		{
			cout << "姓名：" << Addrbook->PersonArray[i].m_name << "\t";
			cout << "性别：" << ((Addrbook->PersonArray[i].m_sex == "1") ? "男" : "女") << "\t";
			cout << "年龄：" << Addrbook->PersonArray[i].m_age << "\t";
			cout << "电话：" << Addrbook->PersonArray[i].m_Phone << "\t";
			cout << "住址：" << Addrbook->PersonArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
int main()
{
	int select = 0;  //用户选择变量
	Addressbooks Addrbook;    //创建通讯录结构体变量Addrbook
	Addrbook.m_size = 0; //初始化通讯录人员人数
	while (true)
	{
		showMenu(); // 菜单调用
		cin >> select; //功能变量
		switch (select)
		{
		case 1:addPerson(&Addrbook);   break;   //1、添加联系人 
		case 2:showPerson(&Addrbook);  break;   //2、显示联系人
		case 3:break;   //3、删除联系人
		case 4:break;   //4、查找联系人
		case 5:break;   //5、修改联系人
		case 6:break;   //6、清空联系人
		case 0:cout << "欢迎下次使用，再见！" << endl;
			system("pause");
			return 0;//正常退出程序，无论后面还有什么代码
			//break;   //7、退出通讯录
		default: break;
		}
	}
	system("pause");
	return 0;
}

