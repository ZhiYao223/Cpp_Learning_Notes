/*
	函数原型:
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的并集
// 注意:两个集合必须是有序序列
// beg1 容器1开始选代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2容器2结束迭代器
// dest 目标容器开始迭代器
	总结:
	求并集的两个集合必须的有序序列。
	目标容器开辟空间需要两个容器相加
	set_union返回值既是并集中最后一个元素的位置
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myprint188(int val)
{
	cout << val << " ";
}

void test188()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	cout << "合并前：" << endl; 
	for_each(v1.begin(), v1.end(), myprint188);//0 1 2 3 4 5 6 7 8 9
	cout << endl;
	for_each(v2.begin(), v2.end(), myprint188);//5 6 7 8 9 10 11 12 13 14

	cout << "合并后：" << endl; 
	vector<int>vtarget; //目标容器
	//最特殊情况，两个容器没有交集， 并集就是两个容器size相加
	vtarget.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd;
	itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myprint188);//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 0 0 0 0 0
	//for_each(vtarget.begin(), itEnd, myprint188);//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14

}
int main188()
{
	test188();
	system("pause");
	return 0;
}

