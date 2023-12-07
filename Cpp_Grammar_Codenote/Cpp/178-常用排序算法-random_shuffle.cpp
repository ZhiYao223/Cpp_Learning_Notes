/*
	功能描述:
	洗牌 指定范园内的元素随机调整次序
	函数原型:
	random_shuffle(iterator be8, iterator end);
	// 指定范围内的元素机调整次序
	// beg 开始迭代器
	// end 结束迭代器
	总结： random_shuffle 洗牌算法比较实用，使用时记得加随机数种子
*/
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;


void myprint178(int val)
{
	cout << val << " ";
}

void test178()
{
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myprint178);  //
	cout << endl; 

	//打乱顺序
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myprint178);
	cout << endl; 
}
int main178()
{
	//随机数种子
	//将当前时间作为种子来初始化随机数生成器，以确保每次程序运行时生成的随机数序列都是不同的。
	srand((unsigned int)time(NULL));  //
	test178(); 
	system("pause");
	return 0;
}




