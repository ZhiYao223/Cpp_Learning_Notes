#define MaxSize 20   //存储空间初始分配量
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];//数组，存储数据元素
	int length; //线性表当前长度
}SqList;

#define OK 1
#define ERROR 0
typedef int Status;

Status GetElem(SqList L, int i, ElemType* e)  //将线性表L中的第i个位置元素返回给e
{
	if (L.length == 0 || i < 1 || i>L.length)
	{
		return ERROR;
	}
	else
	{
		*e = L.data[i - 1];
		return OK;
	}
}


Status ListInsert(SqList* L, int i, ElemType e)
{
	if (L->length == MaxSize)   //顺序线性表已满
	{
		return ERROR;
	}
	if (i <1 || i>L->length + 1)  //因为i>L->length时，可以插到表尾。
	{
		return ERROR;
	}
	if (i < L->length)
	{
		for (int k = L->length - 1; k > i - 1;k--)
		{
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

//删除操作
Status ListDelete(SqList* L, int i, ElemType* e)
{
	if (L->length == 0)
		return ERROR;
	if (i<1 || i>L->length)
		return ERROR;
	*e = L->data[i - 1];
	if (i <= L->length)
	{
		for (int k = i; k < L->length; k++)
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}

//线性表的单链表存储结构
typedef struct Node
{
	ElemType data;
	struct  Node* next;

}Node;

