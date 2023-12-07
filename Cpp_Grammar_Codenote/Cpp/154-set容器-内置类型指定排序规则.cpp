/*
	学习目标： set容器默认排序规则为从小到大，掌握如何改变排序规则

	 利用仿函数，可以改变排序规则
*/
//示例1 set存放内置数据类型
#include<iostream>
#include<set>
using namespace std; 

//利用仿函数，改成从大到小
class Mycompare   //仿函数Mycompare本质是一个数据类型
{
public:     //函数重载
	bool operator() (int v1,int v2) const //operator()是一个函数 
	{
		return v1 > v2; 
	}
};

//set容器排序
void test154()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(50);
	s1.insert(30);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则为从大到小
	set<int, Mycompare> s2;  //创建容器，

	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(50);
	s2.insert(30);

	for (set<int, Mycompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main154()
{
	Mycompare p;   //operator()操作符重载，当Mycompare创建一个实例对象p时
				   //p(12,34)会调用Mycompare类中的重载函数进行比较,即operator()()
	int num = p(42, 34);  //返回布尔类型
	cout << "num = " << num << endl;

	test154();
	system("pause");
	return 0;
}

