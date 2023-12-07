#include <iostream>
using namespace std;
int main15()
{
	//1.从数字1到数字100
	//2.判断每输出一个，求出数字个位数，十位数，判断是否含7，或者这个数是7的倍数，打印敲桌子
	// 并输出一共有多少个数满足敲桌子
	//3.否则，打印
	int ge = 0; int shi = 0;
	int times = 0; int number = 0;   //number为计数变量，统计敲桌子的个数  
	for (int num = 1; num <= 100; num++)
	{
		ge = num % 10;
		shi = num / 10 % 10;
		times = num % 7;               //数字7的倍数，即被7整除等于0
		if ((ge == 7) || (shi == 7) || (times == 0)) //三者满足一个条件即可敲桌子
		{
			cout << "敲桌子" << endl; number++;
		}
		else
		{
			cout << num << endl; 
		}
	}
	cout << "一共敲了"<< number <<"下桌子" << endl;
	//system("pause");
	return 0;
}