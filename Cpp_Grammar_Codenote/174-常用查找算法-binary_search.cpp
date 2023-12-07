/*
	功能描述：查找指定  元素是否存在

	函数原型:
	bool binary_search(iterator beg, iterator end, value);
	// 查找指定的元素，查到 返回true 否则false
	// 注意 在无序序列中不可用
	// beg 开始选代器
	// end 结束迭代器
	// value 查找的元素

	注意： 二分法查找，容器必须是有序的序列，且为升序
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//常用查找算法  binary_search
void test174()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << endl; 
	//v.push_back(2); 如果是无序的，结果位置
	//查找容器中是否有9元素
	bool ret = binary_search(v.begin(), v.end(), 9); //头尾迭代器， 查找元素
	if (ret)
	{
		cout << "找到了元素" << endl;
	}
	else
	{
		cout << "没有找到元素" << endl; 
	}
}




int main174()
{
	test174();
	system("pause");
	return 0;
}