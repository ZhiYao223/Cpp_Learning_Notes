/*
	函数原型:
	count(iterator beg, iterator end, value);
	// 统计元素出现次数
	// beg 开始迭代器
	// end 结束迭代器
	// value 统计的元素
*/
#include<iostream>
#include<vector>
using namespace  std;

//1.统计内置数据类型
void test175_1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);
	v.push_back(50);
	v.push_back(60);
	v.push_back(60);
	v.push_back(70);
	v.push_back(90);
	v.push_back(10);
	
	int elem = 40;
	int num = count(v.begin(), v.end(), 40);
	cout << "元素" << elem << "的个数为：" << num << endl; 

}

//2.统计自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age; 
	}
	bool operator==(const Person& p)  //重载== 让底层知道如何对比
	{
		if (this->m_Age == p.m_Age)
		{
			return true; 
		}
		else
		{
			return false;
		}
	}

	string m_Name;
	int m_Age;
};

void test175_2()
{
	vector<Person>v;
	Person p1("刘备", 40);
	Person p2("张飞", 35);
	Person p3("刘备", 40);
	Person p4("刘备", 40);
	Person p5("赵云", 35);
	Person p6("诸葛亮", 35);

	//将人员插入容器中
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	int num = count(v.begin(), v.end(), p3);       //计算容器中p3元素

	cout << "和" << p3.m_Name << "同岁数的人员个数：" << num << endl; 

}
int main175()
{
	test175_1();
	test175_2();
	system("pause");
	return 0;
}