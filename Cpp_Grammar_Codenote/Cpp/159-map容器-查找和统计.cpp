/*
	功能描述： 对map容器进行查找数据以及统计数据
	函数原型：
	find(key);    //查找key是否存在，若存在，返回该键的元素的迭代器； 若不存在，返回map.end();
	count(key);   //统计key的元素个数

	总结: 查找----find返回的是迭代器  统计-----count (对于map,结果为0或1）
*/
#include<iostream>
#include<map>
using namespace std; 

void printMap159(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << "	value = " << (*it).second << endl; 
	}
	cout << endl; 
}

void test159()
{
	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 30));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 20));
	m.insert(make_pair(4, 50));  //插不进去，map不允许插入重复的key元素

	map<int, int>::iterator pos = m.find(3); //查找key值为3的元素，并返回该元素的迭代器 用pos接收
	if (pos != m.end())
	{
		cout << "找到key值为3的元素：" << (*pos).second << endl; 
	}
	else
	{
		cout << "未找到元素" << endl; 
	}
	printMap159(m);
	//统计
	//map不允许插入重复key元素，count统计而言，结果要么是0要么是1
	//multimap的count统计可能大于1
	int num = m.count(3); //查找key值为3的元素个数
	cout << "num = " << num << endl; 
}

int main159()
{
	test159();
	system("pause");
	return 0;
}