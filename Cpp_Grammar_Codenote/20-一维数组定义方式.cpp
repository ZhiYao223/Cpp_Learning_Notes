//数据类型 数组名[];
//数据类型 数组名[数组长度]=｛值1，值2，值3...｝;
//数据类型 数组名[] = {值1，值2，值3...};

#include <iostream>
using namespace std;
#define key1   1
#define key2   0
#define key3   0
int main20()
{
#if key1
	int num[5] = { NULL };             //初始化
	for (int i = 0;i <= 4;i++)
	{
		num[i] = 10 + 10 * i;
		cout << num[i] << endl;
	}
	return 0;
#endif

#if key2
	int arr1[5] = { 10,20,30,40,50 };//
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << endl;
	}
	return 0;
#endif

	//如果在初始化数据时，没有全部填写完，会用0来填补剩余数据
	//int arr2[5] = { 10,20,30 };  //后门两个数会自动补齐0

#if key3
	int arr3[] = { 90,80,70,60,50,40,30,20,10 };
	for (int i = 0;i < 9;i++)
	{
		cout << arr3[i] << endl;
	}
	return 0;
}
#endif
}