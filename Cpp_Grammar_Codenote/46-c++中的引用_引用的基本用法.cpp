//语法：数据类型 &别名 = 原名
//引用：给变量起别名
//int &b = a;  b = 20; cout << a <<endl;    a,b都是20，修改的是同一块内存

#include <iostream>
using namespace std;
int main46()
{
	//引用必须初始化， int &b;  错误的
	//引用一但初始化后，就不可以更改了

	int a = 10;
	int &b = a;    //引用必须初始化 b=a=10
	cout << "a = " << a << endl;
	cout << "b = " << b << endl << endl;

	int  c = 20;   //错误，一旦初始化后，就不可更改
	//int &b = c;    //b已经是a的别名，不能再改成c的别名

	int d = 20;    //引用在初始化后，不可以改变 
	b = d;         //这是赋值操作，不是更改引用   a=b=20=d

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	system("pause");
	return 0;
}