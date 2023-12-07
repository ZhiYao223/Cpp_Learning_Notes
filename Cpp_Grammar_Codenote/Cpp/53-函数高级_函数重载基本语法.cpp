//作用：函数名可以相同，提高复用性
//函数重载满足条件
//1.同一个作用域下， main外或main内，全局或局部
//2.函数名相同
//3.函数参数类型不同，或者个数不同，或者顺序不同
//注意：函数的返回值不可以作为函数重载的条件

#include <iostream>
using namespace std;

void func()                                          //函数一
{
	cout << "func的调用!" << endl;
}
void func(int a)             //参数类型不同          //  函数二
{
	cout << "func(int a)的调用！" << endl; 
}
void func(double a)                                //函数三
{
	cout << "func(double a)的调用！" << endl;
}
void func(int a, double b)       //参数个数不同        //函数四
{
	cout << "func(int a, double b)的调用！" << endl;
}
void func(double a, int b)      //参数顺序不同        //函数五
{
	cout << "func(double a, int b)的调用！" << endl;
}
//int func(double a, int b)  //函数的返回值不可以作为函数重载的条件，void与int类型    //函数六
//{
//	cout << "func(double a, int b)";
//}
int main53()
{
	func();      //调用第一个函数
	func(10);  //调用第二个函数
	func(3.14);//调用第三个函数
	func(10, 3.14); //调用第四个函数
	func(3.14, 10); //调用第五个函数
	system("pause");
	return 0;
}