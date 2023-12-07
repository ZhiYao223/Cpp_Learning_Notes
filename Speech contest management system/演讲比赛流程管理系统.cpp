#include<iostream>
#include"speechManager.h"
using namespace std;
#include<string>
#include<ctime>
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建管理类对象
	SpeechManager sm;
	
	//测试12名选手创建
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "选手编号：" << it->first
			<< "\t姓名：" << it->second.m_Name
			<< "\t成绩：" << it->second.m_Score[0] << endl; 
	}*/

	int choice = 0 ;  //用来存储用户选项
	while (true)
	{
		sm.show_Menu();

		cout << "请输入您的选择：" << " ";
		cin >> choice;   //接收用户选项
		switch (choice)
		{
		case 1: sm.startSpeech(); break;    //开始比赛
		case 2:	sm.showRecord();  break;	//查看纪录
		case 3:	sm.clearRecord(); break;	//清空记录
		case 4:	sm.exitSystem();  break;	//退出系统
		default: system("cls");   break;	//清屏
		}
	}

	system("pause");
	return 0;

}