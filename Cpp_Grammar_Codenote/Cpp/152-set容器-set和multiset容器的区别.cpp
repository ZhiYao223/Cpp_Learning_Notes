/*
	//学习目标：掌握set和multiset的区别

	区别：set不可以插入重复数据，而multiset可以
	set插入数据的同时会返回插入结果，表示插入是否成功
	multiset不会检测数据，因此可以插入重复数据

	总结： 如果不允许插入重复数据可以利用set 
		  如果需要插入重复数据利用multiset 
*/
#include<set>
#include<iostream>
using namespace std;

//set容器
void test152()
{
	set<int>s;
	pair<set<int>::iterator, bool> ret = s.insert(10); //判断插入是否成功  插入后返回值ret为bool类型
	if (ret.second)  //ret.second表示pair对组的第二个数据即bool类型数据
	{
		cout << "第一次插入成功！" << endl;
	}
	else
	{
		cout << "第一次插入不成功！" << endl; 
	}


	ret = s.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功！" << endl; 
	}
	else
	{
		cout << "第二次插入失败！" << endl; 
	}

	//multiset 
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl; 
}
int main152()
{
	test152();
	system("pause");
	return 0;
}
