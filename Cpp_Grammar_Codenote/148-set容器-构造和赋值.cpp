/*
	set/multiset容器
	简介：所有元素都会在插入时自动被排序

	本质：set/multiset属于关联式容器，底层结构是用二叉树实现

	set和multiset区别：
	set不允许容器内有重复的元素
	multiset允许容器中有重复的元素

	set构造和赋值
	功能描述：创建set容器以及赋值

	构造：
	set<T>st;							//默认构造函数
	set(const set &st);					//重载等号操作符
	set& operator= (const set &stt);	//重载操作符号操作符
*/

#include<set>
#include<iostream>
#include<string>
using namespace std;

//set容器构造和赋值
void printSet148(set<int>& st)
{
	for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it  << " ";
	}
	cout << endl; 
}

void printMultiset148(multiset<int>& st)
{
	for (multiset<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl; 
}

void test148()
{
	//插入数据，只有insert方式
	set<int> s1;     //无序序列
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);

	
	//遍历容器 
	//set容器特点，所有元素插入时自动排序
	//set容器不允许插入重复值
	printSet148(s1);

	//拷贝构造
	set<int>s2(s1);
	printSet148(s1);

	multiset<int>s3;
	s3.insert(10);
	s3.insert(40);
	s3.insert(30);
	s3.insert(20);
	s3.insert(30);
	printMultiset148(s3);
}

int main148()
{
	test148();        
	system("pause");
	return 0;
}