#include <iostream>
using namespace std;
int main16()
{
    //利用嵌套循环实现星图
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}