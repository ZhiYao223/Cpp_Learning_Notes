#if 0
#include<iostream>
using namespace std;

/*
ltag为0时指向该结点的左孩子，为1时指向该结点的前驱。
rtag为0时指向该结点的右孩子，为1时指向该结点的后继。
*/
#if 0
typedef int ElemType;
typedef struct ThreadBNode {				//线索二叉树结构类型
	ElemType data;							//数据元素
	struct ThreadBNode* lchild, * rchild;	//左、右孩子指针
	int ltag, rtag;							//左、右线索标志
}ThreadNode, *ThreadTree;
#endif

using ElemType = int;				 //等价于typedef int ElemType;
struct ThreadBNode					 //ThreadBNode 本身就可以用作结点类型
{
	ElemType data;
	ThreadBNode* lchild, * rchild;  //左孩子、右孩子
	int ltag, rtag;					//左右孩子、前驱后继标志位
};
using ThreadTree = ThreadBNode*;	//类似于C语言结构体类型的重命名 }ThreadNode, *ThreadTree;

//以先序遍历创建二叉树
void CreateBiTree(ThreadTree& T)
{
	char ch;
	cin >> ch;
	if (ch == '#') T = nullptr;
	else
	{
		T = new ThreadBNode;	//创建根结点，并分配空间
		T->data = ch;			//根结点赋值
		CreateBiTree(T->lchild);//建立左子树
		CreateBiTree(T->rchild);//建立右子树
	}
}

/*
附设指针pre指向刚刚访问过的结点，指针p指向正在访问的结点，即pre指向p的前驱。
在中序遍历的过程中，检查p的左指针是否为空，若为空就将它指向pre;检查pre的右
指针是否为空，若为空就将它指向p
*/
//通过中序遍历线索化二叉树：
void InThreadBiTree(ThreadTree p, ThreadTree pre)
{
	if (p != NULL)
	{
		InThreadBiTree(p->lchild, pre);	//递归，线索化左子树
		if (p->lchild == NULL)		//左子树为空，建立前驱标签
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = pre;	//建立前驱节点的后继线索
			pre->rtag = 1;
		}
		pre = p;	//标记当前结点成为刚刚访问过的结点
		InThreadBiTree(p->rchild, pre);		//递归，线索化右子树
	}
}

//通过中序遍历建立中序线索二叉树
void CreateInThread(ThreadTree T)
{
	ThreadTree pre = NULL;		//第一个结点的左子树置为NULL
	if (T != NULL)
	{
		InThreadBiTree(T, pre);			//线索化二叉树
		pre->rchild = nullptr;		////处理中序遍历的最后一个结点，最后一个结点的右子树置为空
		pre->rtag = 1;                         
	}
}
/*
	T指向头结点，头结点左链lchild指向根结点，头结点右链rchild指向中序遍
	的最后一个结点。中序序列中的第一个结点的lchild域指针和最后一个结点的rchild域指针均指向头结点.中序遍历二叉线索链表表示的二叉树T
*/
ElemType visit(ThreadTree p)
{
	return p->data;		//返回结点数据
}
/*
 如果所用的二叉树需经常遍历或查找结点时需要某种遍历序列中的前驱和后继，那么采用线索二叉链表的存储结构就是非常不错的选择。
*/
//中序遍历 线索二叉树，建议结合图像推理分析
void InOrderTraverse_Thread(ThreadTree T)
{
	ThreadTree p;
	p = T->lchild;	//p指向根结点
	//空树或遍历结束时，p == T 最后一个结点指向根结点
	while (p != T)
	{
		while (p->ltag == 0)//当ltag=0时循环到中序序列第一个结点
		{
			p = p->lchild;	//p指向p的左子树
		}
		visit(p);		//访问该结点
		//后继线索为1且不是指向头指针
		while (p->rtag == 1 && p->rchild != T)
		{
			p = p->rchild;		//p指向p的后继
			visit(p);			//访问该结点
		}
		//p进至其右子树根结点，对右子树根进行遍历
		p = p->rchild;          
	}
}

//先序遍历 线索二叉树
void  PreOrderTraverse_Thread(ThreadTree T)
{
	ThreadTree p;
	p = T->lchild;		//p指向根结点

	while (p != T)
	{
		visit(p);
		while (p->ltag == 0)
		{
			p = p->lchild;		//p指向p的左子树
		}
		while (p->ltag == 1 &&  p->rchild != T)
		{
			p = p->rchild;		//p指向p的后继
			visit(p);			//访问该结点
		}
		p = p->rchild;
	}
}



int main17()
{

	system("pause");
	return 0;
}

#endif