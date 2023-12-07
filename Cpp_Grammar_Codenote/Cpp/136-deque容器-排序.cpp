/*
	功能描述:
	利用算法实现对deque容器进行排序

	算法：
	sort(iterator beg, iterator end) //对beg和end区间内元素进行排序
*/  
	
#include<iostream>
#include<deque>
#include<algorithm> //标准算法头文件
using namespace std;

void printDeque136(const deque<int>& d)
{
	for (size_t i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl; 
	//遍历方法之一
	//for (auto const& it : d)
	//{
	//	cout << it << " ";
	//}
}

void test136()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	//300 200 100 30 20 10
	printDeque136(d);

	//排序  sort()默认规则，从小到大
	//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
	//vector容器也可以利用sort()进行排序 
	sort(d.begin(), d.end());
	cout << "排序后： " << endl;
	printDeque136(d);

}

int main136()
{
	test136();
	system("pause");
	return 0;
}