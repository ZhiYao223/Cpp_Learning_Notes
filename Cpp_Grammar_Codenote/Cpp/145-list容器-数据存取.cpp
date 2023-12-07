/*
	功能描述：	对list容器中数据进行存取
	函数原型：
	front();  //返回第一个元素
	back();   //返回最后一个元素
	
*/

#include<list>
#include<iostream>
using namespace std;

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl; 
}
//list容器 数据存取
void test145()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);

	//L[0] 不能用[]访问list容器中的
	//L.at(0）不可以用at方式list容器中的元素
	//原因：list本质是链表，不是用连续线性空间存储数据，迭代器也不支持随机访问
	cout << "第一个元素：" << L.front() << endl;
	cout << "最后一个元素：" << L.back() << endl; 

	//验证迭代器不支持随机访问
	list<int>::iterator it = L.begin();
	it++;    //支持双向
	it--;    //
	//it = it + 1; 不支持随机访问，只支持it++ 和--。  
}


int main145()
{
	test145();
	system("pause");
	return 0;
}