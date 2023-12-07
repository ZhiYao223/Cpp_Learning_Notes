/*
		案例描述：

		有5名选手: 选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分

		实现步骤
		1.创建五名选手，放到vector中
		2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
		3.sort算法对deque容器中分数排序，去除最高和最低分
		4.deque容器遍历一遍，累加总分
		5.获取平均分
*/
#if 1
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

//选手类
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;
	int m_Score;

};

void creatPerson(vector<Person>& v)
{
	string nameSeed[] = { "A", "B", "C","D","E" };
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";  //string 拼接
		name += nameSeed[i];
		cout << name << endl;

		int score = 0; //初始化分数
		//将创建的Person对象放入容器中
		Person p(name, score);
		v.push_back(p);
	}
	cout << endl;
}
//打分
void setScore(vector<Person>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		//将评委的分数，放入到deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;  //0~100
			d.push_back(score);
		}

		cout << "选手：" << v[i].m_Name << "打分：";
		for (auto const& it : d)
		{
			cout << it << " ";
		}
		cout << endl;

		//排序
		sort(d.begin(), d.end());
		//去除最高分和最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (auto const& it : d)
		{
			sum += it; //累加每个评委的分数
		}
		int avg = sum / d.size();  //平均分
		//将平均分 赋值给选手身上
		v[i].m_Score = avg;
	}
	cout << endl; 

}

void showScore(vector<Person>& v)
{
	for (auto const& it : v)
	{
		cout << "姓名：" << it.m_Name << "平均分: " << it.m_Score << endl;
	}
	cout << endl; 
}


int main137()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	//创建5名选手
	vector<Person>v;  //存放选手的容器     
	creatPerson(v);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "分数：" << (*it).m_Score << endl;

	}
	cout << endl;


	//给5名选手打分
	setScore(v);


	//显示最后得分
	showScore(v);


	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
#include<algorithm>
#include<deque>
#include<vector>
#include<ctime>

using namespace std;

class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score; 
	}
	string m_Name;
	int m_Score;
};

void creatPerson(vector<Person>& v )
{
	string nameSeed[] = { "张三", "李四", "王五", "赵六", "宋七" };
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name = name + nameSeed[i];
		cout << name << endl;
		int score = 0;    //分数默认为0
		Person p(name, score);  //创建选手对象p

		v.push_back(p);  //将姓名分数传入对象p，再将p放入容器v
	}
}

//评委打分
void setScore(vector<Person>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		//将评委的分数，放入deque容器里
		deque<Person> d1;
		for (int i = 0; i < 10; i++)
		{
			v[i].m_Score = rand() % 41 + 60;
			cout << v[i].m_Score << " ";
		}

		sort(d1.begin(), d1.end());
		d1.pop_back();
		d1.pop_front();

		int num = 0;
		for (size_t i = 0; i < d1.size(); i++)
		{
			int num = num + d1[i].m_Score;
		}
		//平均值
		int average = num % d1.size();
		cout << endl;

		for (int i = 0; i < d1.size(); i++)
		{
			cout << d1[i].m_Name << "平均分为： " << d1[i].m_Score << endl;
		}
		cout << endl;
	}

}


int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	
	//创建五名选手，放到vector中
	vector<Person> player;
	creatPerson(player);
	
	//10个评委，分别给每个选手打分
	//setScore(player);

	//求平均值
	//averageScore(player);
	
	system("pause");
	return 0;
	
	
}
#endif