/*
	功能描述:
		按条件查找元素
	函数原型:
	find_if(iterator beg,iterator end,_pred);	// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
	// beg 开始选代器
	// end 结束迭代器
	//_Pred 函数或者谓词(返回bool类型的仿函数)
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//常用的查找算法 find_if 条件查找
// 
//1.查找内置数据类型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test172_1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << endl; 
	vector<int>::iterator it;
    it = find_if(v.begin(), v.end(), GreaterFive());   //容器首、尾迭代器 谓词
	if (it == v.end())
	{
		cout << "没找到" << endl; 
	}
	else
	{
		cout << "找到大于5的数字为：" << *it << endl; 
	}
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age; 
	}

	string m_Name;
	int m_Age;
};
class Greater20
{
public:
	bool operator()(Person& p)
	{
		return p.m_Age > 20;
	}
};
//2.查找自定义数据类型
void test172_2()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());//利用迭代器接收返回的结果  
	if (it == v.end())
	{
		cout << "未找到" << endl; 
	}
	else
	{
		cout << "已找到 姓名：" << (*it).m_Name<<"年龄："<<(*it).m_Age << endl;
	}

	
}
int main172()
{
	test172_1();
	test172_2();   
	system("pause");
	return 0;
}