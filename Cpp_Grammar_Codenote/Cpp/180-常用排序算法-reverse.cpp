/*
	功能描述：将容器内元素进行反转
	函数原型：
	reverse(iterator beg, iterator end);
	//反转指定范围的元素
	//beg开始迭代器
	//end结束迭代器

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test180()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << endl; 
	random_shuffle(v.begin(), v.end());  //打乱排序
	cout << "反转前：";
	for_each(v.begin(), v.end(), myprint());
	cout << endl; 


	cout << "反转后：";
	reverse(v.begin(), v.end());           //序列排序颠倒
	for_each(v.begin(), v.end(), myprint());   
	cout << endl;
}
int main180()
{
	test180();
	system("pause");
	return 0;
}

