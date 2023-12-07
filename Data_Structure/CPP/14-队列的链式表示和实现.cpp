#include<iostream>
using namespace std;

#define MAXQSIZE 100 //最大队列长度
typedef int QElemType; //

typedef struct Qnode
{
	QElemType data;
	struct Qnode* next; 
}QNode, *QueuePtr; //队列结点类型、指向队列结点的指针类型

typedef struct     //为指向队列结点的指针类型QueuePtr单独建立一个包含队头队尾的结构体
{
	QueuePtr  front; //队头指针
	QueuePtr  rear;  //队尾指针
}LinkQueue;       //链式队列定义

//初始化链队列：front与rear都指向队头结点，队头结点next指针置空
bool InitQueue(LinkQueue& Q)
{
	//将队列的头尾指针都指向同一个节点，表示队列为空
	//C++ 的 new 运算符会在对象不再需要时自动调用析构函数，并释放内存，而 malloc 函数需要手动调用 free 函数来释放内存。
	Q.front = Q.rear = new QNode;  
	//Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
	{
		exit(OVERFLOW);
	}
	Q.front->next = NULL; //将队列队头指针置空
	return true; //初始化完成
}
//链队列判空
bool QueueEmpty(LinkQueue& Q)
{
	//队头队尾指针指向同一位置(队头结点)，队列为空。
	return Q.front == Q.rear;
}

//链队列销毁：从队头结点开始，一次释放所有结点
bool DestoryQueue(LinkQueue& Q)
{
	QueuePtr temp;   //创建临时指针  指针声明二选一
	//QNode* temp;  
	while (Q.front)
	{ 
		//反正rear指针闲置无事，此处可以不额外创建temp，直接将下列temp替换成Q.rear效果一样。
		temp = Q.front->next; //temp指向队头的下一个结点
		delete Q.front;  //释放队头结点
		Q.front = temp;  //更新队头结点
	}
	Q.rear = NULL;
	cout << "队列销毁成功！" << endl;
	return true; 
}
//链队入队操作，将元素value入队：创建新结点，将元素放入结点数据域、新节点next指针置空、队尾rear指向新结点、更新队尾结点。
bool EnQueue(LinkQueue& Q, QElemType value)
{
	QueuePtr temp = new QNode; //创建指针型QNode结点，指针指向要插入的结点元素
	if (!temp)    //创建结点，分配内存要判断是否分配成功
	{
		exit(OVERFLOW);
	}
	temp->data = value;    //将要插入的元素放入temp结点数据域
	temp->next = NULL;     //temp结点指针域置空
	Q.rear->next = temp;   //将队尾指针接上temp结点
	Q.rear = temp;         //更新队尾结点
	return true; 
}
//链队的出队：删除队头结点的下一位，头结点不存储数据元素。
//判断链队列是否为空、创建temp指针指向要出栈的元素、删除该结点，将头结点指向删除结点的后继结点，更新队头，若删除的是队尾，则队头队尾指针均指向队头结点。。
bool DeQueue(LinkQueue& Q, QElemType value)
{
	if (!QueueEmpty(Q))   //若链队列不为空
	{
		QueuePtr temp = new QNode; //创建指针类型的QNode结点，指针指向新结点
		if (!temp)  exit(OVERFLOW);//判断新结点内存是否分配成功
		temp = Q.front->next;//temp指向队头结点下一位即第一位元素
		value = temp->data;//将temp所指结点的数据保存到value中
		Q.front->next = temp->next;//更新队头结点 

		if (Q.rear == temp)//如果删除的是最后一个结点(尾结点)，尾结点回移
		{
			Q.rear = Q.front;//rear、front均指向仅存的头结点
			Q.front->next = NULL;
		}
		delete temp;  //释放temp所指结点空间
		return true;  //出栈成功
	}
	return false; //队列为空
}
//链队的队头元素
bool GetHead(LinkQueue Q)
{
	if (!QueueEmpty(Q))  //若链队列不为空
	{
		return Q.front->next->data;
	}
	return false; 
}
//链队列的长度/元素个数
//这里Q不能用'&'引用型传递，否则下方队头指针front的移动会修改原队列front指针。不加引用，就会创建一个副本执行操作，故相比前者会多消耗些内存和时间。也可以创建一个临时指针temp对队列进行遍历，这样即使Q加了&, 也不会影响原链队列。
int QueueLength(LinkQueue Q)
{
	if (!QueueEmpty(Q))  //若链队列不为空
	{
		int count = 0;	     //元素个数/队列长度
		while (Q.front != Q.rear)//直到
		{
			Q.front = Q.front->next;//队头指针后移一位
			count++; //计数加一
		}
		return count; 
	}
	return false; //队列为空或不存在
}
//遍历输出链队元素
bool QueuePrint(LinkQueue Q)  
{
	if (!QueueEmpty(Q))
	{
		while (Q.front != Q.rear)
		{
			Q.front = Q.front->next;	  //将链队头指针指向第一个元素结点
			cout << Q.front->data <<" ";  //输出该结点所指的结点数据
		}
		cout << endl;
		return true; 
	}
	cout << "队列为空或不存在！";
	return false;  
}

int main14()
{
	LinkQueue Q;
	QElemType value = 0;
	InitQueue(Q);

	int number = 0;		//入队的元素个数
	cout << "请输入要入队的元素个数：" << " ";
	cin >> number; 

	int num = 0;		//入队的数据元素
	while ((number--) > 0)
	{
		cin >> num; //输入数据元素
		EnQueue(Q, num); //将num入队 
	}

	cout << "队列输出顺序：";
	QueuePrint(Q); //遍历输出队列元素
	cout << "队头元素为：" << GetHead(Q) << endl;
	cout << "队列长度为：" << QueueLength(Q) << endl;

	DeQueue(Q,value); //出队，并将出队元素存储到value中
	cout << "队列出队后输出顺序：";
	QueuePrint(Q); //遍历输出队列元素
	cout << "队头元素为：" << GetHead(Q) << endl;
	cout << "队列长度为：" << QueueLength(Q) << endl;

	DeQueue(Q, value);
	cout << "队列出队后输出顺序：";
	QueuePrint(Q); //遍历输出队列元素
	cout << "队头元素为：" << GetHead(Q) << endl;
	cout << "队列长度为：" << QueueLength(Q) << endl;

	DestoryQueue(Q);//销毁链式队列，释放内存空间

	QueuePrint(Q); //遍历队列元素
	system("pause");
	return 0;
}


