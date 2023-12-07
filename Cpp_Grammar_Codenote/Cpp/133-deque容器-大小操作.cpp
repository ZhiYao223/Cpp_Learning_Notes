/*
功能描述:
。对deque容器的大小进行操作
函数原型:
deque.empty();				//判断容器是否为空
deque.size();				//返回容器中元素的个数
deque.resize(num);			//重新指定容器的长度为num,若容器变长，则以默认值填充新位置
							//如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem);	//重新指定容器的长度为num,若容器变长，则以elem值填充新位置
							//如果容器变短，则未尾超出容器长度的元素被删除。
*/
#include <iostream>
#include <deque>
using namespace std;

//deque容器大小操作

void printDeque133(deque<int>& d)
{
	for (size_t i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl; 
}

void test133()
{
	deque<int>d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque133(d1);

	if (d1.empty())
	{
		cout << "d1为空" << endl; 
	}
	else
	{
		cout << "d1不为空" << endl;
		cout << "d1的大小为：" << d1.size() << endl; 
		//deque没有容器的概念capacity
	}

	//重新指定deque大小
	d1.resize(15, 1);  //超出的部分用1来填充
	printDeque133(d1);

	d1.resize(5);
	printDeque133(d1);
}

int main133()
{
	test133();
	system("pause");
	return 0;
}