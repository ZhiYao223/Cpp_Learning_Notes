/*
	功能描述:
	向容器中填充指定的元素
	函数原型:
	fill(iterator beg, iterator end, value);
	// 向容器中填充元素
	// beg 开始迭代器
	// end 结束迭代器
	// value 填充的值
*/
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

void myprint186(int val)
{
	cout << val <<" ";
}
//常用算术生成算法 fill
void test186()
{
	vector<int>v;
	v.resize(10);  //指定空间大小
	//后期重新填充指定元素
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), myprint186);
	cout << endl;

}
int main186()
{
	test186();
	system("pause");
	return 0;
}