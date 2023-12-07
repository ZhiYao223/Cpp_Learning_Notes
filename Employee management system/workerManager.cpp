#include "workerManager.h"
#include <iostream>

WorkerManager::WorkerManager()  //构造函数类内声明类外定义
{
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //读文件
	if (!ifs.is_open())
	{
		//cout << "文件不存在！" << endl;
		//初始化指针
		//初始化纪录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;   
		ifs.close();
		return;	//文件不存在，退出构造函数
	}

	//2、文件存在，但数据为空
	char ch;
	ifs >> ch;   //读取字符
	if (ifs.eof())   //读取字符，若读到EOF文件尾标志，则表示文件读完了
	{
		//cout << "文件不存在！" << endl;
		//初始化指针
		//初始化纪录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;   //文件不存在，退出构造函数
	}

	//3、文件存在，并且纪录数据
	int num = this->get_EmpNum();  //拿到职工人数并存入num
	//cout << "职工人数为： " << num << endl;
	this->m_EmpNum = num;  //更新m_EmpNum人数

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpArray[i]->m_ID; i++)
	//{
	//	cout << "职工编号： " << this->m_EmpArray[i]->m_ID
	//		<< "姓名： " << this->m_EmpArray[i]->m_Name
	//		<< "部门编号： " << this->m_EmpArray[i]->m_DeptID << endl;
	//}

	//初始化属性
	//this->m_EmpNum = 0;
	//this->m_EmpArray = 0;
}

//统计文件中的人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //打开文件 读

	int id;
	string name;
	int dID;

	int num = 0; //文件中的人数

	while (ifs >> id && ifs >> name && ifs >> dID )  //右移运算符，读到空格，进入下一项的读取，直到读完三项，每读完一行数据，统计人数
	{
		num++;//统计人数变量
	}
	return num;   //返回文件中职工人数
};

//初始化职工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dID;

	int index = 0;   //职工数量索引

	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;
		if (dID == 1)      //普通职工
		{
			worker = new Employee(id, name, dID);
		}
		else if (dID == 2) //经理
		{
			worker = new Manager(id, name, dID); 
		}
		else if(dID == 3)             //老板
		{
			worker = new Boss(id, name, dID);
		}
		//else
		//{
		//	cout << "输入有误！" << endl;   break;   //输入1、2、3以外的数字报错
		//}
		this->m_EmpArray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();
}

//显示职工
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或纪录为空!" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}

//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)     //若文件位空，则没法儿删除
	{
		cout << "文件不存在或者纪录为空！" << endl;
	}
	else   //若文件不为空，则删除指定的职工
	{
		cout << "请输入想要删除职工的编号： " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id); //判断编号为id的职工是否存在，并存入index

		if (index != -1) //说明职工存在，并且要删除掉index位置上的职工
		{
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++)   //i<数组中最后一个位置，就是m_EmpNum-1
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;  //更新数组中纪录人员个数
			this->save();//数据同步更新到文件中
			cout << "删除成功!" << endl; 
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl; 
		}
	}
	system("pause");   //按任意键清屏
	system("cls");
}
//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;  //一开始认定，不存在员工
	for (int i = 0; i < this->m_EmpNum; i++)  //遍历数组
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			index = i;  //找到职工 
			break;
		}
	}
	return index;
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或纪录为空！" << endl; 
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到编号的职工
			delete this->m_EmpArray[ret];

			int newID = 0;    //修改后的新数据初始化
			string newName = " ";
			int dSelect = 0;    //部门ID

			cout << "查到： " << id << "号职工，请输入新职工号：" << endl;
			cin >> newID;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入新岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;    //部门变量

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:worker = new Employee(newID, newName, dSelect);  break;
			case 2:worker = new Manager(newID, newName, dSelect);   break;
			case 3:worker = new Boss(newID, newName, dSelect);      break;
			default: break;
			}

			//更新数据到数组中
			this->m_EmpArray[ret] = worker;   //将修改后的人员插入到数组中
			cout << "修改成功!" << this->m_EmpArray[ret]->m_DeptID << endl;
			this->save(); //保存到文件中
		}
		else
		{
			cout << "修改失败， 查无此人！" << endl; 
		}
	}
	system("pause"); //按任意键清屏
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者纪录为空!" << endl; 
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;
		int search_Mode = 0;    //查找方式
		while (1)
		{
			cin >> search_Mode;     //输入查找方式

			if (search_Mode == 1)  //按编号查找
			{
				int id;
				cout << "请输入要查找的职工编号：" << endl;
				cin >> id;

				int ret = IsExist(id);   //判断该编号是否存在
				if (ret != -1)
				{
					cout << "查找成功！ 该职工信息如下：" << endl;
					this->m_EmpArray[ret]->showInfo();
				}
				else
				{
					cout << "查找失败，查无此人！" << endl;
					cout << " " << endl; //分隔空行
				}
			}
			else if (search_Mode == 2)  //按名字查找
			{
				string name;
				cout << "请输入要查找的姓名：" << endl;
				cin >> name;

				bool name_searchflag = false; //查找到名字的标志，默认为false
				for (int i = 0; i < m_EmpNum; i++)
				{
					if (m_EmpArray[i]->m_Name == name)
					{
						cout << endl;  //分隔空行
						cout << "查找成功， 职工编号为：" << m_EmpArray[i]->m_ID << "号的信息如下：" << endl;

						name_searchflag = true;

						this->m_EmpArray[i]->showInfo();  //显示此人信息
					}
				}
				if (name_searchflag == false)
				{
					//查无此人
					cout << "查找失败，查无此人!" << endl;
				}
			}
			else
			{
				cout << "输入选项有误，请重新输入：" << endl;
			}
			if (search_Mode == 1 || search_Mode == 2)
			{
				break;
			}
		}
	}
	/*system("pause");
	system("cls");*/
}

//排序职工
void WorkerManager:: Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空！" << endl; 
		system("pause");
		system("cls");     
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl; 

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minormax = i;  //声明最小值 或 最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)   //升序
				{
					if (this->m_EmpArray[minormax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minormax = j;  //更新最小值下标
					}
				}
				else  //降序
				{
					if (this->m_EmpArray[minormax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minormax = j;  //更新最大值下标
					}
				}
			}
			//判断一开始认定 最小值或最大值，是不是计算的最小或最大值，如果不是，则交换数据
			if (i != minormax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minormax];
				this->m_EmpArray[minormax] = temp;
			}
		}
		cout << "排序成功，排序后的结果为：" << endl;
		this->save();  //排序后结果保存到文件中
		this->Show_Emp(); //展示所有职工
	}
}

//清空文件
void WorkerManager::Clean_file()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式， ios::trunc 如果存在，删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_FileIsEmpty != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)  //删除堆区的职工对象
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			//删除堆区数组指针
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true; 
		}
		cout << "清空成功！" << endl; 
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()   //堆区数据，手动开辟，手动释放
{
	if (this->m_EmpArray != NULL)
	{
		//delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//展示菜单,类内声明，类外定义
void WorkerManager::Show_Menu()
{
	cout << "*************************************************************" << endl;
	cout << "*******************欢饮使用职工管理系统！**********************" << endl;
	cout << "******************  0.退出管理程序  **************************" << endl;
	cout << "******************  1.增加职工信息  **************************" << endl;
	cout << "******************  2.显示职工信息  **************************" << endl;
	cout << "******************  3.删除离职职工  **************************" << endl;
	cout << "******************  4.修改职工信息  **************************" << endl;
	cout << "******************  5.查找职工信息  **************************" << endl;
	cout << "******************  6.按照编号排序  **************************" << endl;
	cout << "******************  7.清空所有文档  **************************" << endl;
	cout << "*************************************************************" << endl;
	cout << endl;
}

//退出接口，类外实现加作用域
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);  //退出程序
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量" << endl;

	int addNum = 0; //保存用户的输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum; //新空间人数 = 原来纪录人数 + 新增人数

		
		Worker **newSpace = new Worker* [newSize];//开辟新空间
		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name; //职工姓名
			int dSelect; //部门选择
			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			
			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:	worker = new Employee(id, name, 1); break; 
			case 2: worker = new Manager(id, name, 2); break; 
			case 3: worker = new Boss(id, name, 3); break;
			default: break;
			}
			//将创建职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;

		}
		delete[] this->m_EmpArray;//释放原有空间

		this->m_EmpArray = newSpace; //更新新空间的指向

		this->m_EmpNum = newSize; //更新新的员工人数

		this->m_FileIsEmpty = false; //更新职工不为空标志

		cout << "成功添加" << addNum << "名新职工" << endl; //提示添加成果

		this->save();//成功添加后，保存数据到文件中

	}
	else
	{
		cout << "输入数据有误！" << endl; 
	}
	//按任意键后清屏，回到上级目录
	system("pause");
	system("cls");
}
 


//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //用输出的方式打开文件  ----写文件

	//将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "  //利用空格分割属性
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	//关闭文件
	ofs.close();
}