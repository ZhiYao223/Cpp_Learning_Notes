/*
	C++提供两种模板机制：函数模版和类模版

	函数模版作用：
	建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，
	用一个虚拟的类型来代表

	语法：
	template<typename T>
	函数声明或定义

	template -----声明创建模版
	typename -----表明其后的符号是一种数据类型，可以用class代替
	T -------通用的数据类型，名称可以替换，通常为大写字母


*/
#include <iostream>
using namespace std;

//交换两个整数类型函数
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp; 
}

//交换两个浮点型函数
void swapfloat(float& a, float& b)
{
	double temp = a;
	a = b;
	b = temp; 
}

//函数模版
template<typename T> //声明一个函数模版，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T& a, T& b)    //类型参数化  提高复用性
{
	T temp = a;
	a = b;
	b = temp; 
}

int main97()
{
	int a = 10;
	int b = 20; 

	float c = 0.1;
	float d = 0.2;

	cout << "a = " << a << "\t b = " << b << endl;
	cout << "c = " << c << "\t d = " << d << endl;
	cout << "传统交换方法" << endl; 
	swapInt(a, b);
	cout << "a = " << a << "\t b = " << b << endl;
	swapfloat(c, d);
	cout << "c = " << c << "\t d = " << d << endl;

	cout << endl;


	cout << "a = " << a << "\t b = " << b << endl;
	cout << "c = " << c << "\t d = " << d << endl;
	cout << "使用函数模版进行交换" << endl;
	//两种方式使用模版 
	//1、自动类型推导   因为传入的a, b是int型，所以编译器会自行推导出int
	mySwap(a, b);  
	cout << "a = " << a << "\t b = " << b << endl;
	//2、显式指定类型
	mySwap<float>(c, d);
	cout << "c = " << c << "\t d = " << d << endl;

	system("pause");
	return 0;

}