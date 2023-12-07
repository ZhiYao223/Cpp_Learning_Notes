#include <iostream>
using namespace std;
#include <string>
//结构体指针
struct student
{
	string name; 
	int age;
	int score;
};

int main39()
{
	//1.创建学生结构体变量
	struct student s = { "张三", 18, 100 };

	//2.通过指针指向结构体变量
	//int* p = &s;      //error
	student *  p = &s;  //p为结构体类型指针变量
	//3.通过指针访问结构体变量中的数据 s.name   p->  与（*p)等价
	//通过结构体指针，访问结构体中的属性，需要利用'->'
	cout << "姓名：" << p->name << "  年龄 " << p -> age << "  分数：" << p->score << endl;

	system("pause");
	return 0;
}