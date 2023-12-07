//函数重载注意事项： 作用域为重载条件、函数重载碰到函数默认参数
//
//函数重载：同一个作用域，函数名相同；函数要么参数个数不同，要么参数类型不同、要么参数书顺序不同
//

#include <iostream>
using namespace std;
//函数重载的注意事项
//1.引用作为重载的条件

#if 0
//有无const可以作为重载条件
void func(int &a)  //func(10); =====>>  int &a = 10; 引用必须要一个合法的内存空间，要不在栈上，要不在堆上，10是在常量区，不合法                    //函数一
{
	cout << "func(int &a)调用" << endl; 
}

void func(const int& a)  //编译器优化： const int& a = 10; 合法         //函数二                函数一与函数二类型不同，可以重载func(a);调用的是函数一
{
	cout << "func(const int &a)调用" << endl; 
}
// int a = 10;  //此处a是一个变量，可读可写，但函数二加了const只能读不能写，
// func(a);     //则调用无const的第一个函数; 
//func(10);  //调用有const的函数二，函数自带常量
#endif


//2.函数重载碰到默认参数
#if 0
void func2(int a,int b)  //参数个数不同，能发生重载
{
	cout << "func2(int a, int b)的调用" << endl;
}
void func2(int a)  
{
	cout << "func2(int a)的调用" << endl;
}
#endif

#if 0
void func2(int a, int b = 10)            //两个参数
{
	cout << "func2(int a, int b)的调用" << endl;
}
void func2(int a)                     //一个参数
{
	cout << "func2(int a)的调用" << endl;
}
//func2(10)  error：两个个函数都可以调用，编译器不止如何处理，出现二义性
//当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况

//func2(10,20); 走第一个函数
#endif

int main54()
{
	//int a = 10;  //此处a是一个变量，可读可写，但函数二加了const只能读不能写，
	//func(a);     //则func(a);默认调用函数一类型

	//func(10);   //这种情况，默认调用函数二类型
 


	system("pause");
	return 0;
}