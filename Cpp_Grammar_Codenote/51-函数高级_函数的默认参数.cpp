#include <iostream>

using namespace std;

//函数默认参数  如果传入数据，就用自己的数据，如果没有，就用默认值
//语法： 返回值类型  函数名（形参 = 默认值）
int func(int a, int b = 20, int c = 30)  //c++规定默认参数从右边开始赋值
{
	return a + b + c;
}

//1.如果某个位置已经有了默认参数，那么从这个位置起，从左往右都必须有默认值
//int func2(int a, int b = 10, int c, int d)  //error: b有默认参数，那么c,d也必须有
//int func2(int a=10, int b, int c, int d)  //error: a有默认参数，那么b,c,d也必须有
int func2(int a, int b = 10, int c = 20, int d = 30)  //right: b有默认参数，那么c,d也必须有
{
	return a + b + c + d;
}
//注意事项：

//2.如果函数的声明有默认参数，那函数实现就不能有默认参数
//函数声明和实现只能有一个有默认参数，若都有，编译器不知道如何选择，即报错
int func3(int a=10, int b=10);
//int func3(int a=20, int b=20)  //error
int func3(int a, int b)      //函数声明有默认值，则函数实现就不能有
{
	return a + b;
}
int main51()
{
	cout << func(10) << endl;    //b,c有默认值，可以只传递a的值a=10  结果：10+20+30=60
	cout << func(10, 30) << endl; //尽管形参b有默认值，也可通过函数传递，函数实参的优先级高于形参默认值，即a = 10; b = 30;  结果为10+30+30=70
	
	cout << func3(30, 30) << endl;//函数声明已经有默认值10  10; 但优先使用传递值30 30;
	system("pause");
	return 0;
}