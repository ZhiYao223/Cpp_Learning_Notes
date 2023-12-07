/*
	解决假上溢的方法-----引入循环队列
	base[0]接在base[MAXQSIZE-1]之后，若rear+1==M，则令rear=0；
	实现方法：利用模(mod，C语言中：%) 运算；
	插入元素：Q.base[Q.rear] = x;
			 Q.rear = (Q.rear+1)%MAXQSIZE;
	删除元素：x = Q.base[s.front]
			 Q.front = (Q.front+1)%MAXQSIZE;

	涉及到移动、赋值原队列参数的函数参数列表如front，rear，都最好别用&引用，否则会修改原队列中的地址和数值如：SqQueue &Q
	使用SqQueue Q作参数列表时，函数引入的只是一份副本，不会修改原队列中变量、指针的空间地址与数值。

	在函数参数列表中，使用&符号将参数声明为引用类型。这意味着该函数将直接操作传递给它的变量，而不是创建该变量的副本。

	当不使用&时，参数将被声明为传值方式传递。这意味着在将变量传递给函数时，将创建该变量的一份副本，并在函数内部使用该副本。
	在函数内部对参数进行的任何修改都不会影响到原始变量。

在使用&时，参数将被声明为引用方式传递。这意味着函数将直接访问传递给它的变量，而不是创建副本。在函数内部对参数的任何修改都会直接影响原始变量。

因此，使用&可以避免不必要的复制，节省内存和处理时间。同时，通过对原始变量的修改，可以使函数更灵活地与其他代码进行交互。
*/
#include<iostream>
using namespace std;

#define MAXQSIZE 100  //最大队列长度
typedef int QElemType;

//循环队列
typedef struct
{
	QElemType* base;	//初始化的动态分配存储空间
	int front;	//头指针，若队列不空，指向队列头元素
	int rear;	//尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;  //普通类型用 '.' *SqQueue指针类型用 '->'

bool InitQueue(SqQueue& Q);			//循环队列初始化
int  QueueLength(SqQueue Q);			//循环队列长度
bool QueueFull(SqQueue& Q);			//判断队列是否已满
bool QueueEmpty(SqQueue& Q);		//判断队列是否为空
bool EnQueue(SqQueue& Q, QElemType value);//循环队列入队
bool DeQueue(SqQueue& Q, QElemType value);//循环队列出队
bool QueuePrint(SqQueue Q);		//打印输出队列
QElemType GetHead(SqQueue Q);		//获取队头元素

//队列的初始化
bool InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE]; //分配数组空间
	//Q.base = (QElemType*)MAXQSIZE * sizeof(QElemType);  C语言语法
	if (!Q.base)
	{
		exit(OVERFLOW);  //存储分配失败
	}
	Q.front = Q.rear = 0; //头指针尾指针置为0， 队列为空
	return true; 
}
//求循环队列的长度/元素个数
int QueueLength(SqQueue Q)
{
	//若rear指向大于队列长度后重新转一圈指向队头，假如rear=3，front= 4, 3-4=-1不合法。则通过（3-4+6)%6 = 5个元素
	return((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}
//判断队列是否已满
bool QueueFull(SqQueue& Q)
{
	return (Q.rear + 1) % MAXQSIZE == Q.front;  //队列满
}
//判断队列是否为空
bool QueueEmpty(SqQueue& Q)
{
	return (Q.front == Q.rear);
}
//循环队列入队
bool EnQueue(SqQueue& Q, QElemType value)
{
	if (!QueueFull(Q))   //如果队列没满
	{
		Q.base[Q.rear] = value; //将入队元素放入Q.rear所指向的空间中
		Q.rear = (Q.rear + 1) % MAXQSIZE;//队尾指针+1
		return true;
	}
	return false; //队列已满，入队失败
}
//循环队列出队
bool DeQueue(SqQueue& Q, QElemType value)
{
	if (!QueueEmpty(Q))  //如果队列非空
	{
		value = Q.base[Q.front];//将出栈元素保存到value中
		Q.front = (Q.front + 1) % MAXQSIZE; //队头指针+1
		return true; 
	}
	return false; //队列为空，出队失败
}
//取队头元素
QElemType GetHead(SqQueue Q)
{
	if (!QueueEmpty(Q)) //队列不为空
	{
		return Q.base[Q.front];  //返回队头指针元素
	}
	return false;
}
//遍历打印队列元素
bool QueuePrint(SqQueue Q) 
{
	//这里注意！！！ 如果要用这种方法，参数列表一定不能用'SqQueue &value'引用，
	//因为使用&会修改真正的Q.front和Q.rear空间地址,影响原函数的指针位置，和后面的函数调用。
	if (Q.front == Q.rear)
		return false;
	while (Q.front != Q.rear)
	{
		cout << Q.base[Q.front] << "  ";
		Q.front = (Q.front + 1) % MAXQSIZE;
	}
	cout << endl;
	return true;

	//方案二，由于额外创建了临时变量用来遍历队列，不管用不用'&Q'都不会影响原队列中front与rear的位置
	//if (!QueueEmpty(Q))   //队列非空
	//{
	//	QElemType temp = Q.front; //创建临时变量，位置与队头相同
	//	while (temp != Q.rear)
	//	{
	//		cout << Q.base[temp] << " ";  //输出temp所处位置的元素
	//		temp = (temp + 1) % MAXQSIZE; //temp位置上移加 1 
	//	}
	//	cout << endl;
	//	return true;
	//}
	//return false;
}

int main13()
{
	SqQueue Q;  //创建循环队列Q
	InitQueue(Q); //队列初始化
	QElemType value = 0;
	
	int number = 0; //入队的元素个数
	cout << "请输入要入队的元素个数：" << " ";
	cin >> number;

	int num = 0; //入队的数据元素
	while ((number--) > 0)
	{
		cin >> num; //输入数据元素
		EnQueue(Q, num); //将num入队 
	}

	cout << "队列输出顺序：";
	QueuePrint(Q); //遍历输出队列元素
	cout << "队头元素为：" << GetHead(Q) << endl;
	cout << "队列长度为：" << QueueLength(Q) << endl;

	cout << endl;
	DeQueue(Q, value);
	cout << "出队后对列输出顺序：";
	QueuePrint(Q);  //遍历输出
	cout << "出队后队头元素为：" << GetHead(Q) << endl;
	cout << "出队后队列长度为：" << QueueLength(Q) << endl;

	system("pause");
	return 0;
}










