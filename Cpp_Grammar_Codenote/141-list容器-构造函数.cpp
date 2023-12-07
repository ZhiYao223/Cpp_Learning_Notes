/*
	功能描述：创建list容器
	 
	函数原型：
	list<T> lst;   //list采用模板类实现，对象的默认构造函数形式
	list(beg,end);  //构造函数将[beg,end）区间中的元素拷贝给本身
	list(n, elem); //构造函数将n个elem拷贝给本身
	list(const list &lst);  //拷贝构造函数
	
	list同其他容器构造方式基本一样，熟练使用即可

*/
#include<iostream>
#include <vector>
#include <list>
using namespace std; 

void printList141(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//for (size_t i = 0; i < L.size(); i++)
	//{
	//	cout << L[i] << " ";
	//}
} 

void test141()
{
	//创建list容器；
	list<int>L1;  //默认构造
	//添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	//遍历容器
	printList141(L1);

	//区间方式构造
	list<int>L2(L1.begin(), L1.end());
	printList141(L2);

	list<int>L3(L2);
	printList141(L3);

	list<int>L4(10, 1000);
	printList141(L4);
}

int main141()
{
	test141();
	system("pause");
	return 0;
}















