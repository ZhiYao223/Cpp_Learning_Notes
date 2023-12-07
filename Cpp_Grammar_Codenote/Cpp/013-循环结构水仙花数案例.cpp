#include <iostream>
using namespace std;
int main13()
{
	//1.将所有的三位数输出
	int num = 100;
	int ge = 0;   //变量初始化
	int shi = 0;
	int bai = 0;
	do
	{
		ge = num % 10;           //获取个位
		shi = num / 10 % 10;     //获取十位
		bai = num / 100;         //获取百位
		if (pow(ge,3) + pow(shi,3) + pow(bai,3) == num)
		{
			cout << "水仙花数：" << num << endl;
		}
		num++;
	} while (num<=999 );

	//2.在所有三位数中找到水仙花数
	//获取个位   153%10 = 3  对数字取模于10可以获取到个位
	//获取十位   153/10%10 = 5  先整除于10，得到两位数，再取模于10，得到十位。或者n%100/10
	//获取百位   153/100 =1

	//判断 各位^3 + 十位^3 + 百位^3  = 数字本身
	system("pause");
	return 0;
}