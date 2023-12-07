#if 0
#include<iostream>
#include<Windows.h>
using namespace std;

#define MaxSize  128		//栈最大可以存放的元素个数
typedef int SElemType;		//顺序栈存储的数据类型、用int代替SElemType

//创建顺序站
typedef struct
{
	SElemType* base; //栈底指针
	int top;		//栈顶的位置 如 0、1、2、3、4....MaxSize
}SqStack;		//顺序栈的结构体定义

//初始化顺序栈
bool InitStack(SqStack& stack)
{
	//动态分配一个SElemType类型MaxSize长度的空间，将地址给顺序栈Stack的栈底指针
	stack.base = new SElemType[MaxSize];
	//判断顺序栈的栈底指针(stack.base)是否为空，若无地址，则分配失败
	if (!stack.base)
	{
		return false; 
	}
	stack.top = 0;		//初始化栈顶指针的位置为0
	return true; 
}

//判断栈空   ;
bool StackEmpty(SqStack& stack)
{
	if (stack.top == 0)
	{
		return true; 
	}
	return false; 
}

//顺序栈中元素个数
int GetStackSize(SqStack& stack)
{
	return stack.top;  //栈顶位置即top的数值，就是栈中元素的个数
}

//判断栈满
bool StackFull(SqStack& stack)
{
	if (stack.top == MaxSize)   //top的位置值等于MaxSize时栈满
	{
		return true; 
	}
	return false; 
}

//顺序栈入栈，将数据存入stack.base[stack.top]所在的位置，然后stack.top的值加 1
bool PushStack(SqStack& stack, SElemType value)
{
	if (StackFull(stack))
	{
		cout << "栈满" << endl; 
		return false;  
	}
	//若栈未满，执行入栈操作
	stack.base[stack.top] = value;    //以栈顶位置作为下标存储数据
	stack.top++;		//栈顶自增一
	return true; 
}

//顺序栈出栈
//将stack.top的值减1，其位置便是栈最后一个数据元素所在位置。
bool PopStack(SqStack& stack, SElemType &value)
{
	if (StackEmpty(stack))
	{
		cout << "栈为空" << endl; 
		return false; 
	}
	stack.top--;	//栈顶自减 1
	value = stack.base[stack.top];	//以栈顶位置作为下标的值赋值给value返回
	
	return true; 
}

//获取顺序栈中元素
bool GetStack(SqStack& stack, SElemType& value)
{
	if (StackEmpty(stack))
	{
		cout << "栈为空" << endl;
		return false; 
	}
	value = stack.base[stack.top - 1];  //想象将栈顶下标减1后该位置的值赋值给value，并返回
	return true; 
}

void DeleteStack(SqStack& stack)
{
	if (stack.base)    //若栈底指针分配有地址，则释放
	{
		delete stack.base;  //释放栈底指针的地址
		stack.top = 0;		//令栈顶位置为0
		stack.base = NULL; //将栈底指针指向空
		cout << "栈已释放内存！" << endl; 
	}
}

int main()
{
	SqStack	stack;   //创建顺序栈

	//初始化顺序栈
	InitStack(stack);	

	//插入元素
	int number = 0;
	int value = 0;
	cout << "请输入需要插入的元素个数：";
	cin >> number;

	while (number > 0)
	{
		cin >> value;
		PushStack(stack, value);
		number--; 
	}
	//获取栈顶的元素
	GetStack(stack, value);
	cout << "当前栈顶的元素是：" << value << endl;

	//获取栈的元素个数
	cout << "当前栈的元素个数是：" << GetStackSize(stack) << endl;

	//出栈
	cout << "出栈顺序：" << endl;
	while (!StackEmpty(stack))
	{
		PopStack(stack, value);
		cout << value << " ";
	}
	//释放栈的内存
	DeleteStack(stack);
	system("pause");
	return 0;
}
#endif

