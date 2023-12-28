#include<iostream>
using namespace std;
#include "Identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
//登陆功能 参数分别为：操作文件名称、操作身份类型
void LoginIn(string fileName, int type)
{
	//父类指针，用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	
	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接收用户的信息
	int id = 0;
	string name;
	string pwd;

	switch (type)
	{
	case 1:
		cout << "请输入你的学号：";
		cin >> id;
		break; 
	case 2:	
		cout << "请输入您的职工号：";
		cin >> id; 
		break;
	case 3:
		break; 
	default:
		break;
	}
	cout << "请输入用户名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;

	if (type == 1) {
		//学生身份验证
		int fId;			//从文件中读取的id号
		string fName;		//从文件中读取的姓名
		string fPwd;		//从文件中读取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			cout << fId << " " << fName << " " << fPwd << endl;

			if (id == fId && name == fName && pwd == fPwd) {
				cout << "学生验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单
				//ifs.close();
				return;
			}				
		}
	}
	else if (type == 2) {
		//教师身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "教师验证登陆成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员身份验证
	}
	cout << "验证登陆失败！" << endl;
	system("pause");
	system("cls");
	return;
}



//退出系统
bool OutSystem()
{
	cout << "欢迎下一次使用！" << endl;
	system("pause");
	return true;
}




int main()
{
	int select = 0;		//用于接收用户的选择

	while (true)
	{
		cout<<"=====================欢迎来到HUD机房管理系统========================"<<endl;
		cout << "请输入您的身份：" << endl;
		cout << "\t\t------------------------------------------\n" << endl;
		cout << "\t\t|                                        |\n" << endl;
		cout << "\t\t|              1.学生代表                |\n" << endl;
//		cout << "\t\t|                                            << endl;
		cout << "\t\t|              2.老	师               |\n" << endl;
//		cout << "\t\t|                                           *\n" << endl;
		cout << "\t\t|              3.管 理 员                |\n" << endl;
//		cout << "\t\t|                                           *\n" << endl;
		cout << "\t\t|              0.退    出                |\n" << endl; 
//		cout << "\t\t|                                           " << endl;
		cout << "\t\t------------------------------------------\n" << endl;
		cout << "请输入您的选项：";
		 
		cin >> select;  //接收用户选择
		switch (select)
		{
		case 1:	LoginIn(STUDENT_FILE, 1);	break;//学生身份
		case 2:	LoginIn(TEACHER_FILE, 2);	break;//老师身份
		case 3:	LoginIn(ADMIN_FILE,   3);	break;//管理员身份	
		case 0:	OutSystem();	break;//退出系统
		default:
			cout << "输入有误，请重新选择！" << endl; 
			system("pause");
			system("cls");
			break;
		}


	}
	system("pause");
	return 0;
}