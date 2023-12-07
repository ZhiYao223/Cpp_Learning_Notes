#include <iostream>
using namespace std;
int main17()
{
	//1.当前的列数<=行数
	for (int i = 1; i < 10; i++)              //i表示行
	{
		for (int j = 1; j <= i; j++)          //j表示列<= 当前的行数
		{
			int answer = i * j;
			cout << j << "*" << i << "=" << answer << "\t";
		}
		cout << endl;
	}
	return 0;
}


