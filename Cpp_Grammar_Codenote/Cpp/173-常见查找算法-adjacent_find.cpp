/*
 adjacent_find
功能描述:
查找相邻重复元素

函数原型:

adjacent_find(iterator beg,iterator end);  

// 查找相邻重复元素,返回相邻元素的第一个位置的选代器
// beg 开始迭代器
// end 结束迭代器
如果面试题中出现查找相邻重复元素，记得用STL中的adjacent_find算法
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


void test173_1()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);  //相邻的重复元素
	v.push_back(3);
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到：" << *pos << endl;  
	}
	cout << endl; 
}
int main173()
{
	test173_1();
	system("pause");
	return 0;
}