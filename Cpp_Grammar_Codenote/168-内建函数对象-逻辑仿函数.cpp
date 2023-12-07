/*
*	功能描述：实现逻辑运算
	 函数原型:
	template<class T> bool logical and<T>//逻辑与
	template<class T> bool logical_or<T>//逻辑或
	template<class T> bool logicalnot<T>//逻辑非

	算法transform可以把一个容器中的数据全部搬运到另一个容器中
	总结：逻辑仿函数实际应用较少，了解即可
*/
#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>
using namespace std;

void printVector168(vector<bool>&v)
{
	for (auto const& it : v)
	{
		cout << it << " ";
	}
	cout << endl; 
}

//逻辑非 logical_not
void test168()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	printVector168(v);

	//利用逻辑非 将容器v搬运到容器v1中， 并执行取反操作
	vector<bool>v1;
	v1.resize(v.size()); //目标容器开辟与v同样大小的空间
	transform(v.begin(), v.begin(), v1.begin(), logical_not<bool>()); 
	printVector168(v1);


}
int main168()
{
	test168();
	system("pause");
	return 0;
}