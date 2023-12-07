/*
	求差集的两个集合必须是有序序列。
	目标容器开辟空间需要从两个容器取较大值。
	set_difference返回值即是差集中最后一个元素的位置

	函数原型:
	set_difference(Iterator begl, iterator endl, iterator beg2, iterator end2, iterator dest);
	//求两个集合的差集
	// 注意:两个集合必须是有序序列
	// beg1 容器1开始选代器
	// end1 容器1结束迭代器
	// beg2 容器2开始选代器
	// end2 容器2结束迭代器
	// dest 目标容器开始迭代器
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myprint189(int val)
{
	cout << val << " ";
}

void test189()
{
	vector<int>v1;
	vector<int>v2;                             
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	for_each(v1.begin(), v1.end(), myprint189);
	cout << endl; 
	for_each(v2.begin(), v2.end(), myprint189);

	//创建目标容器，并开辟空间
	//最特殊情况，两个容器没有并集，取两个容器中大的size作为目标容器的开辟空间
	vector<int>vtarget;
	vtarget.resize(max(v1.size(), v2.size()));
	cout << endl; 
	cout << "v1和v2的差集为：" << endl; 
	vector<int>::iterator itEnd;
	itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), itEnd, myprint189);   //注意 此处是返回的itEnd迭代器
}

int main189()
{
	test189();
	system("pause");
	return 0;
}
