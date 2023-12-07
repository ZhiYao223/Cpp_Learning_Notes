/*
	学习目标：  map容器默认排序规则为按照key值从小到大排序，掌握如何改变排序规则
	主要技术要点： 利用仿函数，可以改变排序规则

	总结：
	利用仿函数可以指定map容器的排序规则
	对于自定义数据类型， map必须要指定排序规则， 同set容器
*/

#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

class MyCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

void printmap160(map<int, int,  MyCompare>& m)
{
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << "	value = " << (*it).second << endl;
	}
	cout << endl;
}

void test160()
{
	//默认从小到大排序，利用仿函数实现从大到小排序
	map<int, int, MyCompare>m;  //按从大到小排序
	m.insert(make_pair(1, 20));
	m.insert(make_pair(2, 10));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));

	printmap160(m);



}
int main160()
{
	test160();
	system("pause");
	return 0;
}

