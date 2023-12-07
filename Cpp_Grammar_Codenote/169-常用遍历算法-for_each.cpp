/*
	算法主要是由头文件<algorithm> <functiona1> <numeric>组成
	<algorithm》是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
	<nuneric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
	<functiona1>定义了一些模板类用以声明函数对象
	
	学习目标： for_each实际开发中最常用的遍历算法，必须掌握
	for_each //遍历容器
	transform //搬运容器到另一个容器中
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//普通函数
void print169_1(int val)
{
	cout << val << " ";
}

//仿函数
class print169_2
{
public:
	void  operator()(int val)
	{
		cout << val << " ";
	}
};

void test169()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print169_1);  //普通函数：传入函数名
	
	cout << endl;
	
	for_each(v.begin(), v.end(), print169_2());  //仿函数：传入匿名函数对象 
	  
}


int main169()
{
	test169();
	system("pause");
	return 0;
}
