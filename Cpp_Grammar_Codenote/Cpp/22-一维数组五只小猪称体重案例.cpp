#include <iostream>
using namespace std;
int main22()
{
	int arr[5] = { 200,350,400,150,250 };
	int max = arr[0];                    //初始化max
	cout << "五只小猪的体重分别为：";
	for (int i = 0;i < 5;i++)
	{
		cout << arr[i] << " ";
		//如果访问的数组中的元素比认定的最大值还大，更新最大值
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	cout << "\n最重的小猪体重为：" << max << endl;
	return 0;
}