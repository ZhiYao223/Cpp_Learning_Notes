/*
	

*/
#include<iostream>
#include<list>
using namespace std;

void printList145(list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl; 
}

void test145_1()
{
	//反转
	list <int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);
	cout << "反转前：" << endl; 
	printList145(L1);

	L1.reverse();
	cout << "反转后：" << endl;
	printList145(L1);
}

//sort降序
bool  myCompare(int v1, int v2)
{
	//降序，就让第一数 > 第二个数
	return v1 > v2;
}

void test145_2()
{
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);
	//排序
	cout << "排序前：" << endl;
	printList145(L1);

	//所有不支持随机访问迭代器的容器，都不可以用标准算法
	//不支持随机访问迭代器的容器，内部会提供一些对应算法
	//sort(L1.begin(), L1.end());  
	 
	L1.sort();    //默认排序规则，从小到大，升序
	cout << "排序后:" << endl;
	printList145(L1);

	L1.sort(myCompare);    //降序排列
	printList145(L1);

}
int main146()
{
	test145_2();
	system("pause");
	return 0;
}