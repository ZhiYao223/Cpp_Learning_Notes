#include <iostream>
using namespace std;
int main7()
{
	//创建bool数据类型 ture代表真
	bool flag = true;
	cout << flag << endl;

	//false代表假
	flag = false;
	cout << flag << endl;

	//本质上1代表真，0代表假
	//查看bool类型所占内存空间
	cout << "bool类型所占内存空间：" << sizeof(bool) << endl;

	system("pause");
	return 0;
}