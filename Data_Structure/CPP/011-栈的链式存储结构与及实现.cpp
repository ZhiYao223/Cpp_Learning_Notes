#if 0
#include<iostream>
using namespace std;

#define MaxSize 100
typedef int SElemType;

//链栈的存储结构
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode, *LinkStack;
//声明了一个结构体StackNode, 表示链栈中的结点，包含data和next指针
// 用LinkStack定义一个指向StackNode结构体的指针类型。

bool InitStack(LinkStack& stack);   //空栈
bool PushStack(LinkStack& stack, SElemType value); //入栈
bool PopStack(LinkStack& stack, SElemType &value); //出栈
SElemType GetStack(LinkStack& stack); //读栈顶元素
bool StackTraverse(LinkStack& stack); //遍历输出栈元素

//stack 是一个指向链栈的指针，但在函数 InitStack 中它被当作栈顶指针处理。
//这是因为在链式栈中，栈顶指针通常用来指向链表的第一个节点，它代表了当前栈中最顶部的元素。
//在链栈的实现中，可以把 stack 视为栈顶指针，通过它来访问栈顶元素，并且进行入栈和出栈操作。
//因此，在 InitStack 函数中，将栈顶指针 stack 置空，表示初始化一个空栈。
//链栈的初始化
bool InitStack(LinkStack& stack)  //构造一个空栈stack 栈顶指针置空
{
	stack = NULL;     //栈顶指针置空
	return true; 
}

//链栈的入栈
bool PushStack(LinkStack& stack, SElemType value)
{
	//在栈顶插入元素value， 链栈不需要判断栈满
	StackNode* newNode = new StackNode;
	newNode->data = value;
	newNode->next = stack;
	stack = stack->next;
	delete newNode;
	return true; 
}

///出栈操作
bool PopStack(LinkStack& stack, SElemType& value)
{
	if (stack == NULL)   //判断是否为空栈
	{
		return false; 
	}
	value = stack->data;
	StackNode* p = stack; 
	stack = stack->next;
	delete p;
	return true; 
}

//取栈顶元素操作:判断栈是否为空、若空则返回false； 返回value获取栈顶元素的值
SElemType GetStack(LinkStack& stack)
{
	//返回stack的栈顶元素，不修改栈顶指针
	if (stack != NULL)     //非栈空时返回
	{
		return  stack->data;
	}
	return false;
}

//遍历输出链栈
bool StackTraverse(LinkStack& stack)
{
	StackNode* p = stack;
	if (p == NULL)
	{
		cout << "链栈为空！" << endl;
		return false; 
	}
	cout << "栈顶->";
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next; 
	}
	cout << endl;
	return true; 
}

int main()
{
	LinkStack stack;
	int value, choice;
	InitStack(stack);

	while (1)
	{
		cout << "\t 1.入栈 \t 2.出栈 \t 3.读栈顶元素 \t 4.输出栈 \t 0.退出" << endl;
		cout << "选择要进行的操作：";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "输入入栈元素："; cin >> value; break; 
		case 2: 
			if (!PopStack(stack, value))
			{
				cout << "出栈失败！" << endl;
			} 
			else   cout << "元素" << value << "出栈成功！" << endl;break; 
		case 3:
			if (!GetStack(stack, value))
				cout << "读栈顶元素失败！" << endl;
			else
				cout << "栈顶元素为：" << value << endl;
			break;
		case 4:
			StackTraverse(stack);
			break;
		case 0: return true;
		default:
			return true;
		}
	}
	return 0;
}
#endif
/*
1.栈的链式存储不需要附设头节点
2.链头为栈顶，链尾为栈底
3.链栈不需要判断栈满，但要判空
4.因为是动态分配空间，所以需要释放
5.时间性能与顺序栈相同，空间性能不懒顺序栈有元素个数限制和空间浪费，
但又因每个元素都需要一个指针域会增加结构性开销。
总之，看情况，，，
*/
#if 0
#include<iostream>
using namespace std;

typedef int SElemType;

typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode, *LinkStack;
//LinkStack 是指向 StackNode 结构体的指针类型，表示链栈的栈顶指针。

/* 链栈的初始化 */
//LinkStack top 是一个变量，表示链栈的栈顶指针。
//这里的 top 只是一个普通的变量，存储了链栈的栈顶指针的值。
void InitStack(LinkStack& top)
{
	top->next = NULL; //top指针指向栈顶元素的上一个位置
}

//判断栈是否为空
bool StackEmpty(LinkStack& top)
{
	if (top->next = NULL)
	{
		return true; 
	}
	return false; 
}

//元素入栈
bool PushStack(LinkStack& top, SElemType value)
{
	LinkStack temp;
	temp = (LinkStack)malloc(sizeof(StackNode));
	if (temp == NULL)
	{
		return false; 
	}
	temp->data = value;
	temp->next = top->next;
	top->next = temp;
	return true; 
}

//元素出栈
int PopStack(LinkStack top, SElemType& value)
{
	if (StackEmpty(top))
	{
		return false; 
	}
	StackNode* temp = top->next;
	value = temp->data;
	top->next = temp->next;
	free(temp);
	return true; 
}

//获取栈顶元素
int GetStack(LinkStack top, SElemType value)
{
	if (top->next == NULL)
	{
		return false; 
	}
	value = top->next->data;
	return true; 
}

int main()
{
	LinkStack stack;
	int result;
	stack = (LinkStack)malloc(sizeof(StackNode));
	InitStack(stack);
	for (int i = 1; i <= 10; i++)
	{
		PopStack(stack, i);
	}

	GetStack(stack, result);
	cout << "栈顶元素为：" << result << endl; 
	
	cout << "元素依次出栈：" << " ";
	while (!StackEmpty(stack))
	{
		PopStack(stack, result);
		cout << result << endl;
	}
}
#endif

//链栈是运算受限的单链表、只能在链表头部进行操作
/*
	1.链表的头指针就是栈顶
	2.不需要头结点
	3.基本不存在栈满的情况
	4.空栈相当于头指针指向空
	5.插入和删除仅在栈顶处执行
*/
#include<iostream>
using namespace std;

#define MaxSize 100     //链栈的最大长度
typedef int SElemType;  //链栈的数据元素类型假设为int整型
//创建链栈结构
typedef struct StackNode 
{
	SElemType data;   //结点数据域
	struct StackNode* next;//结点指针域
}StackNode, *LinkStack;//struct StackNode的结点形式、链栈形式别名

LinkStack stack;   //创建栈顶指针指向链栈的头结点

bool InitStack(LinkStack& stack);//初始化链栈
bool StackEmpty(LinkStack& stack);//链栈判空
bool PushStack(LinkStack& stack, SElemType value);//入栈
bool PopStack(LinkStack& stack, SElemType& value);//出栈
SElemType GetTop(LinkStack& stack);//获取栈顶元素
bool StackPrint(LinkStack& stack);//遍历元素
void DestoryStack(LinkStack& stack);//销毁链栈，释放内存
int StackLength(LinkStack& stack);//计算链栈长度/元素个数

//链栈的初始化
bool InitStack(LinkStack& stack)
{
	//构造一个空栈、栈顶指针置为空
	stack = NULL;
	return true; 
}

//判断链栈是否为空
bool StackEmpty(LinkStack& stack)
{
	if (stack == NULL)
	{
		return true; 
	}
	return false;
}

//链栈的入栈
bool PushStack(LinkStack& stack, SElemType value)   //不用判栈满
{
	StackNode* temp = new StackNode; //生成新结点temp
	temp->data = value; //将新节点数据域置为value
	temp->next = stack; //将新结点插入栈顶
	stack = temp; //更新栈顶指针
	return true;
}

//链栈的出栈：首先判空
bool PopStack(LinkStack& stack, SElemType &value)
{
	if (StackEmpty(stack))
	{
		return false; 
	}
	value = stack->data;  //将栈顶数据域元素赋值给value
	//LinkStack temp1 = new StackNode;
	//StackNode* temp = new StackNode;
	StackNode* temp = stack; //创建一个temp指针，并将其指向 stack 指针所指向的内存地址，以便找到出栈位置并释放。
	stack = stack->next; //令栈顶指针指向下一位结点，即更新栈顶指针
	delete temp;   //释放temp所指向的空间，即出栈元素所占的内存空间,而temp本身会在函数结束后自动销毁。
	return true;  
}

/*
	LinkStack temp1 = new StackNode;
	这里 LinkStack 是一个指针类型别名，实际上是 StackNode* 的别名。
	所以 temp1 是一个指针变量，指向 StackNode 类型的结点。

	StackNode* temp2 = new StackNode;
	这里直接声明了一个 StackNode* 类型的指针变量 temp2，指向 StackNode 类型的结点。

	这两种声明方式是等价的。两者都创建了一个动态分配的 StackNode 类型的结点，并将它的地址赋给相应的指针变量。两者都可以通过 temp1->data 或 temp2->data 来访问结点的数据成员，以及 temp1->next 或 temp2->next 来访问结点的下一个结点的指针成员。
	因此，在功能上，temp1 和 temp2 没有区别。不同的只是它们的声明方式，temp1 是通过别名 LinkStack 来声明的指针变量，而 temp2 是直接以 StackNode* 类型来声明的指针变量。
	*/

//取栈顶元素
SElemType GetTop(LinkStack& stack)
{
	if (!StackEmpty(stack))  //若栈不为空
	{
		return stack->data;  //返回栈顶元素
	}
	return false; 
}


/*
因为链表的最后一个节点的next指针是nullptr（或者说是NULL），代表链表的终止，所以可以将链表的遍历条件设置为当前节点指针不等于nullptr，这样在遍历过程中，当指针指向最后一个节点时，其next指针就会指向nullptr，循环条件就不再成立，遍历结束，可以避免继续遍历下一个不合法的节点。
*/
//获取栈顶长度
int StackLength(LinkStack& stack)
{
	int length = 0;
	StackNode* temp = stack;//创建临时指针temp与stack指向同一位置
	while (temp != nullptr)
	{
		length++;  //链栈长度即为栈中元素个数，循环一次，长度++
		temp = temp->next; //temp指针下移一位
	}
	return length; //返回链栈长度
}
//遍历栈元素
bool StackPrint(LinkStack& stack)
{
	if (stack != nullptr)
	{
		StackNode* temp = stack;//创建一个指针与stack指向同一位置
		cout << "出栈顺序：";
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;  //temp向下移动一位
		}
		return true;  //遍历完毕
	}
	cout << "栈为空！" << endl;
	return false;
}

//销毁链栈，释放内存
void DestoryStack(LinkStack& stack)
{
	StackNode* temp = new StackNode;//创建一个指针
	while (stack != nullptr)
	{
		temp = stack;//使该临时指针与stack指向同一位置
		stack = temp->next;//更新栈顶指针
		delete temp;//释放临时指针
	}
	stack = nullptr;
	return;
}

//测试代码
int main11()
{
	//创建链栈
	LinkStack stack;
	SElemType value;

	InitStack(stack);
	cout << "检查栈是否为空？" << (StackEmpty(stack) ? "\t是" : "\t否") << endl;

	int number = 0;//插入元素个数
	int num = 0; //插入元素值
	cout << "请输入需要插入的元素个数：";
	cin >> number;
	while ((number--) > 0) //计数
	{
		cin >> num;//输入数据
		PushStack(stack, num);//插入所输入元素
	}
	cout << "当前栈的元素个数：" << StackLength(stack) << endl; 
	cout << "获取栈顶元素：" << GetTop(stack) << endl;
	StackPrint(stack); //遍历打印栈顶元素

	cout << endl;
	PopStack(stack, value); //出栈
	cout << "出栈一次后栈顶元素为：" << GetTop(stack) << endl;
	StackPrint(stack);//遍历打印链栈元素

	DestoryStack(stack);
	cout << endl << "栈已被销毁释放" << endl;

	cout << "销毁栈后打印输出结果：" <<" ";
	StackPrint(stack);
	cout << "销毁栈后遍历栈结果：" << " ";
	StackPrint(stack);

	system("pause");
	return 0;
}


