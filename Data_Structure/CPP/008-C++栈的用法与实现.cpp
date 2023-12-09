/*
首先看一下原c++栈的方法的基本用法：
push(): 向栈内压入一个成员；
pop(): 从栈顶弹出一个成员；
empty(): 如果栈为空返回true，否则返回false；
top(): 返回栈顶，但不删除成员；
size(): 返回栈内元素的大小；

*/
#if 0
#include<iostream>
#include<stack>

using namespace std; 

int main()
{
	stack<int>stk;
	//入栈
	for (int i = 0; i < 50; i++)
	{
		stk.push(i);
	}
	cout << "栈的大小为：" << stk.size() << endl;
	while (!stk.empty())
	{
		cout << stk.top() << endl;   //若栈不为空，持续输出栈顶元素
		stk.pop();    //删除栈顶元素
	}
	cout << "栈的大小：" << stk.size() << endl; 
	return 0;
}
#endif

#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 0fff;

#if 0
template <class type>
class mystack
{
	//int top;
	type* top;
	int maxsize;
public:
	mystack() : top(-1), maxsize(MAXSIZE) {}
	{
		top = new type(maxsize);
		if (top == NULL)
		{
			cout << "动态存储分配失败！" << endl; 
		}
	}

	mystack(int size) : top(-1), maxsize(size)
	{
		top = new type(maxsize);
		if (top = NULL)
		{
			cout << "动态存储分配失败！" << endl;
			exit(1);
		}
	}
	~mystack()
	{
		delete[] top; 
	}
	//是否为空
	bool Empty();
	//压栈
	void Push(type tp);
	//返回栈顶元素
	type Top();
	//出栈
	void Pop();
	//栈太小
	int Size();

};

#endif