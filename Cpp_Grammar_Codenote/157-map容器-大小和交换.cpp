/*
	统计map容器大小以及交换map容器

	函数原型：
	size();   //返回容器中元素的数目
	empty();  //判断容器是否为空
	swap();   //交换两个集合容器

*/
#include<iostream>
#include<map>
using namespace std;

void printMap157(map<int, string>& m)
{
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << "	value = " << it->second << endl;
	}
	cout << endl;
}

void test157()
{
	map<int, string>m1;
	//方式一：
	m1.insert(make_pair(1, "唐僧"));
	m1.insert(make_pair(3, "孙悟空"));
	m1.insert(make_pair(2, "猪八戒"));
	m1.insert(make_pair(5, "沙悟净"));
	m1.insert(make_pair(4, "白龙马"));
	//方式二：
	//m1.insert(pair<int, string>(1, "唐僧"));
	//m1.insert(pair<int, string>(3, "孙悟空"));
	//m1.insert(pair<int, string>(2, "猪八戒"));
	//m1.insert(pair<int, string>(5, "沙悟净"));
	//m1.insert(pair<int, string>(4, "白龙马"));

	if (!m1.empty())
	{		
		cout << "容器不为空" << endl; 
		cout << "容器中元素数目： " << m1.size() << endl;
	}
	else
	{
		cout << "容器为空" << endl; 
	}

	map<int, string>m2;
	m2.insert(make_pair(7, "白骨精"));
	m2.insert(make_pair(6, "琵琶精"));
	cout << "交换前：" << endl;
	printMap157(m1);
	printMap157(m2);

	cout << "交换后：" << endl;
	swap(m1, m2);
	printMap157(m1);
	printMap157(m2);

}

int main157()
{
	test157();
	system("pause");
	return 0;
}