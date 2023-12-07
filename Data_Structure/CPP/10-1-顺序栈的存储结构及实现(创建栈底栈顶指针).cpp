#if 0

#include <iostream>
#include <Windows.h>
using namespace std;

//顺序栈的结构类型
#define	 MaxSize 50			//定义栈中元素的最大个数为50
typedef  int  SElemType;	//栈存储的数据类型，用int代替SElemType  

//创建顺序栈
typedef struct
{
	SElemType* base;  //栈底指针   base指针不动、top往上移
	SElemType* top;  //栈顶指针
	int stackSize;	// 当前已分配的存储空间大小,即顺序栈的大小
}SqStack;			//顺序栈的结构体定义

bool InitStack(SqStack& stack);	//初始化栈
bool StackEmpty(SqStack& stack);//判断是否为空
bool StackFull(SqStack& stack);	//判断是否已满
int  StackLength(SqStack& stack);//获取栈已存储的元素个数
bool PushStack(SqStack& stack, SElemType value);//入栈
bool PopStack(SqStack& stack, SElemType& vlaue);//出栈
bool GetStack(SqStack& stack, SElemType& value);//获取栈顶的元素
void DestoryStack(SqStack& stack);//销毁栈、释放栈的内存

//初始化顺序栈
bool InitStack(SqStack& stack)
{
	//动态分配一个SElemType类型MaxSize长度的空间，将地址给顺序栈stack的栈底指针
	stack.base = new SElemType[MaxSize];
	//stack.base = (SElemType*)malloc(MaxSize * sizeof(SElemType); //C语言语法
	
	//判断顺序栈的栈底指针(stack.base)是否为空，若无地址，则分配失败
	if (!stack.base)  //判断是否分配内存失败
	{
		return false;
	}
	stack.top = stack.base;		 //初始化为空栈，栈顶栈底指向同一个位置
	stack.stackSize = MaxSize; //空的顺序栈，有MaxSize个空间可以存储
	return true;   //初始化完成
}

//判断栈空
bool StackEmpty(SqStack& stack)
{
	//cout << "判断栈空的结果为：";
		if(stack.top == stack.base) //当栈顶、栈底指针指向同一位置时栈为空
		{
			//cout << "栈空" << endl;
			return true;  
		}
		else
		{
			//cout << "栈不空" << endl;
			return false; 
		}
}
//判断栈满
bool StackFull(SqStack& stack)  //指针top减去指针base， 通过两指针相减所得判断之中相隔元素个数
{
	if ((stack.top - stack.base) == MaxSize)	//若两指针位置相减 等于 栈的大小 则栈为满栈
	{
		//cout << "栈满" << endl;
		return true; 
	}
	else
	{
		return false; 
	}
}
//顺序栈入栈: 判断是否栈满，如果栈已满，则入栈失败，否则将元素放入栈顶，栈顶指针向上移动一个空间（top++）。
//栈顶永远指向下一个待插入元素的位置，即指向最后一个元素的下一地址。
bool PushStack(SqStack& stack, SElemType value)
{
	if (StackFull(stack))  //满栈
	{
		cout << "栈满" << endl; 
		return false; 
	}
	//若栈未满，执行入栈操作
	*stack.top = value;  //将要插入的value值，放入top指针所指的空间中
	stack.top++;   //栈顶指针加1，向上移动一位，更新栈顶位置。
	//或者写成 *stack.top++=value;
	return true; 
}

//顺序栈出栈：判断是否栈空，如果栈空，出栈失败。否则将栈顶元素输出，栈顶指向减 1 
bool PopStack(SqStack& stack, SElemType &value)
{
	if (StackEmpty(stack))  //判断栈是否为空
	{
		cout << "栈为空" << endl;
		return false; 
	}
	stack.top--;  //栈顶指针下移一位，指向最后一个元素
	value = *stack.top;  //将栈顶指针所指向地址中的数据元素存入value中返回。
	//或者：value = *--stack.top;
	return true; 
}

//获取栈顶元素: 首先也要判断栈是否为空
//取栈和出栈不同，取栈顶元素是把其赋值一份，栈的元素个数保持不变，所以栈顶指针最后也不变。
//而出栈是将栈顶元素从原有栈中拿走，最终栈顶指针要减 1，即向下移动一位 。
bool GetStack(SqStack& stack, SElemType& value)     
{
	if (StackEmpty(stack))
	{
		cout << "栈为空" << endl;
		return false;
	}
	value = *(stack.top - 1); //将栈顶指针下一位空间所存储的元素取出，并赋值给value返回 实际栈顶指针位置不变。
	return true; 
}

//清空栈：  释放内存
void DestoryStack(SqStack& stack)
{
	if (stack.base)  //若栈底指针有分配地址。
	{
		delete stack.base;   //释放栈底指针的地址
		stack.top = NULL;     //令栈顶、栈底指针指向空
		stack.base = NULL;
		stack.stackSize = 0;
		cout << "栈已释放内存！" << endl; 
	}
}

//获取顺序栈存储的元素个数：栈顶指针减去栈尾指针即为栈所存储的元素个数
int StackLength(SqStack& stack)    //栈顶指针减去栈底指针，所得即为二者间相隔的元素个数
{
	return (stack.top - stack.base); //返回栈中元素个数
}

int main10_1()
{
	//创建顺序栈
	SqStack stack;

	//初始化栈
	InitStack(stack);

	//插入元素
	int number = 0; //插入元素个数
	int value = 0;	//插入元素值
	cout << "请输入需要插入的元素个数：";
	cin >> number;

	while (number > 0)
	{
		cin >> value;   //输入数据
		PushStack(stack, value);  //插入所输入的数据
		number--;    //插入元素个数计数
	}
	//测试顺序栈
	//获取栈顶的元素
	GetStack(stack, value);
	cout << "当前栈顶元素是：" << value << endl;
	cout << "当前栈的元素个数是：" << StackLength(stack) << endl;

	//出栈
	cout << "出栈顺序：" << endl;
	while (!StackEmpty(stack))   //栈不为空，进入循环
	{
		PopStack(stack, value);
		cout << value << " ";
	}
	cout << endl;  

	//释放栈的内存
	DestoryStack(stack);

	system("pause");
	return 0;
}

#endif

