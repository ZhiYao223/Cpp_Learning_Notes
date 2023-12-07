/*
	学习目标：set容器默认排序规则为从小到大，掌握如何改变排序规则

	对于自定义数据类型，  set必须指定排序规则才可以插入数据
*/
//示例2 set存放自定义数据类型

#include<iostream>
#include<set>
using namespace std;

#if 0
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age; 
	}
public:
	string m_Name;
	int m_Age;
};

class ComparePerson
{
public:
	bool operator() (const Person &p1,const Person &p2) const
	{
		//按照年龄排列
		return p1.m_Age > p2.m_Age;   
	}
};
void test155()
{
	//自定义数据类型， 都会指定排序规则
	set<Person, ComparePerson> s;
	
	//插入数据方式一
	//Person p1("刘备", 45);
	//Person p2("张飞", 43);
	//Person p3("关羽", 40);
	//Person p4("赵云", 35);
	//s.insert(p1);
	//s.insert(p2);
	//s.insert(p3);
	//s.insert(p4);
	
	//插入数据方式二
	s.insert({ "刘备", 45 });
	s.insert({ "张飞", 43 });
	s.insert({ "关羽", 40 });
	s.insert({ "赵云", 35 });

	for (set<Person, ComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名: " << it->m_Name << "年龄: " << it->m_Age << endl; 
	}
}

int main155()
{
	test155();
	system("pause");
	return 0;
}
#endif




