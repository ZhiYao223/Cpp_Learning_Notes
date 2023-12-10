#include<iostream>
using namespace std;


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
		cout << "\t\t|-------------------------------------------|\n" << endl;
		cout << "\t\t|                                           |\n" << endl;
		cout << "\t\t|              1.学生代表                   |\n" << endl;
//		cout << "\t\t|                                           " << endl;
		cout << "\t\t|              2.老	 师                 |\n" << endl;
//		cout << "\t\t|                                           *\n" << endl;
		cout << "\t\t|              3.管 理 员                   |\n" << endl;
//		cout << "\t\t|                                           *\n" << endl;
		cout << "\t\t|              0.退    出                   |\n" << endl; 
//		cout << "\t\t|                                           " << endl;
		cout << "\t\t|-------------------------------------------|\n*" << endl;
		cout << "请输入您的选项：";
		 
		cin >> select;  //接收用户选择
		switch (select)
		{
		case 1:		break;//学生身份
		case 2:		break;//老师身份
		case 3:		break;//管理员身份	
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