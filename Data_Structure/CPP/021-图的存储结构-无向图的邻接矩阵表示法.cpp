/*
	采用邻接矩阵表示法创建无向网
	无向网 --->有向图、无向图、有向网

	无向网 --->无向图---->1.初始化邻接矩阵时，w均为0	2.构造邻接矩阵时，w为1
	无向网 --->有向网---->1.邻接矩阵是非对称矩阵		2.仅为G.arcs[i][j]赋值	3.无需为G.arcs[j][i]赋值

	算法思想：
	1.输入总顶点数和总边数
	2.依次输入点的信息存入顶点表
	3.初始化邻接矩阵，使每个权值初始化为极大值
	4.构造邻接矩阵

	邻接矩阵有什么好处？
	1.直观、简单、好理解，空间复杂度O(n^2)
	2.方便检查任意一对顶点间是否存在边
	3.方便找任一顶点的所有"邻接点"(有边直接相连的顶点)
	4.方便计算任一顶点的"度"(从该点出发的边数为出度、指向该点的边数为入度)
	无向图：对应行或列非0元素的个数
	有向图：对应行非0元素的个数是"出度"，对应列非0元素的个数是"入度"

	邻接矩阵有什么缺点？
	1.由于固定大小，不便于增加和删除顶点
	2.浪费空间-----存稀疏图（点很多而边很少）有大量无效元素
				  对稠密图(特别是完全图)还是很合算的
	3.浪费时间，统计稀疏图中一个有多少条边，空间复杂度O(n^2)
*/

#include<iostream>
using namespace std;

//邻接矩阵的存储表示：用两个数组分别存储定点表和邻接矩阵
#define Maxlnt 32767		//表示极大值， 即无穷大
#define MVNum  100			//最大顶点数
typedef char VerTexType;	//设顶点的数据类型为字符型
typedef int ArcType;		//假设边的权值类型为整型

typedef struct {
	VerTexType vexs[MVNum];		//顶点表
	ArcType arcs[MVNum][MVNum];	//邻接矩阵
	int vexnum, arcnum;			//图的当前点数和边数
}AMGraph;	//Adjacency Matrix Graph

int LocateVex(AMGraph G, VerTexType u); //图G中查找顶点u，存在则返回顶点表中的下标，否则返回-1
bool CreateUDN(AMGraph& G);		//采用邻接矩阵表示法创建无向网

//采用邻接矩阵表示法创建无向网
bool CreateUDN(AMGraph& G)
{
	int v1, v2, w;
	//采用邻接矩阵表示法，创建无向网G
	cin >> G.vexnum >> G.arcnum;	//输入总定点数、总边数
	for (int i = 0; i < G.vexnum; ++i){
		cin >> G.vexs[i];	//依次输入点的信息
	}
	for (int i = 0; i <G.vexnum; ++i) {
		for (int j = 0; i < G.vexnum; ++j) {
			G.arcs[i][j] = Maxlnt;		//边的权值均置为极大值
			for (int k = 0; k < G.vexnum;++k) {
				cin >> v1 >> v2 >> w;	//输入一条边所依附的顶点及边的权值
				i = LocateVex(G, v1);
				j = LocateVex(G, v2);	//去顶v1和v2在G中的位置
				G.arcs[i][j] = w;		//边<v1, v2>的权值置为w
				G.arcs[j][i] = G.arcs[i][j];	//由于是无向图，置<v1,v2>的对称边<v2, v1>的权值置为w
			}	
		}
	}
	return true;
}//CreateUDN

//图G中查找顶点u，存在则返回顶点表中的下标，否则返回-1
int LocateVex(AMGraph G, VerTexType u)
{
	for (int i = 0; i < G.vexnum; ++i) {
		if (u == G.vexs[i]) {
			return i;   
		}
	}
	return -1;
}

int main021()
{
	system("pause");
	return 0;
}
















