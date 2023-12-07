/*
		学习目标:掌握常用的排序算法
	
		算法简介 :
		
		sort			//对容器内元素进行排序
		random_shuffle	//洗 指定范围内的元素机调整次序
		merge			// 容器元素合并，并存储到另一容器中
		reverse			// 反转指定范国的元素
		
	
		功能描述 :对容器内元素进行排序
		函数原型 :
		sort(iterator beg, iterator end, Pred);
		// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
		// beg 开始选代器
		//_Pred 谓词
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

void printVector177(vector<int> &v)
{
	for (auto const& it : v)
	{
		cout << it << " ";
	}
	cout << endl; 
}
void myprint177(int val)
{
	cout << val << " ";
}
//常用排序算法 sort
void test177()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	cout << "排序前：" << endl;
	printVector177(v);

	cout << "排序后: " << endl;
	sort(v.begin(), v.end());

	for_each(v.begin(), v.end(), myprint177); //遍历方法
	//printVector177(v);
	cout << endl;
	//改变为降序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myprint177); //遍历方法

}

int main177()
{
	test177();
	system("pause");
	return 0;
}