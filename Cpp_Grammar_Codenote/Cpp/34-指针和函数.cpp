#include <iostream>
using namespace std;
int main34()
{
	//指针和数组
	//利用指针访问数组中的元素
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "第一个元素为：" << arr[0] << endl;
	int* p = arr;//arr就是数组首地址
	cout << "利用指针访问第一个元素：" << *p << endl;
	p++;//让指针向后偏移4个字节,
	cout << "利用指针访问第二个元素：" << *p << endl;

	cout << "利用指针遍历数组:" << endl;
	int* p2 = arr;                      //用指针找到首地址
	for (int i = 0; i < 10;i++)
	{
		//out << arr[i] << "\t";
		cout<<"第"<<i+1<<"个数为：" << *p2 << endl;
		p2++;                           //移动四个字节，每四个字节一个数据
	}
	system("pause");
	return 0;
}