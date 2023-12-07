/*
函数模版注意事项：
1、自动类型推导，必须推导出一致的数据类型T才可以使用
2、模版必须要确定出T的数据类型，才可以使用

*/
#include <iostream>
using namespace std;

//函数模版
template<typename T> //声明一个函数模版，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T& a, T& b)    //类型参数化  提高复用性
{
	T temp = a;
	a = b;
	b = temp;
}
//1、自动类型推导，必须推导出一致的数据类型T才可以使用
void test98()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	mySwap(a, b); //正确
	//mySwap(a, c); //错误 a 和 c不是一个类型
	cout << "a = " << a << "\t b = " << b << endl;
}

//2、模版必须要确定出T的数据类型，才可以使用
template<class T>
void func98()
{
	cout << "func调用" << endl; 
}



int main98()
{
	//func98();//错误，没有确定的T数据类型
	func98<int>(); //正确，函数定义中没有说明类型，即任意T都可以
	return 0;
}