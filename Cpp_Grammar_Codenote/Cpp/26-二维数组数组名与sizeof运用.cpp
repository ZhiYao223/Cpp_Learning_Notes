//查看二维数组所占内存空间
//获取二维数组首地址
#include <iostream>
using namespace std;
int main26()
{
	//二维数组名称用途
	int arr[2][3] = { {1,2,3}, {4,5,6} };
	cout << "二维数组占用内存空间为：" << sizeof(arr) << endl;
	//查看一行所占内存空间
	cout << "二维数组第一行所占内存为：" << sizeof(arr[0]) << endl;
	cout << "二维数组第一个元素占用内存为：" << sizeof(arr[0][0]) << endl;

	cout << "二维数组行数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组的列数：" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	//2.可以查看二维数组的首地址
	cout << "二维数组首地址为：" << (int)arr << endl;
	cout << "二维数组第一行首地址：" << (int)arr[0] << endl;
	cout << "二维数组第二行首地址为：" << (int)arr[1] << endl;

	//arr[0][0]表示一个数，所以要取地址需加上&字符
	cout << "二维数组第一个元素首地址：" << (int)&arr[0][0] << endl;
	cout << "二维数组第二个元素首地址：" << (int)&arr[0][1] << endl;

	system("pause");
	return 0;
}