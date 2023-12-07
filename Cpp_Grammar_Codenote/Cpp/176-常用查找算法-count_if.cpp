/*
	功能描述:
	按条件统计元素个数
	函数原型:
	count_if(iterator beg, iterator end, _Pred);
	// 按条件统计元素出现次数
	//beg 开始选代器
	//end 结束选代器
	//_Pred谓词
I
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator()(const Person& p)
	{
		return  p.m_Age > 20;
	}
	string m_Name;
	int m_Age;
};
class AgeGreater40
{
public:
	bool operator()(const Person& p)
	{
		return p.m_Age > 40; 
	}
};

class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};
//条件计数

void test176_1()
{
	vector<int>v;
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);

	int num = count_if(v.begin(), v.end(), Greater20());
	cout << "大于20的元素个数：" << num << endl;
}
//自定义数据类型
void test176_2()
{
	vector<Person>v;
	Person p1("刘备", 45);
	Person p2("张飞", 35);
	Person p3("刘备", 40);
	Person p4("刘备", 45);
	Person p5("赵云", 35);
	Person p6("诸葛亮", 50);

	//将人员插入容器中
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	//统计大于20岁人员个数
	int num = count_if(v.begin(), v.end(), AgeGreater40());  //传入谓词， 返回布尔类型
	cout << "年龄大于40的元素个数：" << num << endl;
}


int main176()
{
	test176_1();
	test176_2();
	system("pause");
	return 0;
}