/*
	学习目标:
	掌握常用的算术生成算法注意:
	算术生成算法属于小型算法，使用时包含的头文件为 #inciude <numeric>
	
	算法简介:
	accumulate		//计算容元素累计总和accumulate   
	fill			// 向容器中添加元素
	
	accumulate:
	功能描述：计算区间内容器元素累计总和


	函数原型:
	accumulate(iterator beg, iterator end, value); // 计算容器元素累计总和
	// beg 开始选代器
	// end 结束选代器
	// value 起始值
*/
#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

void test185()
{
	vector<int>v1;
	for (int i = 0; i <= 100; i++)
	{
		v1.push_back(i);
	}
	//参数3 起始累加值
	int total = accumulate(v1.begin(), v1.end(), 0); 
	cout << "total = " << total << endl; 

}
int main185()
{
	test185();
	system("pause");
	return 0;
}
