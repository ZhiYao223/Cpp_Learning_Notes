/*
	函数原型:
			push_back(elem);//在容器尾部加入一个元素。
			pop_back();//删除容器中最后一个元素。
			push_front(elem);//在容器开头插入一个元素。
			pop_front();//从容器开头移除第一个元素
			insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置.
			insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
			insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
			clear();//移除容器的所有数据
			erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置
			erase(pos);//删除pos位置的数据，返回下一个数据的位置。
			remove(elem);//删除容器中所有与elem值匹配的元素			
*/

#include<iostream>
#include<list>
using namespace std;

void printList144(list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl; 
}

void test144()
{
	list<int> L;
	L.push_front(30);
	L.push_front(20);
	L.push_front(10);
	L.push_back(40);
	L.push_back(50);
	L.push_back(60);
	//10 20 30 40 50 60 
	printList144(L);        
	
	L.push_front(0);
	L.push_back(0);
	printList144(L);  //0 10 20 30 40 50 60 0

	L.pop_front();   //头删
	L.pop_back();    //尾删
	printList144(L);  //10 20 30 40 50 60 

	L.insert(L.begin(), 100);   //在begin()插入元素  并返回新数据的位置
	L.insert(L.end(), 100);     //在end()插入元素    并返回新数据的位置
	printList144(L);			//100 10 20 30 40 50 60 100 

	list<int>L1{ 1,2,3 };			//创建list容器并初始化
	L.insert(L.begin()++, 3, 200);	//在容器L的第一个元素处插入3个100
	L.insert(L.begin(), L1.begin(), L1.end()); //将L1中从头到尾的数据插入L的第一个元素位置
	printList144(L);				//1 2 3 100 100 100 10 20 30 40 50 60 100

    L.erase(L.begin());   //删除第一个元素
	L.erase(--L.end());   //删除最后一个元素，L.end()表示尾后指针，指向最后一个元素的下一个位置，所以此处不能填L.end()，它的上一个位置才是存储最后一个元素
	printList144(L);       //2 3 100 100 100 10 20 30 40 50 60 
	
	//删除容器内某一区间的元素   创建迭代器，使其指向第一个元素
	list<int>::iterator it = L.begin();
	L.erase(it, next(it, 2));    //删除前两个元素 利用next(it, 2)表示，从it指向的地址往后第二个元素的迭代器指向地址  即2 3
	printList144(L);         //200 200 200 100 10 20 30 40 50 60 

	L.remove(100);    //删掉容器中所有的100
	printList144(L);  //200 200 200 10 20 30 40 50 60 

	//删掉10 20 30 
	list<int>::iterator first = next(L.begin(), 3); //取第二个元素的迭代器
	list<int>::iterator last = next(L.begin(), 6); //取第五个元素的迭代器
	L.erase(first, last);    //删除区间范围内的元素
	printList144(L);    //200 200 200 40 50 60 

	L.remove(200);
	printList144(L);

	L.clear();
	printList144(L);


}

int main144()
{
	test144();
	system("pause");
	return 0;
}



