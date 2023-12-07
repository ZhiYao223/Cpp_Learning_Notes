/*

	向deque容器中插入和删除数据
		函数原型:
		两端插入操作:
		push back(elem);		//在容器尾部添加一个数据
		push front(elem);		//在容器头部插入一个数据
		pop_back();				//删除容器最后一个数据
		pop_front();			//删除容器第一个数据  

		指定位置操作:
		insert(pos,elem);		//在pos位置插入一个elem元素的拷贝，返回新数据的位置.
		insert(pos,n,elem);		//在pos位置插入n个elem数据，无返回值。
		insert(pos,beg,end);	//在pos位置插入[beg,end)区间的数据，无返回值
		clear();				//清空容器的所有数据
		erase( beg ,end):		//删除[begend)区间的数据，返回下一个数据的位置
		erase( pos);			//删除pos位置的数据，返回下一个数据的位置


		总结：
		插入和删除提供的位置是迭代器！！！
		尾删、尾插、头插、头删：  push_back、pop_back、push_front、pop_front
*/
#include <iostream>
#include <deque>
using namespace std;

void printDeque134(const deque<int>& d)  //容器元素不可修改
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " "; //*it不可修改
	}

	//for (auto const& it : d)//遍历方式之一  
	//{
	//	cout << it << " "; 
	//}
	cout << endl; 
}
void test134_1()
{
	deque<int>d1; 
	//尾插
	d1.push_back(10);
	d1.push_back(20);

	//头插
	d1.push_front(100);
	d1.push_front(200);

	//200 100 10 20
	printDeque134(d1);

	//尾删   200 100 10
	d1.pop_back();
	printDeque134(d1);

	//头删    100 10
	d1.pop_front();
	printDeque134(d1);
}

void test134_2()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	//200 100 10 20
	printDeque134(d1);

	//insert插入  
	d1.insert(d1.begin(), 1000);
	//1000 200 100 20 10
	printDeque134(d1);

	d1.insert(d1.begin(), 2, 10000);
	//10000 10000 1000 200 100 20 10
	printDeque134(d1);


	//insert(d1.begin()+n, n, elem}; 随机访问插入

	//按照区间进行插入
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d2.push_back(4);
	d1.insert(d1.begin(), d2.begin(), d2.end()); //在d1的begin位置处，插入[d2.begin(), d2.end())区间中的元素
	////1 2 3 4 10000 10000 1000 200 100 20 10
	printDeque134(d1);


}

void test134_3()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	//删除 
	deque<int>::iterator it = d1.begin(); //迭代器指向第一个数据
	it++;        //指向第二个数据
	d1.erase(it);
	printDeque134(d1);

	//按区间删除
	d1.erase(d1.begin(), d1.end());
	//清空
	d1.clear();
	printDeque134(d1);
}

int main134()
{
	test134_1();
	cout << endl;
	test134_2();
	cout << endl;
	test134_3();
	system("pause");
	return 0;
}