/*

	功能:
	双端数组，可以对头端进行插入删除操作
	deque与vector区别:
	vector对于头部的插入删除效率低，数据量越大，效率越低。 
	deque相对而言，对头部的插入删除速度回Evector快。
	vector访问元素时的速度会比deque快,这和两者内部实现有关

	deque容器的迭代器也是支持随机访问的


	函数原型:
		deque<T> degT;//默认构造形式
		deque( beg, end);//构造函数将[beg,end)区间中的元素拷贝给本身
		deque(n, elem);//构造函数将n个elem拷贝给本身
		deque(const deque &deg);//拷贝构造函数
*/
#include <iostream>
#include <deque>
using namespace std;



void printDeque131(deque<int>& d)
{ 
	for (size_t i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl; 
}

void test131()
{
	deque<int>d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	cout << "d1 = ";
	printDeque131(d1);

	//将d1左闭右开的区间赋值给d2
	deque<int>d2(d1.begin(), d1.end());
	cout << "d2 = ";
	printDeque131(d2); 

	deque<int>d3(10, 100);
	cout << "d3 = ";
	printDeque131(d3);

	deque<int>d4(d3);    //将d3的值复制给d4
	cout << "d4 = ";
	printDeque131(d4);


}


int main131()
{
	test131();
	system("pause");
	return 0;
}


