#if 0
#include <iostream>
using namespace std;
#include <string>
#include <ctime>
//学生的结构体
struct Student
{
	string sName;
	int score;
};
//老师的结构体定义
struct Teacher
{
	//姓名
	string tName;
	//学生数组
	struct Student sArray[5];
	
};
//给老师和学生赋值的函数
void allocateSpace(struct Teacher tArray[], int len)
{
	string nameSeed = "ABCDE";
	//给老师开始赋值
	for (int i = 0; i < len; i++)
	{
		tArray[i].tName = "Teacher_";
		tArray[i].tName += nameSeed[i];

		//通过循环给每名老师所带的学生赋值
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].sName = "Student_";
			tArray[i].sArray[j].sName += nameSeed[j];

			int random = rand()%61 + 40;   //40-99  0到60之间的随机数+ 40 即，0-100之间
			tArray[i].sArray[j].score = random; 
		}
	}
}
//打印所有信息
void printInfo(struct Teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师姓名" << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名： " << tArray[i].sArray[j].sName
				<< "考试分数： " << tArray[i].sArray[j].score << endl;
		}
	}
}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	//1.创建3名老师的数组
	struct Teacher tArray[3];  

	//创建三名函数的数组
	//2.通过函数给3名老师的信息赋值，并给老师带的学生信息赋值
	int len = sizeof(tArray) / sizeof(tArray[0]);  
	allocateSpace(tArray, len);
	//3.打印所有老师及所带学生的信息
	printInfo(tArray, len);
	system("pause");
	return 0;
}
#endif


#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//学生结构体  姓名，分数
struct Student
{
	string sName;
	int score;
};
//老师结构体 姓名 学生信息
struct Teacher
{
	string tName;
	struct Student StudentArray[5];   //结构体嵌套结构体
};
//给老师和学生赋值的函数
void ImportInfo(struct Teacher TeacherArray[], int len)
{
	string nameSeed = "ABCDEF";  //为了生成不同老师A,B,C....
	for (int i = 0;i < len; i++)
	{
		TeacherArray[i].tName = "Teacher_";  
		TeacherArray[i].tName += nameSeed[i];  //字符串相加，例如i = 0时，Teacher_+'A'即Teacher_A

		for (int j = 0; j < 5; j++)
		{
			 TeacherArray[i].StudentArray[j].sName = "Student_:";  //产生不同学生编号
			 TeacherArray[i].StudentArray[j].sName += nameSeed[j]; //加上代表学生编号的字符，如Student_A
			 int random = rand() % 61 + 40;    //生成0-60的随机数，再加上40，即生成40-100的随机数
			 TeacherArray[i].StudentArray[j].score = random; //给学生分数赋值随机数
		}
	}
}
//输出打印老师学生信息
void ExportInfo(struct Teacher TeacherArray[], int len)
{
	for (int i = 0; i < len; i++)     //3个老师
	{
		cout << "老师姓名： " << TeacherArray[i].tName << endl;
		for (int j = 0; j < 5; j++)   //每个老师中五个学生信息
		{
			cout << "\t学生姓名： " << TeacherArray[i].StudentArray[j].sName
				 << " 学生分数： " << TeacherArray[i].StudentArray[j].score << endl;
		}
	}
}
int main43()  
{
	//创建老师结构体数组，学生结构体数组
	//struct Student StudentArray[5];
	struct Teacher TeacherArray[3];   //定义老师结构体数组
	srand((unsigned int)time(NULL));  //系统时钟配置，生成随机数
	//创建一个函数，向数组中输入老师，学生的信息
	//总长度/单个元素长度 = 数组元素个数，此处计算len = 3
	int len = sizeof(TeacherArray) / sizeof(TeacherArray[0]); 
	ImportInfo(TeacherArray, len);   //输入老师及其学生信息
	ExportInfo(TeacherArray, len);   //输出老师及其学生信息
	system("pause");
	return 0;
}
