/*
在C++中实现静态链表中删除某一节点元素的操作可以通过以下步骤完成：

遍历链表，找到要删除节点的前驱节点（即指向要删除节点的节点）。
修改前驱节点的指针，将其指向要删除节点的下一个节点。
将要删除节点的索引加入空闲节点链表，使其成为可被重新利用的节点。
以下是一个简单的示例代码，演示了如何在C++中实现静态链表中删除某一节点元素的操作：

*/

#include <iostream>
using namespace std;

const int Max_Size = 100;  //定义静态链表的最大容量

struct Node
{
	int data;
	int next; //用来表示结点之间的指针或数组下标，-1表示链表结束
}staticLinkedList[Max_Size];   //静态链表的存储空间

int currentNode = 0;	//当前可用的结点空间

//初始化静态链表
void initStaticLinkedList()
{
	for (int i = 0; i < Max_Size - 1; i++)
	{
		staticLinkedList[i].next = i + 1; //将结点依次连接起来
	}
	staticLinkedList[Max_Size - 1].next = -1;//最后一个结点的next为-1表示结束
}
 
//插入结点
int insertNode(int value)
{
	if (currentNode == -1)
	{
		cout << "链表已满，无法插入" << endl;  
		return -1;
	}
	int newNodeIndex = currentNode;
	staticLinkedList[newNodeIndex].data = value;//存储数据
	currentNode = staticLinkedList[currentNode].next;  //更新可用结点位置
	return newNodeIndex;  //返回新插入结点的索引
}

//删除结点
void deleteNode(int value)
{
	int index = 0;
	int prevIndex = -1; //前驱结点索引
	//找到要删除结点的索引及其前驱结点索引
	while (index != -1)
	{
		if (staticLinkedList[index].data == value)
		{
			if (prevIndex == -1)
			{
				//删除的是第一个结点
				currentNode = staticLinkedList[index].next;
			}
			else
			{
				staticLinkedList[prevIndex].next = staticLinkedList[index].next;
			}
			staticLinkedList[index].next = currentNode;//将删除的结点加入空闲列表
			currentNode = index; //更新可用结点位置
			return;
		}
		prevIndex = index;
		index = staticLinkedList[index].next;
	}
	cout << "结点数据：" << value << "未发现该元素，无法删除" << endl;
}

//遍历访问
void traverseStaticLinkedList()
{
	int index = 0;
	while (index != -1)
	{
		cout << staticLinkedList[index].data << "->";
		index = staticLinkedList[index].next;
	}
	cout << "NULL" << endl; 
}

int main9()
{
	initStaticLinkedList();

	//插入结点
	int node1 = insertNode(10);
	int node2 = insertNode(20);
	int node3 = insertNode(30);

	//遍历访问
	traverseStaticLinkedList();

	//遍历访问
	traverseStaticLinkedList();

	//删除节点
	deleteNode(20);

	//遍历访问
	traverseStaticLinkedList();

	return 0;
}
















