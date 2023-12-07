/*
	功能描述：set容器进行插入数据和删除数据

	函数原型：
			insert(elem);	//在容器中插入元素
			clear();		//清除所有元素
			erase(pos);		//删除pos迭代器所指的元素，返回下一个元素的迭代器.
			erase(beg,end);	//删除区间[beg,end)的所有元素，返回下一个元素的迭代器
			erase(elem);	//删除容器中值为elem的元素

*/
#include<iostream>
#include<set>
using namespace std;

void printSet150(set<int>& s)
{
	for (auto const& it : s)
	{
		cout << it << " ";
	}
	cout << endl;
	
	//for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
}

void test150()
{
	set<int>s1;
	//插入
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);	
	s1.insert(40);   //插完会自动排序
	
	//遍历
	printSet150(s1);   //10 20 30 40

	//删除
	s1.erase(s1.begin());
	printSet150(s1);  //20 30 40 

	//删除重载版本
	s1.erase(30);
	printSet150(s1);
	
	//清空
	//s1.erase(s1.begin(); s1.end());
	s1.clear();
	printSet150(s1);
	
}

int main150()
{
	test150();
	system("pause");
	return 0;
}