
//函数的分文件编写
//实现两个数字进行交换的函数
////函数的声明
//void swap(int a, int b);
////函数的定义
//void swap()
//{
//	int temp = a;
//	a = b;
//	b = temp; 
//	cout << "a = " << a << endl; 
//	cout << "b = " << b << endl;
//
//}
//创建.h后缀的头文件
//创建.cpp后缀的源文件
//在头文件中写函数声明
//在源文件中写函数定义

#include <iostream>
using namespace std;
#include "swap.h"

int main29()
{
	int a = 10;
	int b = 20;
	swap(a, b);
	return 0;
}
