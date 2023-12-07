#include <iostream>
using namespace std;
#include <string>
//定义学生结构体
struct student
{
	string name;
	int age;
	int score;
};
//定义老师结构体
struct teacher
{
	int id;     //教师编号
	string name;//教师姓名
	int age;     //教师年龄
	struct student stu;   //辅导的学生
};

int main40()
{
	//结构体嵌套结构
	//创建老师
	//
	teacher t;      //定义老师结构体变量
	t.id = 10000;
	t.name = "老王";
	t.age = 50;
	t.stu.name = "小王";//老师的学生姓名
	t.stu.age = 20;     //老师学生年龄 
	t.stu.score = 80;   //老师学生分数
	
	cout << "老师姓名： " << t.name << "  教师职工编号： " << t.id << "  老师年龄： " << t.age
		<< "  老师辅导的学生姓名： " << t.stu.name << "  学生年龄 " << t.stu.age
		<< "  学生考试分数：" << t.stu.score << endl;

	system("pause");
	return 0;
}
//在结构体中可以定义另一个结构体作为成员，用来解决实际问题