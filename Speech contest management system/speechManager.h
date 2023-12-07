#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<map>
#include<deque>
#include<numeric>
#include<fstream>
#include"speaker.h"
using namespace std;

//设计演讲比赛管理类
class SpeechManager
{
public:
	//构造函数
	SpeechManager();

	//展示菜单
	void show_Menu()  ;

	//退出系统
	void exitSystem();

	//析构函数
	~SpeechManager();

	//创建12名选手
	void createSpeaker();

	//初始化容器和属性
	void initSpeech();

	//选手抽签
	
	//开始比赛 比赛整个流程控制函数
	void startSpeech();

	//开始抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示得分
	void showScore();

	//保存记录
	void saveRecord();

	//读取纪录
	void loadRecord();

	//判断文件是否为空
	bool fileIsEmpty;

	//显示往届得分
	void showRecord();

	//清空纪录
	void clearRecord();

	//存放往届纪录的容器
	map<int, vector<string>>m_Record;

	//成员属性
	//保存第一轮比赛选手编号 容器
	vector<int>v1;

	//第一轮晋级选手编号容器
	vector<int>v2;

	//胜出前三名选手编号容器
	vector<int>vVictory;

	//存放编号以及对应具体选手容器，编号绑定对应选手
	map<int, Speaker>m_Speaker;  

	//存放比赛轮数变量
	int m_Index;
};