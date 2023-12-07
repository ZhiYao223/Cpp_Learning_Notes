/*
	功能描述： 统计set容器大小以及交换set容器

	函数原型：
	size();  //返回容器中元素的数目
	empty(); //判断容器是否为空
	swap(st); //交换两个集合容器
*/

#include<set>
#include<iostream>
using namespace std;

void printSet149(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl; 
}

//大小
void test149_1()
{
	set<int> s1;
	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	//打印容器
	printSet149(s1);
	//判断是否为空
	if (s1.empty())
	{
		cout << "s1为空！" << endl; 
	}
	else
	{
		cout << "s1不为空" << endl; 
		cout << "s1的大小为： " << s1.size() << endl;
	}

}

//交换
void test149_2()
{
	set<int> s1;
	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int> s2;
	//插入数据
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	cout << "交换前：" << endl;
	printSet149(s1);
	printSet149(s2);

	cout << endl << "交换后：" << endl; 
	s1.swap(s2);
	printSet149(s1);
	printSet149(s2); 

}

int main149()
{
	test149_1();
	test149_2();
	system("pause");
	return 0;
}