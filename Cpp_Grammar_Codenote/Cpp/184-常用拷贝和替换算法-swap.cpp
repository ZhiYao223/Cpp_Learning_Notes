/*
	功能描述：互换两个容器的元素
	函数原型：swap(container c1, container c2);
	//互换两个容器的元素
	//注意事项： swap交换容器时，注意交换的容器要同种类型
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test184()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
	}
	cout <<"交换前："<< endl;
	for_each(v1.begin(), v1.end(), myprint());
	cout << endl; 
	for_each(v2.begin(), v2.end(), myprint());
	cout << endl;
	swap(v1, v2);
	cout << "交换后："<<endl;
	for_each(v1.begin(), v1.end(), myprint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myprint());
}

int main184()
{
	test184();
	system("pause");
	return 0;
}