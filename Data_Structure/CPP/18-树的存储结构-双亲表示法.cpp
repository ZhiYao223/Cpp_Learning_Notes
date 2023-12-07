#include<iostream>
using namespace std;

using TElemType = int;
struct PTNode
{
	TElemType data;
	int parent;		//双亲位置
};


//树结构
#define Max_Tree_Size 100
struct PTree
{
	PTNode node[Max_Tree_Size];
	int r, n;			//根结点的位置和结点个数
};


int main18()
{

	system("pause");
	return 0;
}








//树结构