/*
	功能描述：给vector容器进行赋值

	函数原型：
	vector& operator = (const vector &vec);  //重载等号操作符
	assign(beg, end);  //将【beg,end)区间内的数据拷贝赋值给本身
	assign(n, elem);  //将n个elem拷贝赋值给本身

	vector赋值方式比较简单，使用operator= 或者assign都可以
*/

#include<iostream>
#include<vector>

using namespace std;
void printVector(vector<int>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
//vector赋值
void test125_1()
{
	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//operator= 赋值操作
	vector<int> v2;
	v2 = v1;
	printVector(v2);

	//assign
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());  //左闭右开，能取v1.begin()至v1.end()的上一位
	printVector(v3);

	//n个elem方式赋值
	vector<int>v4;
	v4.assign(10, 100);
	printVector(v4);    //打印10个100 

}

int main125()
{
	test125_1();
	system("pause");
	return 0;
}
