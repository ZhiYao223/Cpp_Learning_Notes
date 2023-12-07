/*
	对set容器进行查找数据及统计数据

	函数原型：
	find(key);  //查找key是否存在，若存在返回该键的元素的迭代器，否则，返回set.end();
	count(key);  //统计key的元素个数   统计结果无非是0或1 因为set型不能插入重复元素

	
*/
//查找和统计
#include <iostream>
#include<set>
using namespace std; 

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl; 
}
void test151_1()
{
	//查找
	set<int> s1;
	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	int elem = 30;
	set<int>::iterator pos = s1.find(elem); 
	if (pos != s1.end())  //若返回的位置不指向end(),说明找到了元素
	{
		cout << "找到元素:" << *pos << endl;    //输出返回地址所存的元素数据
	}
	else
	{
		cout << "未找到元素！" << endl; 
	}

}
void test151_2()
{
	//查找
	set<int> s1;
	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	s1.insert(30);
	//统计30的个数
	int num = s1.count(30);
	cout << "num = " << num << endl;   // 虽然有3个30，但set不能插入相同元素，所以最后输出num还是1
}

int main151()
{
	test151_1();
	test151_2();
	system("pause");
	return 0;
}