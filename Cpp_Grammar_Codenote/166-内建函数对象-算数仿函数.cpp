/*
	STL
	功能描述:
实现四则运算:
其中negate是一元运算，其他都是二元运算仿函数原型:
template<class T> T plus<T> //加法仿函数

template<class T> T minus<T>//减法仿函数

template<class T> T multiplies<T>//乘法仿函数

template<class T> T divides<T>//除法仿函数

template<class T> T modulus<T>//取模仿函数

template<class > T negate<T>//取反 仿函数
*/
#include<iostream>
#include<functional>
using namespace std;
//negate
void test166_1()
{
	negate<int> n;
	cout << n(50) << endl; 
}
//plus
void test166_2()
{
	plus<int>p;
	cout << p(10, 20) << endl;
}

int main166()
{
	test166_1();
	test166_2();
	system("pause");
	return 0;
}