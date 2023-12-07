/*
	功能描述：将容器内指定范围的旧元素修改为新元素
	函数原型:
	replace(iterator feg, iterator end, oldvalue, newvalue);

	//将区间内日元素馨换成新元素
	// beg 开始选代器
	// end 结束选代器
	// oldvalue 旧元素
	// newvalue 新元素
*/
#include<iostream>
#include<algorithm>
using namespace std;
#include <vector>
//常用拷贝和替换算法 replace

class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test182()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	cout << "替换前：";
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
	replace(v.begin(), v.end(), 20, 2000); //将20全部替换成2000

	cout << "替换后：";
	for_each(v.begin(), v.end(), myprint());

}
int main182()
{
	test182();
	system("pause");
	return 0;
}