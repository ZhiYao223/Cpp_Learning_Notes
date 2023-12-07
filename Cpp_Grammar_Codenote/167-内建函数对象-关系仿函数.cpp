/*
	功能描述:实现关系对比
	仿函数原型:
	template<class T> bool equal to<T>		//等于
	template<class T> bool not_equal_to<T>	/不等于
	template<class T> bool greater<T>		//大于   最常用
	template<class T> bool greater_equal<T>//大于等于
	template<class T> bool less<T>			//小于
	template<class T> bool less_equal<T>	//小于等于
	内建仿函数是给内置数据类型用的，谓词是给自定义数据类型用的
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Mycompare167
{
public:
	bool operator()(int val1, int val2 )
	{
		return val1 > val2;
	}
};
void printVector167(vector<int>& v)
{
	for (auto const& it : v)
	{
		cout << it << " ";
	}
	cout << endl;
}
//内建函数对象——关系仿函数
//大于greater
void test167()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);
	printVector167(v);   //无序
	//降序
	//  sort(v.begin(), v.end(), Mycompare167());

	sort(v.begin(), v.end(), greater<int>()); //通过内建仿函数创建函数对象 效果等同于上一行
	printVector167(v);   //降序
}

int main167()
{
	test167();
	system("pause");
	return 0;
}