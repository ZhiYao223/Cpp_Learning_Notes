/*
	功能描述： ma容器进行插入和删除数据
	函数原型:
		insert(elem);		//在容器中插入元素。
		clear();			//清除所有元素
		erase(pos);			//删除pos迭代器所指的元素，返回下一个元素的迭代器。
		erase(beg,end);		//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
		erase(key);			//删除容器中值为kev的元素	
		
*/

#include<iostream>
#include<map>
using namespace std;

void printMap158(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << "value = " << (*it).second << endl; 
	}
	cout << endl;
}

void test158()
{
	map<int, int>m;      //插入时会按key值排序容器中的元素
	//第一种
	m.insert(pair<int, int>(1, 4));
	//第二种  推荐
	m.insert(make_pair(2, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(3, 20));
	//第三种
	m.insert(map<int, int>::value_type(5, 30));
	//第四种
	m[4] = 40;//[]不建议， 用途：可以利用key访问到value  cout<<m[4]<<endl; 
	printMap158(m);
	
	//删除
	m.erase(m.begin());
	printMap158(m);

	//删除单个元素
	m.erase(3);  //按key删除元素
	printMap158(m);

	//删除区间
	//m.erase(m.begin(), m.end());
	printMap158(m);
	m.clear();   //清空
}

int main158()
{
	test158();
	system("pause");
	return 0;
}