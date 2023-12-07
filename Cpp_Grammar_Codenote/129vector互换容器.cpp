/*
	实现两个容器元素进行互换
	swap(vec); //将vec与本身的元素互换
*/
#include<iostream>
#include<vector>
using namespace std;

//vector容器互换

void printVector129(vector<int>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl; 
}

//1.基本用法
void test129_1()
{
	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "交换前：" << endl;
	printVector129(v1);

	vector<int>v2;
	for (size_t i = 9; i < 10; i--)
	{
		v2.push_back(i);
	}
	printVector129(v2);

	cout << "交换后："<<endl;
	v1.swap(v2);
	printVector129(v1);
	printVector129(v2);


}



//2.实际用途
//巧用swap可以收缩内存空间
void test129_2()
{
	vector<int>v;
	for (size_t i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}

	cout << "v的容量为： " << v.capacity() << endl;
	cout << "v的大小为： " << v.size() << endl;
	cout << endl;

	v.resize(5);//重新指定大小    //容量不变、大小变为5
	cout << "v的容量为： " << v.capacity() << endl;
	cout << "v的大小为： " << v.size() << endl;
	cout << endl;

	//巧用swap收缩内存
	vector<int>(v).swap(v);
	cout << "v的容量为： " << v.capacity() << endl;
	cout << "v的大小为： " << v.size() << endl;

}


int main129()
{

	test129_1();
	test129_2();
	system("pause");
	return 0;
}
