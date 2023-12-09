
#if 0
#include<iostream>
using namespace std;

#define MAXQSIZE 100		//最大队列长度
//循环队列
using QElemType = int; //等价于typedef int QElemType;
struct SqQueue
{
	QElemType* base;	//初始化动态分配存储空间
	int front;	//头指针、若队列为空
	int rear;	//尾指针 若队列不为空，指向队尾元素的下一个位置
};


//队列初始化
bool InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE];	//分配数组空间
	if (!Q.base)
	{
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;	//头尾指针置为0，队列为空
	return true; 
}
//求队列的长度/元素个数
int QueueLength(SqQueue Q)
{
	//若rear指向大于队列长度后，重新转一圈指向队头
	return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}
//判断队列是否为空
bool QueueEmpty(SqQueue& Q)
{	
	return (Q.front == Q.rear);
}
//判断队列是否已满
bool QueueFUll(SqQueue& Q)
{
	//队列已满
	return (Q.rear + 1) % MAXQSIZE == Q.front;
}

//循环队列入队
bool EnQueue(SqQueue& Q, QElemType value)
{
	if (!QueueFUll(Q))	//如果队列未满
	{
		Q.base[Q.rear] = value;
		Q.rear = (Q.rear + MAXQSIZE) % MAXQSIZE;//队尾指针+1
		return true; 
	}
	return false; 
}
//循环队列出列, 并保存出列元素数据
bool DeQueue(SqQueue& Q, QElemType value)
{
	if (!QueueEmpty(Q))
	{
		value = Q.base[Q.front];//将出栈元素放入value
		Q.front = (Q.front + 1) % MAXQSIZE;	//队头指针+1
		return true; 
	}
	return false; //队列为空、出队失败
}
//取队头元素
QElemType GetHead(SqQueue Q)
{
	if (!QueueEmpty(Q))
	{
		return Q.base[Q.front];	//返回队头指针元素
	}
	return false; 
}

//遍历打印队列元素
bool QueuePrint(SqQueue Q)
{
	if (QueueEmpty(Q)) return false;
	while (Q.front != Q.rear)
	{
		cout << Q.base[Q.front] << " ";
		Q.front = (Q.front + 1) % MAXQSIZE;
	}
	cout << endl;
	return true; 
}

//方案二
bool QueuePrint(SqQueue &Q)
{
	if (!QueueEmpty(Q))
	{
		QElemType temp = Q.front;
		while (temp != Q.rear)
		{
			cout << Q.base[temp] << " ";
			temp = (temp + 1) % MAXQSIZE;//位置上移+1
		}
		cout << endl;
		return true; 
	}
	return false; 
}

int main()
{
	system("pause");
	return 0;
}
#endif

#include<iostream>
using namespace std;

using TElemType = int;
struct ThreadBNode
{
	TElemType data;
	ThreadBNode* lchild, * rchild;
	int ltag, rtag;
};
using ThreadTree = ThreadBNode*;

//以先序遍历创建二叉树
void CreateBiTree(ThreadTree& T)
{
	char ch;
	cin >> ch;
	if (ch == '#') T = nullptr;
	else
	{
		T = new ThreadBNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

//通过中序遍历线索化二叉树
void InThreadBiTree(ThreadTree p, ThreadTree pre)
{
	if (p != nullptr)
	{
		InThreadBiTree(p->lchild, pre);
		if (p->lchild == nullptr)
		{
			p->lchild = pre; 
			p->ltag = 1;
		}
		if (p->rchild == nullptr && pre != nullptr)
		{
			pre->rchild = pre; 
			pre->rtag = 1;
		}
		pre = p; 
		InThreadBiTree(p->rchild, pre);
	}
}
//中序遍历 线索化二叉树
void InOrderTraverseThreadBiTree(ThreadTree T)
{
	ThreadTree p;
	p = T->lchild;
	while (p != T)
	{
		while (p->ltag == 0)
		{
			p = p->lchild;
		}
		cout << p->data << " ";
		while (p->rtag == 1 && p->rchild != T)
		{
			p = p->rchild;
			cout << p->data << " ";
		}
		p = p->rchild;
	}
}


int main19()
{
	ThreadTree p = NULL;
	ThreadTree pre = NULL;

	CreateBiTree(p);
	InThreadBiTree(p, pre);

	system("pause");
	return 0;
}

