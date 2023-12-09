/*
	BF算法：Index(S,T,pos)
	将主串的第pos个字符和模式串的第一个字符比较。
	若相等，继续逐个比较后续字符
	若不等，从主串的下一字符起，重新与模式串的第一个字符比较。
	直到主串的一个连续子串字符序列与模式串相等，返回值为S中与T匹配的子序列第一个字符的序号，
	即匹配成功。否则，匹配失败。
*/
#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;


#if 0	//串的块链存储结构
#define CHUNKSIZE 80	//块儿的大小可由用户定义
typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct
{
	Chunk* head, * tail;	//串的头指针和尾指针
	int curlength;        //串的当前长度
}LString;             //字符串的块链结构
#endif 

#define MAXLEN 255

//串的定长顺序存储结构
typedef struct
{
	char ch[MAXLEN + 1];	//存储串的一维数组  MAXLEN加1是为了存储'\0'结束符， 从数组下标为0的位置开始存储第1个字符
	int  length;			//串的当前长度
}SString;					//字符串的顺序结构

//堆分配存储表示
typedef struct
{
	char* ch;	//按串长分配存储区，ch指向串的基地址
	int length;	//串的长度
}HString;

void InitStr(SString &S, const char* str);						//初始化串
int  StrInsert(SString &S, int pos, SString T);	//在S串的pos位置前插入子串T
void StrPrint(SString& S);						//打印字符串
bool StrCopy(SString& S, SString& T);			//将字符串T复制到串S
bool StrAssign(SString& S, const char* T);		// T为指向常量字符数组的指针，该常量字符不可修改
int  StringLength(const char* str);				//自定义的字符串长度计算函数
int  StrLength(const SString &S);						//求串S的长度
int  StrCompare(SString& S1, SString &S2); //S1大于S2返回1，小于返回0，
bool StrConcat(const SString& S1, const SString& S2, SString& T);//将串S1与S2联接成新的串T
bool SubStr(SString* Sub, int pos, int len, SString& S); //用Sub返回串S的第pos个字符起长度为len的子串
int  Index_BF(SString S, SString T, int pos);	//BF算法、朴素匹配算法
void Get_Next(SString T, int next[]);			//求模式串T的next数组
int  Index_KMP(SString S, SString T, int pos);			//KMP算法
bool StrEmpty(SString S);						//判断字符串是否为空
bool StrDelete(SString& S, int pos, int len);//从串S中删除第pos个字符起长度为len的子串

//初始化: 将str字符串转化成SString的形式，并更新字符串长度S.length
void InitStr(SString &S, const char* str)
{
	StrAssign(S, str);
}
//简单的模式匹配算法
int Index_BF(SString S, SString T, int pos)
{
	if (pos < 1 || pos > S.length)
	{
		cout << "输入有误！" << endl;
		return -1;
	}
	int i = pos, j = 0;
	while (i <= S.length && j < T.length)
	{
		if (S.ch[i-1] == T.ch[j])  //主串和子串依次匹配下一个字符
		{
			++i; ++j;//主串、子串指针回溯重新开始下一次匹配
		} 
		else { i = i - j + 1; j = 0; }//主串、子串指针回溯重新开始下一次匹配
	}
	if (j >= T.length)
		return i - T.length; //返回匹配的第一个字符的下标
	else
		return -1;	//模式匹配失败，说明文本串中不存在模式串，返回-1
}
//求模式串T的next数组 KMP算法中喜欢把数组第一位当作1
//next[j]：其值 = 第j位字符前面j-1位字符组成的子串的前后缀最大重合字符数+1
void Get_Next(SString T, int next[])  //参数2等同于int* next; 
{
	//i指向后缀末尾位置、j指向前缀末尾位置后一位；
	//j还代表着包括i及i之前的子串的最长相等前后缀长度
	int j = 0, i = 1;
	next[1] = 0;
	while (i<T.length)
	{
		if (j == 0 || T.ch[j] == T.ch[i])
		{
			++i; ++j;         //next数组下标j是指失配的位置，所以从1开始j
			//若pi = pj; 则next[j+1] = next[j] + 1
			next[i] = j;
		}
		else
			j = next[j];//否则令j = next[j], 循环继续
	}
}
//返回子串T在主串S中第pos个字符后的位置，若不存在，则函数返回-1。 1<= pos <=StrLength(S)
//KMP算法:本质就是主串指针不回溯，模式串指针每次回溯到最长公共前缀的下一位
//模式串中第j个位置与主串中第i个位置发生不匹配时，应从模式串中第next[j]个位置与主串第i个位置重新开始比较。
int  Index_KMP(SString S, SString T, int pos)
{
	int i = pos, j = 1;			//i用于主串S中当前位置下标，从pos位置开始后匹配；j用于子串T中当前位置下标值
	int next[MAXLEN + 1];		//定义next数组
	Get_Next(T, next);			//求模式串的next数组
	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])		////（两字母相等）或（next[j]=0即j=next[j]=0）时继续
		{
			++i;
			++j;			//继续比较后继字符
		}	
		else
			j = next[j];	//模式串向右移动，i不变, 把next数组下标赋值给j，即从数组下标位置开始匹配
	}
	if (j > T.length)
		return i - T.length;	//匹配成功
	else 
		return  -1;
}

//生成一个其值等于字符串常量chars的串S
bool StrAssign(SString &S, const char *T)	// T为指向常量字符数组的指针，该常量字符不可修改
{
	int len = 0;							//计算字符串长度
	while (T[len] != '\0' && len < MAXLEN)
	{
		S.ch[len] = T[len];  //字符串赋值
		len++;				//长度+1
	}
	S.ch[len] = '\0';	//手动添加字符串结束符
	S.length = len;	//设置字符串长度, 将len的值赋值给S的长度
	return true;		//操作成功
}
//字符串复制
bool StrCopy(SString& S, SString& T)  //将字符串T复制到串S
{
	//检查目标串的空间是否足够
	if (T.length < MAXLEN)		//目标串T的长度小于串S的最大长度
	{
		int len = 0;
		//赋值字符数组内容
		for (int len = 0; len <= T.length; len++)
		{
			S.ch[len] = T.ch[len];
		}
		S.length = T.length;	//设置字符串长度
	}
	return false;  //目标串长度大于S串最大空间，无法完成复制
}
//判断字符串是否为空
bool  StrEmpty(SString S)
{
	if (S.length == 0)
	{
		return true; 
	}
	return false;
}

int StrLength(const SString &S)  //求串S的长度
{
	//int length = 0;
	//while (S.ch[length] != '\0')
	//{
	//	length++;
	//}
	return S.length; 
}

//自定义的字符串长度计算函数
int StringLength(const char* str)
{
	int length = 0;
	while (*str != '\0')
	{
		length++;
		str++;  
	}
	return length;
}

//用T返回S1和S2联接而成的新串T，若未截断，则返回true,否则返回false
bool StrConcat(const SString &S1, const SString &S2, SString& T)
{
	//检查联接后的长度是否超过串T的最大限制
	if (S1.length + S2.length > MAXLEN)
	{
		//如果超过最大限制，截断联接并返回false
		//strncpy(T.ch, S1.ch, MAXLEN);
		T.ch[MAXLEN] = '\0';		//确保字符串以'\0'结尾
		T.length = MAXLEN;
		return false;  
	}
	// 如果未截断，完整连接字符串
	int i, j;
	for (i = 0; i < S1.length;i++)    //循环将S1复制到串T中
	{
		T.ch[i] = S1.ch[i];
	}
	T.length = S1.length;
	for (j = 0; j < S2.length; j++)   //再循环，将S2复制到串T中
	{
		T.ch[T.length] = S2.ch[j];
		++T.length;
	}
	T.length = S1.length + S2.length;
	return true;
}

bool SubStr(SString *Sub, int pos, int len, SString &S) //用Sub返回串S的第pos个字符起长度为len的子串
{
	if ((pos < 1) || (pos > S.length) || (len < 0) || (len > S.length - pos + 1))
	{
		//输入有误
		return false; 
	}
	int i = 0;
	while (i < len)
	{
		Sub->ch[i] = S.ch[pos - 1];//将串S中第pos个字符赋给Sub串
		++i;
		++pos; 
	}
	Sub->length = len;   //Sub接收的子串长度为len
	return true;  
}
//字符串比较，比较字符串大小
int StrCompare(SString& S1, SString &S2) //S1大于S2返回1，小于返回0，
{
	int i = 0;
	if (S1.length != S2.length)		//若S1与S2字符串长度不等，比较无意义
	{
		cout << "字符串长度不相等，比较无意义";
		return -1;		//退出函数
	}
	while ((S1.ch[i] == S2.ch[i]) && (S1.ch[i] != '\0') && (S2.ch[i] != '\0'))
	{
		i++; //遍历字符串
	}
	return (S1.ch[i] > S2.ch[i]); //S1大返回1  S1小返回0
}
//在串的S的第pos个字符之前插入串 T   第1个元素是数组下标为0的元素
//插入函数参数列表中不使用引用SString &S ，经过插入操作后原字符串S4就不会被修改, 这点非常重要！！！
int StrInsert(SString &S, int pos, SString T)	
{
	//pos=1表示在S串开头插入，pos=S.length+1表示在S串末尾插入，即最后元素的下一位之前插入
	if (pos < 1 || (pos > S.length+1)) 
	{
		return false;	//插入位置不合法
	}
	if (S.length + T.length > MAXLEN)
	{
		return false;	//插入后串的长度超过最大限制MAXLEN
	}
	//数组最后一个元素的下标应为 S.length-1，代表第 S.length 个字符。
	//相应地，在插入操作时，如果 pos > S.length + 1，则表示插入位置不合法。
	for (int i = (S.length - 1); i >= pos - 1;i--)  
	{
		S.ch[i + T.length] = S.ch[i];//将串中第pos及之后的字符后移T.length个位置，腾出空间
	}
	for (int j = 0; j < T.length; j++)
	{
		S.ch[pos-1+j] = T.ch[j];  //将串T放入串S腾出来的长度为T.length的空间中
	}
	S.length = S.length + T.length;//更新插入T后S串的长度
	return true;
}
//从串S中删除第pos个字符起长度为len的子串
bool StrDelete(SString& S, int pos, int len)
{
	if (pos<1 || pos>(S.length - len + 1))   //pos<1,或者删除位置pos离串尾不足len个元素
	{
		return false;	
	}
	for (int i = 0; i <= len; i++) //第pos个字符的下标为pos-1 以此类推。
	{
		S.ch[pos - 1 + i] = S.ch[pos - 1 + len + i];  
	}
	S.length = S.length - len; //更新S的长度，超过S.length后的字符串会被省略
	return true;  //删除成功
}
//打印字符串
void StrPrint(SString &S)
{
	if (!StrEmpty(S))			//字符串不为空
	{
		for (int i = 0; i < S.length;i++)   //遍历字符串
		{
			cout << S.ch[i];
		}
		return;
	}
	cout << "字符串为空！";
	return;
}
int main15()
{
	SString S;
	SString T;
	SString R;
	SString S1;
	SString S2;
	SString S3;
	SString S4;
	SString S5;
	SString S6;

	char ch[] = { "hello" };
	char ch1[] = { "zello, world" };
	char ch2[] = { "hello, world" };

	InitStr(S, "hello zhiyao");
	InitStr(T, "Hello Zhiyao");
	InitStr(S1, ch1);	
	InitStr(S2, ch2);
	InitStr(S3, "zhiyao,");
	InitStr(S4, "Hello,");
	InitStr(S5, "How are you ? ");

	cout << "串S:";
	StrPrint(S);
	cout << endl << "串T:";
	StrPrint(T);
	cout << endl; 

	cout << "串S1的长度为：" << S1.length << endl;
	cout << "串S2的长度为：" << S2.length << endl;
	cout << "S1与S2字符串比较结果：";
	cout << ((StrCompare(S1, S2))==1)?  "S1大于S2" : ((StrCompare(S1, S2) == -1) ? "二者长度不等！" : "S1小于S2"); cout << endl;
	cout << "串S:";
	StrPrint(S);
	cout << "的长度为：" << S.length << endl;

	cout << "在串S4的第七个位置之前插入S3:";
	cout << endl << "插入前S4为:";		   StrPrint(S4);
	cout << endl << "插入子串S3为：";		   StrPrint(S3);
	StrInsert(S4, 7, S3);         //插入函数参数列表中不使用引用&，经过插入操作后原字符串S4就不会被修改,这点非常重要！！！
	cout << endl << "插入后S4为：";         StrPrint(S4);

	cout << endl << "S4为:";		   StrPrint(S4);
	cout << endl << "S3为：";	   StrPrint(S3);
	StrConcat(S3, S4, R);
	cout << endl << "将串S4与串S3联接成新串R：";
	StrPrint(R);

	cout << endl << "S5为：";	StrPrint(S5);
	StrCopy(S6, S5);
	cout << endl << "将S5复制到S6的结果,S6为：";
	StrPrint(S6);

	cout << endl << "将串S3插入S6开头：";
	StrInsert(S6, 1, S3);
	cout << endl << "插入后S6为:";
	StrPrint(S6);

	cout << endl << "用Sub返回串S3的第1个字符起长度为6的子串:";
	SubStr(&S3, 8, 3, S6);
	StrPrint(S3);

	cout << endl;
	SString S7;
	cout << "串S6为:";
	StrPrint(S6);
	InitStr(S7, "How");
	cout << endl;
	cout << "串S6的长度为：" << S6.length << endl;
	cout << "串S7的长度为：" << S7.length << endl;
	cout <<"暴力匹配后结果："<< Index_BF(S6, S7, 1) << endl;


	SString S8;
	SString S9;
	InitStr(S8, "abcabaaaabaabcac");
	InitStr(S9, "abaabcac");
	StrPrint(S8);  cout << endl;
	StrPrint(S9);  cout << endl;
	cout << "串S8的长度为：" << S8.length << endl;
	cout << "串S9的长度为：" << S9.length << endl;
	cout << "KMP算法结果：" << Index_KMP(S8, S9, 1) << endl;
	cout << endl;
	system("pause");
	return  0;
}




