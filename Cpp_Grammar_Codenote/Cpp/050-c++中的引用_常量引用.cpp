#include <iostream>

using namespace std;

//引用使用的场景，通常用来修饰形参
void Showvalue(const int& b)
{
	//b += 10;    //error: 引用形参加了const, b就不能被修改，否则报错. 这样可以保护main中的实参
	cout << b << endl; 
}
int main50()
{
	//int& ref = 10; 引用本身需要一个合法的内存空间，此行错误
	//加入const就可以了，编译器会优化代码： int temp = 10; const in& ref = temp;
	const int& ref = 10;

	//ref = 100;//加入const后不可以修改变量
	cout << ref << endl; 

	//函数中利用常量引用防止误操作修改实参
	int a = 10;
	Showvalue(a);
	//加入
	system("pause");
	return 0;
}