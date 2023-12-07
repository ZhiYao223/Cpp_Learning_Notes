/*
	学习目标：掌握常用集合算法

	算法简介：
	set_nitersection  //求两个容器的交集
	set_union //求两个容器的并集
	set_difference//求两个容器的差集

	求交集的两个集合必须是有序序列

	求交集的两个集合必须的有序序列
	目标容器开辟空间需要从两个容器中取小值。
	setintersection返因值既是交集中是后一个元亲的位置
*/
#include<iostream>
#include<vector>
#include<algorithm>
//#include<functional>
using namespace std;

void myprint187(int val)
{
	cout << val << " ";
}

void test187()
{
	vector<int>v1;
	vector<int>v2;				
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	for_each(v1.begin(), v1.end(), myprint187);//0 1 2 3 4 5 6 7 8 9
	cout << endl; 
	for_each(v2.begin(), v2.end(), myprint187);//5 6 7 8 9 10 11 12 13 14
	cout << endl; 

	vector<int>vtarget;
	//目标容器需要提前开辟空间
	//最特殊情况，大容器包含小容器， 开辟空间取最小容器的size即可
	vtarget.resize(min(v1.size(), v2.size()));
	cout << endl;
	//获取交集
	vector<int>::iterator itEnd;
	itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());

	for_each(vtarget.begin(), vtarget.end(), myprint187);//5 6 7 8 9 0 0 0 0 0
	cout << endl;
	//如果用vtarget.end()迭代器，交集多余的空间会被补零。 所以用itEnd迭代器
	for_each(vtarget.begin(), itEnd, myprint187);  //5 6 7 8 9


}
int main187()
{
	test187();
	system("pause");
	return 0;
}