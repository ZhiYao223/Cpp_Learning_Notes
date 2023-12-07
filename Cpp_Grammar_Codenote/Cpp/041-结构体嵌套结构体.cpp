#include <iostream>
using namespace std;


//学生结构体定义
struct student
{
	string name;
	int age;
	int score;
};
//打印学生信息的函数
void printStudent1(struct student s)   //值传递
{
	s.age = 100;     //修改年龄
	cout << " 子函数中打印 姓名：" << s.name << "  年龄: " << s.age << "  分数：" << s.score << endl;
}
//地址传递
void printStudent2(struct student * p)//将s的地址传递给结构体指针变量p
{
	//值传递用.name, 指针传递用p->name
	p->name = 100;
	cout << "子函数2中 姓名： " << p->name << "年龄： " << p -> age << "分数： " << p->score << endl;

}
int main41()
{
	//结构体做函数参数，将学生传入到一个参数中，打印学生身上的所有信息
	struct student s;
	s.name = "张三";
	s.age = 20;
	s.score = 90;

	printStudent1(s);   //值传递
	//printStudent2(&s);    //地址传递
	cout << "main函数中打印 姓名：" << s.name << " 年龄: " << s.age << " 分数：" << s.score << endl;

	system("pause");
	return 0;
}

//值传递不改变实参，地址传递改变实参