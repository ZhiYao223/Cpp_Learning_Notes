#include<iostream>
using namespace  std;

#if 0
//形式一
struct LNode
{
	int data; //定义单链表结点类型
	struct LNode* next; //每个结点存放一个数据元素
};
typedef struct LNode LNode;

//形式二
struct LNode
{
	int data;		//每个结点存放一个数据元素
	struct LNode* next;		//每个结点存放一个数据元素
};
typedef struct LNode LNode;
typedef struct LNode* LinkList;


//形式三  (推荐)
typedef struct LNode  //定义单链表结点类型
{
	int data;		//每个结点存放一个数据元素
	struct LNode* next;//指针指向下一个结点
}LNode, * LinkList;  
//LNode：struct LNode 的类型别名。
//LinkList：struct LNode* 的类型别名，表示指向单链表的指针。

//LNode*强调返回的是一个结点、LinkList 强调这是一个单链表
LNode* GetElem(LinkList L, int i)  //查找单链表L中的第i个结点的元素
{
	int j = 1;  
	LNode* p = L->next; //声明一个结点指向头结点。
	if (i == 0)  
		return L;     //返回头结点指针 L
	if (i < 1 || i > +1)
		return NULL;  //链表中不存在第 i 个节点
	while (p != NULL && j < i)  //直到遍历到第i个元素，或遍历完整个链表
	{ 
		p = p->next; //未到达i位置，指针p继续后移一位
		j++;
	}
	return p;  //返回第 i 个节点的指针。
}

//要表示一个单链表时，只需声明一个头指针L,指向单链表的第一个结点
LNode *L1;   //声明一个指向单链表第一个结点的指针
LinkList L2; //声明一个指向单链表第一个结点的指针（代码可读性更强）

#endif

