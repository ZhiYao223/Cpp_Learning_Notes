/*
	功能描述： 搬运容器到另一个容器

	函数原型：
	transform(iterator beg1, iterator end1, iterator  beg2, _func);
	beg1  原容器开始迭代器
	end1 源容器结束迭代器
	beg2 目标容器开始迭代器
	_func函数或者函数对象
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Transform
{
public:
	//仿函数是一种将对象当作函数使用的机制，它允许对象像函数一样进行调用
	//定义了一个名为 operator() 的函数，接收一个 int 类型的参数 v，并返回相同的值 v。仿函数可以像函数一样被调用，它的调用方式类似于函数调
	//调用方式，例如int value = operator()(10);这样会将参数 10 传递给仿函数的 operator() 函数，并返回相同的值 10 。
	int operator()(int v)   // 定义了一个仿函数，并重载了函数调用运算符 operator()
	{
		return v+10; 
	}
};

class print170
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
//常用遍历算法 transform 
void test170()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << endl;
	//目标容器
	vector<int>vTarget;   //没有提前给给vTarget容器开辟空间，会报错
	vTarget.resize(v.size());//给新容器开辟原容器一样大小的空间

	transform(v.begin(), v.end(), vTarget.begin(), Transform());   //传入匿名函数对象

	for_each(vTarget.begin(), vTarget.end(), print170());  //仿函数传入，需带()
}

int main170()
{
	test170();
	system("pause");
	return 0;
}
   

