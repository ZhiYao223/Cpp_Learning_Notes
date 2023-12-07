#include <iostream>
using namespace std;
#include <string>
//1.结构体定义
struct Student
{
	//成员列表
	//姓名
	string name;
	//年龄
	int age;
	//分数
	int score;
};


int main38()
{
	//struct 结构体名 数组名[元素个数] = { {}, {}, {}, {}}
	//2.创建结构体数组
	struct Student stuArray[3] = {
		{"张三",18 ,100},
		{"李四",20 ,99},
		{"王五",23, 88}
	};
	//3.给结构体数组中的元素赋值(修改数组元素)
	stuArray[2].name = "赵六";
	stuArray[2].age = 80;
	stuArray[2].score = 60;

	//4.遍历结构体数组
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名： " << stuArray[i].name
			 << "年龄： " << stuArray[i].age 
			 << "分数:  " << stuArray[i].score << endl;
	}
	system("pause");
	return 0;
}