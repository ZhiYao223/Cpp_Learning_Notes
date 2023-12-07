#include <iostream>
#include <ctime>  //系统时间头文件
using namespace std;
int main12()
{
	//1.系统随机生成随机数
	//2.玩家进行猜测
	//3.判断玩家的猜测
	// 
	//4.猜对  退出游戏  猜错 提示过大或过小，继续猜测
	srand(time(0));                          //生成真正的随机数  或者srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;             //rand()%100 + 1表示区间为0+1-99+1的随机数，单有这行是伪随机数
	cout << num << endl;

	int val = 0;  //猜测结果变量初始化
	cout << "请玩家输入您的猜测：" << endl;
	cin >> val;
	int number = 1;
	while (1)
	{
		if (val > num)
		{
			cout << "猜测结果过大，请重新输入您的猜测：" << endl;
			cin >> val; 
		}
		else if (val < num)
		{
			cout << "猜测结果过小，请重新输入您的猜测：" << endl;
			cin >> val; 
		}
		else if (val == num)
		{
			cout << "恭喜您猜对了, 共使用"<<number<<"次机会，游戏结束！" << endl;
			break;       //跳出while循环，结束游戏
		}
		number++;
		if (number > 5)
		{
			cout << "很遗憾，您的猜测次数已用完，游戏结束！" << endl;
		}
	}
	system("pause");
	return 0;


}