/*

*/
#include <iostream>
#include <deque>
using namespace std;

void  printDeque132(const deque<int>& d)
{
	//for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	//{
	//	//*it = 100;    //加了const_iterator后，*it禁止修改
	//	cout << *it << " ";
	//}

	for (auto const& it : d)
	{
		cout << it << " ";
	}
	cout << endl;
}
void test132()
{
	deque<int>d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque132(d1);

	//operator= 赋值
	deque<int>d2;
	d2 = d1;
	printDeque132(d2);

	//assign赋值
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque132(d3);

	//assign
	deque<int>d4;
	d4.assign(10, 100);
	printDeque132(d4);
}

int main132()
{
	test132();
	system("pause");
	return 0;
}
