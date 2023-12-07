/*
函数原型:
at(int idx);//返回索引idx所指的数据
operator[];//返回索引idx所指的数据
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素

总结：
除了用叠加器获取vector中的元素 [] 和 at也可以
front返回容器第一个元素 back返回容器最后一个元素
*/
#include<iostream>
#include<vector>
using namespace std;


void test128()
{
	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//利用[]方式访问数组中元素
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl; 

	//利用at方式访问元素
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//获取第一个元素
	cout << "第一个元素为： " << v1.front() << endl;

	//获取最后一个元素
	cout << "最后一个元素为：" << v1.back(); 
}

int main128()
{
	test128();
	system("pause");
	return 0;
}