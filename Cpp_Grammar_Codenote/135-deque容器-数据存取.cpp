/*
	功能描述：
	对deque中的数据的存取操作
	函数原型:
			at(int idx);//返回索引idx所指的数据
			operator[];//返回索引idx所指的数据
			front();//返回容器中第一个数据元素
			back();//返回容器中最后一个数据元素

*/
#include<iostream>
#include<deque>
using namespace std;

//deque数据存取操作
void test135_1()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	//通过[]的方式访问元素
	//300 200 100 10 20 30
	for (size_t i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl; 

	//通过at方式访问元素
	for (size_t i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl; 
	
	cout << "第一个元素为： " << d.front() << endl;
	cout << "最后一个元素为："<< d.back() << endl; 
}
int main135()
{
	test135_1();
	system("pause");
	return 0;
}