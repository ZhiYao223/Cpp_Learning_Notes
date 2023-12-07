#include <iostream>
using namespace std;


//占位参数
//返回值类型	  函数名（数据类型）｛｝
//占位参数，还可以有默认参数，如fuc1函数
void func2(int a, int = 10)
{
	cout << "this is value：" << a << endl;
}

void func1(int a, int)  //第二个int占位
{
	cout << "this is value: "<< a << endl;
	
}
int main52()
{
	func1(10, 10); //第二个10函数拿不到，只是占位作用
	func2(10);
	system("pause");
	return 0;
}