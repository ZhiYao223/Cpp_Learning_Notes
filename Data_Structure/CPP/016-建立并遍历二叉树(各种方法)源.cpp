#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

using TElemType = char;
struct BTNode
{
	TElemType data;	//数据域
	BTNode* lchild;	//左孩子
	BTNode* rchild;	//右孩子
};
using BiTree = BTNode*;		//定义指针型别名

//创建结点
BTNode* NewNode()
{
	BTNode *Node = new BTNode;
	if (Node == nullptr)	exit(OVERFLOW);
	Node->lchild = Node->rchild = nullptr;
	return Node; 
}

void FreeNode(BiTree* T)	//释放根节点
{
	free(T);
}

//第一种建立二叉树方法(通过结点进行创建二叉树)
//前序创建二叉树
void PreCreateTree(BiTree &T)
{
	char ch;
	cin >> ch;
	if (ch != '#' || T != nullptr)
	{
		T = NewNode();
		T->data = ch;
		PreCreateTree(T->lchild);	//创建左子树
		PreCreateTree(T->rchild);	//创建右子树
	}
}

//按照先序顺序建立二叉树
void createBiTree(BiTree& T)
{
	//输入需要将二叉树补成满二叉树		ABD##E##CH### 或者 AB##C##
	char ch;
	cin >> ch;
	if ('#' == ch)		//当遇到#时，令树的根结点为NULL，从而结束该分支的递归
		T = nullptr;
	else
	{
		T = NewNode();
		T->data = ch;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}
//先序遍历输出
void PreOrderTraverse(BiTree T)
{
	if (T != nullptr)
	{
		cout << T->data <<" ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
//中序遍历输出
void InOrderTraverse(BiTree T)
{
	if (T != nullptr)
	{
		InOrderTraverse(T->lchild);
		cout << T->data << " ";
		InOrderTraverse(T->rchild);
	}
}
//后序遍历输出
void PostOrderTraverse(BiTree T)
{
	if (T != nullptr)
	{
		InOrderTraverse(T->lchild);
		InOrderTraverse(T->rchild);
		cout << T->data << " ";
	}
}


int main16()
{
	BiTree T;		//声明一个指向二叉树根结点的指针
	createBiTree(T);		//建立二叉树
	cout << "二叉树建立完成！" << endl;
	cout << "前序遍历：";
	PreOrderTraverse(T);

	cout << endl << "中序遍历：";
	InOrderTraverse(T);

	cout << endl << "后序遍历：";
	PostOrderTraverse(T);

	system("pause");
	return 0;
}













