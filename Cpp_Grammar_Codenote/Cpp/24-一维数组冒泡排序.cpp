#if 0
#include <iostream>
using namespace std;
//比较相邻的元素，如果第一个比第二个大，就叫交换他们两个
//对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值
int main()
{
	//利用冒泡排序实现升序序列
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };//9个元素
	cout << "排序前：" << endl;
	for (int i = 0;i < 9;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	//开始冒泡排序
	//总共排序轮数为 元素个数-1
	for (int i = 0;i < 9 - 1;i++)
	{
		//内层循环对比，次数=元素个数 -当前轮数-1
		for (int j = 0;j < 9 - i - 1;j++)
		{
			//如果第一个数字，比第二个数字大，交换两个数字
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp; 
			}
		}
	} 
	//排序后结果
	cout << "排序后结果：" << endl;
	for (int i = 0;i < 9;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
#endif

#include <iostream>
using namespace std;
int main24()
{
	//给出一串元素，并打印
	int arr[9] = { 3,4,2,7,5,9,6,8,1 };
	cout << "元素排序前：" << " ";
	//数组中元素个数
	int num = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < num ;i++)
	{
		cout << arr[i] << "  ";
	}

	//进行冒泡排序,总共排序轮数 = 元素个数-1   i表示当前第i轮排序
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1;j++)    //j表示当轮排序中，第j个元素
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	//排序后结果，打印输出
	cout << "\n元素排序后：" << " ";
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;

}