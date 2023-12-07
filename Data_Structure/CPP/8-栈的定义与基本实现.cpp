#include<iostream>
#include<vector>
using namespace std;

typedef int SElemType;   //SElemType类型根据实际情况而定，这里假设为int

class ArrayStack
{
private:
	static const int MAX_SIZE = 100; //栈的最大容量
	int data[MAX_SIZE];   //用数组存储栈元素
	int top;		//栈顶指针

public:
	ArrayStack(): top(-1) {}    //构造函数
	//进栈操作
	void push(int x)
	{
		if (top < MAX_SIZE - 1)
		{
			data[++top] = x;
		}
		else
		{
			std::cout << "Stack overflow!" << std::endl; 
		}
	}
};

//使用vector容器实现栈的进栈操作
class VectorStack
{
private:
	vector<int> data;   //使用vector存储栈元素

public:
	//入栈操作
	void push(int x)
	{
		data.push_back(x);  //将元素加入vector的末尾
	}
};

//使用自定义链表实现栈的进栈操作
class Node
{
public:
	int data;
	Node* next;
	Node(int value): data(value), next(nullptr)  {}
};

class LinkedStack
{
private:
	Node* top; //栈顶指针
public:
	LinkedStack() : top(nullptr)  {}  //构造函数
	//进栈操作
	void push(int x)
	{
		Node* newNode = new Node(x);
		if (top == nullptr)
		{
			top = newNode; 
		}
		else
		{
			newNode->next = top; 
			top = newNode; 
		}
	}
};


int main8()
{
	VectorStack stack1;
	stack1.push(1);    //将元素1入栈
	stack1.push(2);		//将元素2入栈
	return 0;


	LinkedStack stack2;
	stack2.push(1);  //将元素1入栈
	stack2.push(2);  //将元素2入栈

}

