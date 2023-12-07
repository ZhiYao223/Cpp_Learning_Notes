#if 0
#include<iostream>
using namespace std;


/*
	1.初始化HT[1.....2n-1]: lch = rch = parent = 0;
	2.输入初始n个叶子结点：置HT[1....n]的weight值；
	3.进行以下n-1次合并，依次产生n-1个结点HT[i], i = n+1....2n-1:
	  a)在H[1..i-1]中选两个未被选过的weight最小的两个结点HT[s1]和HT[s2], s1、s2为两个最小结点下标；
	  b)修改HT[s1]和HT[s2]的parent值，HT[s1].parent=i; HT[s2].parent = i;
	  c)修改新产生的HT[i]:
		HT[i].weight = HT[s1].weigth + HT[s2].weigth;
		HT[i].lch = s1; HT[i].rch = s2;
*/
typedef struct
{
	int weigth;
	int parent, lch, rch;
}HTNode, *HuffmanTree;

HuffmanTree H; //定义一个数组

//构造哈夫曼树----哈夫曼算法
void CreateHuffmanTree(HuffmanTree HT, int n)
{
	if (n <= 1)	return;
	int m = 2 * n - 1;	//数组共2n-1个元素
	HT = new HTNode[m + 1];	//0号单元未使用，HT[m]表示根结点
	for (int i = 1; i < m;++i)
	{
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
	}
	for (int i = 0; i <= n; ++i)
	{
		cin >> HT[i].weigth;	//输入n个元素的weight值
	}
	//初始化结束，下面开始建立哈夫曼树
	for (int i = n + 1; i <= m;i++)
	{
		Select(HT, i - 1, s1, s2);//在HT[k]中选择两个双亲域为0
		HT[s1].parent = i;
		HT[s2].parent = i; //表示从F中删除s1,s2
		HT[i].lch = s1; 
		HT[i].rch = s2;		//s1,s2分别作为i的左右孩子
		//i的权值为左右孩子权值之和
		HT[i].weight = HT[s1].weight + HT[s2].weigth;
	}
}
#endif
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<string>
using namespace std;
//宏定义
#define N 30
#define Max 2*N-1

//创建结构体
typedef struct
{
	double weigth;	//结点权值
	char s;	//所代表的字符，例如：程序输入样例中的m,n,c
	//定义每个结构体中的关系，父亲左孩子，右孩子、方便后面建立哈夫曼
	int parent, lchild, rchild;
}HTNode, HuffmanTree[Max+1];//默认哈夫曼树有Max+1个结点

/*函数定义*/
void Select(HuffmanTree ht, int x, int* m1, int* m2); //找出森林集合中权限值最小的两个

void CreateHuffmanTree(HuffmanTree ht, int n);//构建哈夫曼树

void HuffmanCoding(HuffmanTree ht, char** hc, int n);//哈夫曼树

void PrintHuffmanCoding(HuffmanTree ht, char** hc, int index);//先序打印

void HuffmanDecoding(HuffmanTree ht, int n, char* pwd);//在生成的哈夫曼编码中查询目标

/*找出森林集合中权限值最小的两个*/
void Select(HuffmanTree ht, int x, int* m1, int* m2)
{
	//选出两最小的两个下标,初始化为极大的数来查找最小的两个数
	double min1 = 99999999;
	double min2 = 99999999;
	/* ht[j]不断后移，其权值与min1进行比较，使得min始终为已查找的数中最小的那个*/
	for (int j = 1; j <= x;j++)
	{
		if (ht[j].weigth < min1 && ht[j].parent == 0)
		{
			min1 = ht[j].weigth;
			*m1 = j; 
		}
	}
	/*在已经查找到最小的数min1的前提下查找不等于min1的最小数min2*/
	/*ht[k]不断后移，与min2比较，若ht[k]小于已知的min2，且不为min1，那ht[k]的权值替换min2*/
	for (int k = 1; k <= x; k++)
	{
		if (ht[k].weigth < min2 && k != *m1 && ht[k].parent == 0)
		{
			min2 = ht[k].weigth;
			*m2 = k; 
		}
	}
}

/*构建哈夫曼树*/
void CreateHuffmanTree(HuffmanTree ht, int n)
{
	//n为用户在主函数中输入的字符个数，即为后面构建哈夫曼树的叶子结点个数
	for (int i = 0; i <= 2 * n - 1; i++)
	{
		int m1, m2;
		Select(ht, i - 1, &m1, &m2);//调用Select函数，查找两个根结点最小的数，并赋值给m1,m2
		//从n+1开始创建新的根
		ht[i].weigth = ht[m1].weigth + ht[m2].weigth;//构建新结点ht[i],权值为ht[m1]和ht[m2]的和
		ht[i].lchild = m1;//新结点ht[i]的左孩子为m1,因为题目要求：左右孩子中较小值为左孩子
		ht[i].rchild = m2;//同理，第二小的结点为新父亲结点的右孩子
		ht[m1].parent = i;//赋值，结点ht[m1]的父亲结点地址为i
		ht[m2].parent = i;//赋值，结点ht[m2]的父亲结点地址为i
	}
}
/*哈夫曼树编码*/
void HuffmanCoding(HuffmanTree ht, char** hc, int n)
{
	char* cd = (char*)malloc(n * sizeof(char)); //cd临时存放哈夫曼编码
	cd[n - 1] = '\0';//根结点编码为空
	int now = 1;//此时正在编码的结点
	int p = 0;	//正在编码结点的父亲结点
	int start;	//此时编码存放在数组中的位置
	int i = 0;
	/*外层循环用于初始化，更换需要编码的的结点*/
	while (i < n)
	{
		start = n-1;//编码永远在数组中指定位置开始存放
		now = n + 1;//随着while循环的推进，编码的起点也在更换
		p = ht[now].parent;//父亲结点初始化为now结点的父亲位置
		/*内层循环用于获取指定结点的编码*/
		while (p != 0)
		{
			start--;
			if (ht[p].lchild == now) //结点是其父亲结点的左子树并赋值为0，右为1
			{
				cd[start] = '0';
			}
			else
			{
				cd[start] = '1';
			}
			now = p; //此时的结点为原来的父亲结点
			p = ht[now].parent;	//更新父亲结点
		}
		hc[i + 1] = (char*)malloc((n - start) * sizeof(char));//开辟存放编码数组的内存
		strcpy(hc[i + 1],  &cd[start]);//传指针复制编码
		i++; 
	}
}
/*先序打印*/
void PrintHuffmanCoding(HuffmanTree ht, char** hc, int index)
{
	//递归输出前序遍历序列
	if (index >= 1)//如果这是叶子结点，那么输出它的字符以及编码
	{
		if (ht[index].lchild == 0 && ht[index].rchild == 0)
		{
			cout << ht[index].s << " " << hc[index] << endl; 
			return;
		}
		PrintHuffmanCoding(ht, hc, ht[index].lchild);//递归，继续查找遍历
		PrintHuffmanCoding(ht, hc, ht[index].rchild);
	}
}

/*在生成的哈夫曼树中查找目标*/
void HuffmanDecoding(HuffmanTree ht, int n, char* pwd)
{
	//从根结点出发，是0走左子树，1走右子树，直到遇到叶子结点，再从根结点出发
	cout << "original:";
	int len = strlen(pwd);//获取用户输入编码的长度
	int i = 0;
	int node = 2 * n - 1; //初始化为从根结点出发
	while (i < len)
	{
		if (pwd[i] == '0')
		{ //0 走左子树
			node = ht[node].lchild;//更新当前结点
			i++;
			if (ht[node].lchild == 0 && ht[node].rchild == 0)
			{//如果这是叶子结点，输出此叶子结点的字符
				cout << ht[node].s << endl;
				node = 2 * n - 1;//重新从根结点出发，继续译码
			}
		}
		if (pwd[i] == '1') //是1，走右子树
		{
			node = ht[node].rchild;
			i++;
			if (ht[node].lchild == 0 && ht[node].rchild == 0)
			{
				cout << ht[node].s << endl; 
				node = 2 * n - 1; 
			}
		}
	}
}
//哈夫曼编码实现
int main20()
{
	
/*
	HuffmanTree ht;
	int n = 0;	//输入字符个数
	cin >> n; //用户输入，获取n
	getchar();

	char* hc[n + 1];
	for (int i = 1; i <= n;i++)
	{
		cout << ht[i].s << " " << ht[i].weigth << endl; 
		getchar();
		ht[i].lchild = 0;
		ht[i].rchild = 0;
		ht[i].parent = 0;
	}
	char pwd[9999];	//需要译码的字符串
	cout<< "pwd: " << pwd << endl;//获取字符串
	//创建二叉树
	CreateHuffmanTree(ht, n);
	//编码
	HuffmanCoding(ht, hc, n);
	//前序输出
	PrintHuffmanCoding(ht, hc, 2 * n - 1);
	//译码
	HuffmanDecoding(ht, n, pwd);
	*/
	system("pause");
	return 0;
}