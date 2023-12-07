#include <iostream>
using namespace std; 
int main21()
{
	//1.可以通过数组名统计整个数组占用内存大小
	int arr[10] = { 1,2,3,4,5,6,7,8,9,19 };
	cout << "整个数组占用内存空间为：" << sizeof(arr) << endl;
	cout << "每个元素占用内存空间为：" << sizeof(arr[0]) << endl;
	cout << "每个数组中元素个数为：" << sizeof(arr) / sizeof(arr[0])<< endl;   ///sizeof(arr[0]

	//2.可以通过数组名查看数组首地址
	cout << "数组首地址为：" << (int)arr << endl;
	cout << "数组中第一个元素地址为：" << (int)&arr[0] << endl;//相邻地址相差4个字节
	cout << "数组中第二个元素地址为：" << (int)&arr[1] << endl;

	system("pause");
	return 0;
}