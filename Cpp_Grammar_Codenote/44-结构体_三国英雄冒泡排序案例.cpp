#include <iostream>
#include <string>
using namespace std;
//1.创建英雄结构体
struct Hero
{
	string name;
	int age;
	string sex;
};
//2.冒泡排序函数
void HeroSort(struct Hero HeroArray[], int len)//  HeroArray[]等价于 *HeroArray     HeroArray[1] = *(HeroArray+1)
{
	for (int i = 0; i < len - 1; i++)      //len-1 为总排序轮数
	{
		for (int j = 0; j < len - i - 1; j++)  //len-i-1 为当轮排序中第几个元素
		{
			//如果j下标的元素年龄大于j+1下标的元素年龄，则交换两个元素
			if (HeroArray[j].age > HeroArray[j + 1].age)
			{
				struct Hero temp = HeroArray[j]; //易错点，不是string temp
				HeroArray[j] = HeroArray[j + 1];
				HeroArray[j + 1] = temp;
			}
		}
	}
}
//3.结果打印函数
void HeroPrint(struct Hero HeroArray[], int len)  //若采用指针传递，该如何编写？
{
	cout << "排序后结果： " << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "\t姓名：" << HeroArray[i].name
			 << "  年龄：" << HeroArray[i].age
			 << "  性别：" << HeroArray[i].sex << endl;
	}	
	//return;
}

int main44()
{
	//创建结构体数组，存放五名英雄
	struct Hero HeroArray[5] = { {"刘备",25,"男"},
		                         {"关羽",27,"男"},
		                         {"张飞",24,"男"},
		                         {"赵云",21,"男"},
		                         {"马超",23,"男"}};
	//计算结构体数组长度
	int len = sizeof(HeroArray) / sizeof(HeroArray[0]);
	//打印排序后结果
	cout << "排序前结果： " << endl;
	HeroPrint(HeroArray, len);   //输出排序前信息
	HeroSort( HeroArray, len);   //进行冒泡排序
	HeroPrint(HeroArray, len);   //输出排序后信息
	system("pause");
	return 0;
}

//思考为什么排序替换时不能这样写？ 为什么是struct Hero temp 而不是 string temp?
#if 0
if (HeroArray[j].age > HeroArray[j + 1].age)
{
	string temp1 = HeroArray[j].name;
	HeroArray[j].name = HeroArray[j + 1].name;
	HeroArray[j + 1].name = temp1;

	int temp2 = HeroArray[j].age;
	HeroArray[j].age = HeroArray[j + 1].age;
	HeroArray[j + 1].sex = temp2;

	string temp3 = HeroArray[j].sex;
	HeroArray[j].sex = HeroArray[j + 1].sex;
	HeroArray[j + 1].sex = temp3;


}
#endif