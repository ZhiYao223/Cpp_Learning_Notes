/*

	返回bool类型的仿函数称为谓词
	如果operator()接受一个参数，那么叫做于元谓词。
	如果operator()接受两个参数，那么叫做二元谓词

	//仿函数 返回值类型是bool数据类型 ，称为谓词
	//一元谓词
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class LargeFive
{
public:    
	bool operator()(int val)  
	{
		return val > 5; 
	}
};
void test164()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);   //插入数据
	}
	//查找容器中，有没有大于5的数字   LargeFive()匿名的函数对象
	vector<int>::iterator it;
	it = find_if(v.begin(), v.end(), LargeFive());   //返回元素地址处的迭代器
	if (it == v.end())
	{
		cout << "未找到" << endl; 
	}
	else
	{
		cout << "找到了大于5的数字为：" << *it << endl; 
	}


}