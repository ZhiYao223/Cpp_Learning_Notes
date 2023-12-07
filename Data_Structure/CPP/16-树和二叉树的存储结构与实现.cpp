
#if 0
#include<iostream>
using namespace std;

/*
	二叉树的顺序存储结构
	实现：按满二叉树的节点层次编号，依次存放二叉树中的数据元素。
	在n个结点的二叉链表中，必有2n个链域，只会有n-1个结点的链域存放指针指向非空子女结点
	空指针数目=2n-(n-1)=n+1

	先序遍历：访问根节点、先序遍历左子树、先序遍历右子树     根左右  前缀表示
	中序遍历：中序遍历左子树、访问根节点、中序遍历右子树		左根右  中缀表示
	后序遍历：后序遍历左子树、后序遍历右子树、访问根节点		左右根  后缀表示
*/
//二叉树的顺序存储表示

#define MAXTSIZE 100
typedef TlemType SqBiTree[MAXTSIZE];
SqBiTree bt;

//三叉链表： |lchild|data|parent|rchild|
typedef  struct TriTNode
{
	TelemType data;
	struct TriTNode* lchild, * parent, * rchild;
}TriTNode, * TriTree;
#endif


#if 0
//二叉树的链式存储结构
typedef int TelemType;
typedef  struct BiTNode
{
	TelemType data;
	struct BiTNode* lchild, * rchild;	//左右孩子指针
}BiTNode, *BiTree; //利用typedef 将struct BiNode 定义为BiNode, *BiTree结点、指针类型，增强可读性。

//创建新结点
BiTNode* NewNode(TelemType value)
{
	BiTNode* Node = new BiTNode;	//申请一个node类型变量的地址空间
	Node->data = value;		//结点权值为v
	Node->lchild = Node->rchild = nullptr;	//初始状态下无左右孩子
	return Node;		//返回新结点的地址
}

//在二叉树里面找到所有数据域（对多个结点实行操作）为给定数据域的结点，并且对查找到的结点修改为给定的数据域
void SearchNode(BiTree T, TelemType data, TelemType newdata)
{
	if (T == nullptr) return;	//空结点的情况
	if (T->data == data){
		T->data = newdata;		//找到数据域为data的结点并修改为newdata
	}
	SearchNode(T->lchild, data, newdata);	//搜索左子树
	SearchNode(T->rchild, data, newdata);	//搜索右子树
}



//二叉树先序遍历
bool PreOrderTraverse(BiTree T)
{
	if (T == NULL)	return  false;		//到达空树，即递归边界
	else
	{
		cout << T->data<<endl;			//访问根节点数据域
		PreOrderTraverse(T->lchild);	//递归遍历左子树
		PreOrderTraverse(T->rchild);	//递归遍历右子树
	}
	return true; 
}
//中序遍历
bool InOrderTraverse(BiTree T)
{
	if (T == NULL)	return false; //到达空树，即递归边界
	else
	{

		InOrderTraverse(T->lchild);		//到达空树，即递归边界
		cout << T->data << endl;			//访问根节点数据域
		InOrderTraverse(T->rchild);		//访问右子树
	}
	return true;
}
//后序遍历
bool PostOrderTraverse(BiTree T)
{
	if (T == NULL)	return false;
	else
	{

		PostOrderTraverse(T->lchild);	//访问左子树
		PostOrderTraverse(T->rchild);	//访问右子树
		cout << T->data << endl;		//访问根节点数据域
	}
	return true; 
}
//二叉树遍历算法的应用-----复制二叉树
/*
	否则，申请新结点空间，复制根节点
	递归复制左子树
	递归复制右子树
*/
int CopyTree(BiTree T, BiTree& NewT)
{
	if (T == NULL)		//如果是空树，返回0
	{
		NewT = NULL;
		return 0;
	}
	else
	{
		NewT = new BiTNode;			//创建新结点，用于复制原有结点
		NewT->data = T->data;		//将树结点的数据赋值到新结点数据域
		CopyTree(T->lchild, NewT->lchild);		//复制左子树
		CopyTree(T->rchild, NewT->rchild);		//复制右子树
	}
}

//二叉树遍历算法的应用------计算二叉树深度
/*
	如果树为空，则深度为0
	否则，递归计算左子树的深度记为m，递归计算右子树的深度为n，二叉树的深度则为m与n的较大者+1
*/
int Depth(BiTree T)
{
	int n, m;
	if (T == NULL)
		return 0;	//如果是空树，返回0
	else
	{
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		return (m > n) ? (m + 1) : (n + 1);
	}

}
//二叉树遍历算法的应用------计算二叉树结点总数
/*
	如果是空树，则结点个数为0
	否则，结点个数为左子树的结点个数+右子树的结点个数再+1
*/
int NodeCount(BiTree T)
{
	if (T == NULL)
		return 0;
	else
	{
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}
//二叉树遍历算法的应用------计算二叉树叶子结点个数
/*
	如果为空树，则叶子结点个数为0
	否则，为左子树的叶子结点个数 + 右子树的叶子结点个数。
*/	
int LeafCount(BiTree T)
{
	if (T == NULL)
	{
		return 0;		//如果是空树返回0
	}
	if (T->lchild == NULL && T->rchild == NULL)
	{
		return 1;		//如果是叶子结点返回1
	}
	else
	{
		//如果不是叶子结点，则分别统计左右子树上的结点。
		return LeafCount(T->lchild) + LeafCount(T->rchild);
	}
}
#endif // 0




/*
中序遍历非递归算法：
二叉树中序遍历的非递归算法关键：在中序遍历过某节点的整个左子树后，如何找到该结点的根以及右子树
基本思想：
建立一个栈
根节点进栈，遍历左子树
根结点出栈、输出根结点，遍历右子树
*/
#if 0
bool InOrderTraverse(BiTree T)
{
	BiTree p;  //创建一个指针
	InitStack(S);//初始化栈
	p = T;     //令指针p指向根节点
	while (p || !StackEmpty(S)  //当指针p不为空，或者栈不为空时
	{
		if (p){
			Push(S, p); 
			p = p->lchild;    }
		else{
			Pop(S, q);
			cout << q->data << endl; 
			p = q->rchild;  }
	}
	return true;
}
#endif

/*
	二叉树的层次遍历：思路：使用一个队列。
	一、将根节点进队
	二、队不为空时循环：从队列中列出一个结点*p，访问它；
				   1.若它有左孩子结点，将左孩子结点进队；
				   2.若它有右孩子结点，将右孩子结点进队；
*/
#if 0
typedef int BTNode;
#define MaxSize 100
typedef struct
{
	BTNode data[MaxSize];	//存放对中元素
	int front, rear;		//队头和队尾指针
}SqQueue;					//顺序循环队列类型

//二叉树层次遍历算法
void LevelOrder(BTNode* b)
{
	BTNode* p;     //
	SqQueue* qu;		//创建一个队列
	InitQueue(qu);		//初始化队列
	EnQueue(qu, b);		//根节点指针进入队列
	while (!QueueEmpty(qu))	//队不为空，则循环
	{
		EeQueue(qu, p);		//出队队列头结点
		cout << p->data << endl;	//访问结点p
		if (p->lchild != NULL)
		{
			EnQueue(qu, p->lchild);  //有左孩子时将其进队
		}
		if (p->rchild != NULL)
		{
			EnQueue(qu, p->rchild);	//有右孩子时将其进队
		}
	}
}
//按先序遍历序列建立二叉树的二叉链表
bool CreateBiTree(BiTree& T)
{
	char ch;
	cin >> ch;
	if (ch == "#") T = NULL; 
	else
	{
		if (!(T = new BiTNode))
		{
			exit(OVERFLOW);
		}
		T->data = ch;	//生成根节点
		CreateBiTree(T->lchild);	//构造左子树
		CreateBiTree(T->rchild);	//构造右子树
	}
	return true; 
}



int main16_2()
{
	system("pause");
	return 0;
}
#endif 