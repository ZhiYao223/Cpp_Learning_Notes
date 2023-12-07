/*
	学习目标:
		掌握常用的持贝和替换算法
		算法简介:
		copy		// 客器内指定范围的元素拷贝到另一容器中
		replace		// 将容器内指定范围的元素修改为新元素
		replace_if	// 容器内指定范围满足条件的元素警换为新元素
		Swap		// 互换两个容器的元素

		Copy功能描述:
		容器内指定范围的元素拷贝到另一容器中

		函数原型:
		copy(iterator beg, iterator end, iterator dest);
		// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
		//利用copy算法在拷贝时，目标容器记得提前开辟空间
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

void myprint(int val)
{
	cout << val << " ";
}
//常用拷贝和替换算法copy
void test181()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), myprint);

}

int main181()
{
	test181();
	system("pause");
	return 0;
}