/*
	vector容器预留空间
	功能描述：
	减少vector在动态扩展容量时的扩展次数

	函数原理：
	reserve（int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问

*/

#include<iostream>
#include<vector>
using namespace std;


void test130()
{
	vector<int>v;

	//预留空间
	v.reserve(100000);
	int num = 0; //统计扩容次数
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p != &v[0])   //用p指针跟踪容器的第一个元素地址，若发生扩容，则二者地址不等。
		{
			p = &v[0];  //再令其相等，等待下一次不相等的时候，说明再次扩容
			num++;      //纪录扩容的次数
		}
	}
	cout << "num = " << num << endl; 
}


int main130()
{
	test130();
	system("pause");
	return 0;
}