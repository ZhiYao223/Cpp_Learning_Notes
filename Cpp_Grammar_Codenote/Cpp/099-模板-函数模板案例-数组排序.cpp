/*
	案例描述
	利用函数模版封装一个排序的函数，可以对不同数据类型数组进行排序
	排序规则从大到小，排序算法为选择排序
	分别利用char数组和int数组进行测试
*/
#include <iostream>
using namespace std;
//实现通用 对数组进行排序的函数
//规则从大到小 算法选择排序
//测试 char数组， int数组
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp; 
}
//提供打印数组模版
template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "  ";
	}
}
//排序算法
template<class T >
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)    
		{
			//认定的最大值比遍历出的数值要小，说明j下标的元素才是真正的最大值
			if (arr[max] < arr[j])
			{
				max = j; //更新最大值下标
			}
		}
		if (max != i)
		{
			//交换max和i元素
			mySwap(arr[max], arr[i]);
		}
	}
}
//测试char数组
void test99_1()
{
	char charArr[] = "bdcegfa";
	int length = sizeof(charArr) / sizeof(char);
	mySort(charArr, length);
	printArray(charArr, length);
}
//测试int数组
void test99_2()
{
	int intArr[] = { 4,2,6,3,5,1,8,9,7 };
	int length = sizeof(intArr) / sizeof(int);
	mySort(intArr, length);
	printArray(intArr, length);
}

int main99()
{
	test99_1();

	cout << endl << endl << endl << endl;

	test99_2();
	system("pause");
	return 0;
}



