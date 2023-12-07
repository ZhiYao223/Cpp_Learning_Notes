/*
	功能描述： 给list容器进行赋值，以及交换list容器

	函数原型：
	assign(beg,end);      //将[beg,end]区间中的数据拷贝赋值给本身
	assign(n, elem);      //将n个elem拷贝赋值给本身
	list& operator = (const list &lst);  //重载等号操作符
	swap(lst);                     //将lst与本身的元素互换

	总结： list容器的赋值和交换灵活应用即可
*/

#include <iostream>
#include <list>
using namespace std; 

//list容器赋值和交换

void printList143(list<int>& L)  //list容器是双向链表，不能使用">", "<"比较大小
{
	
	//for (size_t i = 0; i<L.size(); i++)
	//{
	//	cout << L[i] << " ";
	//}
	//cout << endl;
	for (auto const& it : L)
	{
		cout << it << " ";
	}
	cout << endl;
}

//赋值
void test143_1()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList143(L1);

	list<int>L2;
	L2 = L1; //operator= 赋值
	printList143(L2);

	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList143(L3);

	list<int>L4;
	L4.assign(10, 100);
	printList143(L4);

}

//交换
void test143_2()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int>L2;
	L2.assign(10, 100);

	cout << "交换前:" << endl;
	printList143(L1);
	printList143(L2);

	cout << "交换后:" << endl; 
	swap(L1, L2);  //交换容器L1,L2内的元素
	printList143(L1);
	printList143(L2);

}
int main143()
{
	test143_1();
	test143_2();
	system("pause");
	return 0;
}
