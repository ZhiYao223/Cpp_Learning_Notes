#include <iostream>
using namespace std;
int main23()
{
	int arr[5] = { 1,3,2,5,4 };
	cout << "数组元素逆置前：";
	for (int i = 0;i < 5;i++)
	{
		cout << arr[i] << "\t";
	}
	int start = 0;//起始下标
	//在不知道数组元素个数的情况下，可以用数组总长度/单个数据字节长度 再减1，即为下标末尾序号
	int end = sizeof(arr) / sizeof(arr[0]) - 1;   //计算结束下标， 总长度除以单个字节长度，等于数组数据个数

	while (start < end)
	{
		//实现元素互换
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++; end--;
	}
	//打印逆置后的结果
	cout << "\n数组元素逆置后: ";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] <<"\t";
	}
	return 0;
}

#if 0
1.创建数组
2.实现逆置
2.1 纪录起始下标位置
2.2 纪录结束下表位置
2.3 起始下标与结束下标的元素互换
2.4 起始位置++ 结束位置--
2.5 循环执行2.1操作，直到起始位置>=结束位置
#endif