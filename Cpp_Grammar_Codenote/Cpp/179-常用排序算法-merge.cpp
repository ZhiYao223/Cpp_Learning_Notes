/*
	功能描述：两个容器元素合并，并存储到另一容器中
	函数原型:

	merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
	// 客元素合并，并存储到另一容器中
	// 注意: 两个容器必须是有序的 且必须都是一个顺序，默认为升序  
	//假如两个都是降序，则merge中需要加上谓词参数，Greater<int>(),以便达到降序合并

	// beg1 容器1开始选代器
	// end1容器1结束迭代器
	// beg2容器2开始迭代器
	// end2容器2结束迭代器
	// dest目标容器开始迭代器   

	//合并的两个容器必须是有序序列
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

void myprint179(int val)  //打印容器元素
{
	cout << val << " ";
}
void test179()
{
	vector<int>v1;
	vector<int>v2;

	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
	}
	cout << "容器1中的元素为：";
	//random_shuffle(v1.begin(), v1.end());  //打乱容器序列  如果打乱，会报错
	
 
	for_each(v1.begin(), v1.end(), myprint179); //遍历容器元素
	cout << endl;


	cout << "容器2中的元素为：";
	//random_shuffle(v2.begin(), v2.end());   //打乱容器序列
	for_each(v2.begin(), v2.end(), myprint179);
	cout << endl;

	vector<int>v3;    //如果不指定v3容器的大小，会报错

	v3.resize(v1.size() + v2.size()); //分配 目标容器大小为v1+v2的大小

	cout << "合并后的元素："; 
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), myprint179);
}
int main179()
{
	srand((unsigned int)time(NULL)); //随机数种子
	test179();
	system("pause");
	return 0;
}