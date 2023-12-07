/*
	功能描述:
	将区间内满足条件的元素，替换成指定元素
	函数原型:
	replace_if(iterator beg, iterator end, _pred, newvalue);
	// 按条件替换元素，满足条件的替换成指定元素
	// beg 开始迭代器
	// end 结束迭代器
	// _pred 谓词
	// newvalue 新换的新元素
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;


class Myprint183     //仿函数
{
public:
	void operator()(int val)  
	{
		cout << val <<" ";
	}
};
class Greater30    
{
public:
	bool operator()(int val)  
	{
		return val >= 30;
	}
};
void test183()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(60);
	v.push_back(50);
	v.push_back(20);
	v.push_back(10);
	v.push_back(30);
	cout << "替换前：";
	for_each(v.begin(), v.end(), Myprint183());
	cout << endl;
	//将大于等于30的元素替换为0
	cout << "替换后：";
	replace_if(v.begin(), v.end(), Greater30(), 0);
	for_each(v.begin(), v.end(), Myprint183());
}

int main183()
{
	test183();
	system("pause");
	return 0;
}