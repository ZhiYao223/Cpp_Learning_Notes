#include"speechManager.h"
#include"speaker.h"

//构造函数
SpeechManager::SpeechManager()
{
	//初始化容器和属性
	this->initSpeech();

	//创建12名选手
	this->createSpeaker();
	
	//加载往届纪录
	this->loadRecord();
}


void SpeechManager::show_Menu()
{
	cout << "****************************************************************" << endl;
	cout << "**************************欢迎参加演讲比赛**********************" << endl;
	cout << "**************************1.开始演讲比赛************************" << endl;
	cout << "**************************2.查看往届纪录************************" << endl;
	cout << "**************************3.清空比赛纪录************************" << endl;
	cout << "**************************4.退出比赛程序************************" << endl;
	cout << "****************************************************************" << endl;

	cout << endl;
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear(); 

	//初始化比赛轮数
	this->m_Index = 1;
	//初始化 纪录容器
	this->m_Record.clear();
}

//创建12名选手
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建具体的选手
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2;j++)   //第几轮分数
		{
			sp.m_Score[j] = 0;		 //初始化选手分数
		}
		//创建选手编号并放入v1容器
		this->v1.push_back(i + 10001);

		//选手编号以及对应选手 放入到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//抽签
void SpeechManager::speechDraw()
{
	cout << "第 <<" << m_Index << ">>轮比赛选手正在抽签" << endl;
	cout << "-----------------------------" << endl;
	cout << "抽签后演讲顺序如下:" << endl;
	if (this->m_Index == 1) //第一轮抽签
	{
		random_shuffle(v1.begin(), v1.end()); //打乱选手编号
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else       //第二轮抽签
	{
		//打乱第一轮晋级，进入第二轮的6名选手顺序
		random_shuffle(v2.begin(), v2.end());  
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl; 
	}
	cout << "-------------------------------" << endl;
	system("pause");  //按任意键继续
	cout << endl; 
}


void SpeechManager::startSpeech()
{
	//第一轮比赛
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3、显示晋级结果
	this->showScore();
	//第二轮比赛
	this->m_Index++;
	//1、抽签
	this->speechDraw();
	//2、比赛
	this->speechContest();
	//3、现实最终结果
	this->showScore();
	//4、保存分数到文件中
	this->saveRecord();

	//重置比赛 初始化属性
	this->initSpeech();

	//创建选手
	this->createSpeaker();

	//获取往届纪录
	this->loadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}
//比赛
void SpeechManager::speechContest()
{
	cout << "---------------------第<<" << this->m_Index << ">>轮比赛正式开始------------" << endl;

	//准备临时容器存放小组成绩，允许出现相同元素， 按分数降序排列
	//得分key 编号int map默认按key(得分)升序
	multimap<double, int, greater<double>> groupScore; //分数、编号 降序  内建函数对象

	int num = 0; //纪录人员个数 6人一组 

	vector<int>v_Src;  //比赛选手容器
	if (this->m_Index == 1) //第一轮比赛选手
	{
		v_Src = v1;   //将第一轮参赛的选手存入容器
	}
	else
	{
		v_Src = v2;   //将第二轮参赛的选手存入容器
	}
	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;  //人员个数
		//评委打分
		deque<double>d; //创建存储得分的容器
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; //600~1000
			//cout << score << "  ";
			d.push_back(score);  //将得分插入容器
		}
		
		sort(d.begin(), d.end(), greater<double>());  //将按得分由高到低降序排列
		d.pop_front();    //去除最高分
		d.pop_back();    //去除最低分
		double sum = accumulate(d.begin(), d.end(), 0); //累加序列元素
		double avg = sum / (double)d.size(); //计算平均分

		//打印平均分
		//cout << "编号： " << *it << "姓名： " << this->m_Speaker[*it].m_Name << "获取平均分： " << avg << endl; 
		
		//将平均分放入到map容器中  通过map[key]可以拿到value值，即通过m_Speaker[*it]拿到Speaker,
		//再通过Speaker拿到该选手的得分，m_Index-1 = 0 表示将avg平均分赋值给0号位置上
		//m_Speaker[*it] 中的 *it 是一个迭代器 it 所指向的元素, 为vector<int>型的选手编号，
		//再通过map<key, value>m; m[key] = value;  即m_Speaker[*it] 为map容器对应的value值，即Speaker类型
		//然后再通过Speaker.m_Score[]将平均值放入该Speaker的分数中。
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg; //*it为选手编号，通过key值获取value中的Speaker类型，再获取分数m_Score

		 
		//将打分数据放入到6人 临时小组容器中  map容器默认按照key值排序因此将avg放第一个参数项
		groupScore.insert(make_pair(avg, *it)); //key是得分，value是具体选手编号，//将选手编号和分数绑定放入容器
		//每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号： " << it->second << "姓名： " << this->m_Speaker[it->second].m_Name
					<< "成绩： " << this->m_Speaker[it->second].m_Score[this->m_Index -1] << endl;

			}
			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; count++, it++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second); //将这一组前三名编号存入v2容器
				}
				else
				{
					vVictory.push_back((*it).second); //将第二轮比赛的前三名编号存入vVictory容器
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "----------------------第" << this->m_Index << "轮比赛完毕！-----------------------" << endl;
	system("pause");
	cout << endl;
}
//显示得分
void SpeechManager::showScore()
{
	cout << "-----------------第" << this->m_Index << "轮晋级选手信息如下： -----------------------" << endl;
	vector<int>v;     //晋级人员 容器
	if (this->m_Index == 1)  //第一轮  晋级后选手都在v2容器中
	{
		v = v2; 
	}
	else                   //第二轮晋级选手，都在vVictory容器中
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号:  " << *it << "姓名： " << this->m_Speaker[*it].m_Name << "得分：  " <<
			this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	//system("cls");   //清屏
	this->show_Menu();
}

//保存纪录
void SpeechManager::saveRecord()
{
	ofstream ofs;
	//重新打开名为 “speech.csv” 的文件，并以写入和追加的模式打开文件，
	//以准备向文件中写入数据或在末尾追加数据。
	ofs.open("speech.csv", ios::out | ios::app);  //用追加的方式写文件

	//将每个选手数据，写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		//将 *it 的值、this->m_Speaker[*it].m_Score[1] 的值
		// 以及逗号 , 依次插入到文件中，形成一条记录或一行数据。
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}  
	ofs << endl;    //在文本文件中添加新行

	ofs.close();	// 
	cout << "纪录已保存" << endl;

	//有记录了，文件不为空
	this->fileIsEmpty = false;
}

//查看往届比赛纪录
void SpeechManager::loadRecord()
{
	ifstream  ifs("speech.csv", ios::in); //读文件
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();  //关闭文件
		return;       
	}
	//文件清空情况
	char ch;
	ifs >> ch;  //读走一个字符
	if (ifs.eof())  //检查文件指针是否已经到达文件末尾,判断是否已经读取到文件的最后一行
	{
		cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close(); 
		return;
	}
	//文件不为空
	this->fileIsEmpty = false;
	//将已读取的字符放回输入流通常是为了纠正错误、
	//回退到之前的状态或者支持多模块 / 多函数的读取操作。
	ifs.putback(ch);	//读完后文件光标后移一位，为了读到全部数据，需将上面读取的单个字符，放回来
 	string data;
	//流提取运算符（ >> ）从输入流中连续读取数据，并将数据存储到变量 data
	//通常用于循环读取输入流中的数据，直到无法再读取数据为止。
	int index = 0;  //第几届，一定要放到while循环外面，否则取出1届数据
	while (ifs >> data)  //将数据读到data中
	{
		//cout << data << endl;
		//10002,86.675,10009,81.3,10007,78.55,
		vector<string>vname;   //存放6个string字符串
		int pos = -1; //查到","位置的变量
		int start = 0;
		
		while (true)
		{
			//在字符串 data 中从指定的起始位置 start 开始，
			//查找第一个出现的子串 "," 的位置，并将结果存储在变量 pos 中。
			pos = data.find(",", start);
			if (pos == -1)  
			{
				break; //没有找到情况
			}
			//在字符串 data 中从指定的起始位置 start 开始，
			//提取一个长度为 pos - start 的子串，并将提取的子串赋值给变量 temp。
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			vname.push_back(temp);  //将从文件中提取的选手编号、得分数据插入容器
			start = pos + 1;
		}
		//将一个由 index 和 vname 构成的键值对插入到成员变量 m_Record 中。
		this->m_Record.insert(make_pair(index, vname));
		index++;
	}
	ifs.close();
	/*for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << it->first << "冠军编号：" << it->second[0] << "分数： " << it->second[1] << endl;


	}*/
};

//显示往届纪录
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在，或记录为空！" << endl;
	}
	else
	{
		for (size_t i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届"
				<< "冠军编号：" << this->m_Record[i][0] << " 得分: " << this->m_Record[i][1] << "  "
				<< "亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << "  "
				<< "季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}


//清空纪录
void SpeechManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;    

	if (select == 1)
	{
		//打开模式 ios::trunc 如果文件存在，删除文件并重新创建，以用于写入数据
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化属性
		this->initSpeech();

		//创建选手
		this->createSpeaker();

		//获取往届纪录
		this->loadRecord();

		cout << "清空成功！" << endl;

	}
	system("pause");
	system("cls");
}

//析构函数
SpeechManager::~SpeechManager()
{

}







