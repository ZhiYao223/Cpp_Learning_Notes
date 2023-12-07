#include <iostream>
using namespace std;
#include <string>
//学生结构体定义
struct student
{
	string name;
	int age;
	int score;
};

//const使用场景，加const
//将函数中的形参改为指针，可以减少内存空间，而且不会复制新的副本出来
void printStudent(const student * s)  //常量指针，若对齐进行赋值修改，则报错，
{
									  //stu->age = 100;//操作失败，因为加了const修饰
	//若没有加const，通过地址传递，利用指针可以修改main中的实参变量的值，是不安全的操作，为了避免发生修改，加const
	//s->age = 150;  
	//加入const后，一旦有修改的操作就会报错，可以防止我们的误操作
	cout << "姓名： " << s->name << " 年龄：" << s->age << " 分数： " << s -> score << endl;

}

int main42()
{
	//创建结构体变量
	struct student s = { "张三", 15, 70 };
	//通过函数打印结构体变量

	printStudent(&s);   //值传递，结构体学生变量的地址传递给指针变量p

	cout << "main中张三的年龄为：" << s.age << endl;   
	system("pause");
	return 0;
}