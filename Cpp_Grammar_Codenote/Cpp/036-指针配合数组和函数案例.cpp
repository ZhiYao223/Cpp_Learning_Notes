#include <iostream>
using namespace std;
//冒泡排序函数，参数1 数组首地址   参数2  数组长度
void bubbleSort(int * arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			//如果j>j+1的值，交换数值
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp; 
			}
		}
	}
}
//输出打印排序后的数组元素
void printArray(int* arr, int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << arr[i] << "  ";
	}
}

int main36()
{
	//1.创建数组
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

	//数组长度
	int len = sizeof(arr) / sizeof(arr[0]);

	//2.创建函数，实现冒泡排序
	bubbleSort(arr, len);
	printArray(arr, len);

	cout << endl;
	system("pause");
	return 0;
}