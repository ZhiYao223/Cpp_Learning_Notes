/*
	调用规则如下：
	1、如果函数模版和普通函数都可以实现，有限调用普通函数
	2、可以通过空膜拜参数列表来强制调用函数模版
	3、函数模版也可以发生重载
	4、如果函数模版可以产生更好的匹配，有限调用函数模版

	总结：既然提供了函数模版，最好就不要提供普通函数，否则容易出现二义性
*/

#include <iostream>
using namespace std; 

void myPrint(int a, int b)
{
	cout << "调用的普通函数" << endl; 
}

template<class T>
void myPrint(T a, T b)
{
	cout << "调用的函数模版" << endl; 
}

//函数模版重载后的调用
template<class T>
void myPrint(T a, T b, T c)
{
	cout << "调用的重载的函数模版" << endl;
}


void test101_1()
{
	int a = 10;
	int b = 20;
	int c = 30;
	//普通函数 函数模版都能调用，优先调用普通函数
	//如果普通函数只有声明，没有实现即没有函数体，则报错
	myPrint(a, b);  

	//通过空模版参数列表，强制调用函数模版
	myPrint<>(a, b); //此时调用函数模版

	myPrint<>(a, b, c); //调用重载的函数模版 

	//如果函数模版产生更好的匹配，优先调用函数模版
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2); //该行普通函数和函数模版都可以调用，但编译器认为：
					//如果调用普通函数，则需要把字符'a', 'b'转化成ASCII码int型，再执行。因此编译器会选择调用T匹配度更高的函数模版
}

int main101()
{
	test101_1();
	system("pause");
	return 0;
}