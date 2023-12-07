#include <iostream>
using namespace std;
int main11()
{
	//switch 语句
	//给电影打分 10-9 经典     8-7 非常好    6-5 一般    5以下 烂片
	//1.提示用户给电影评分
	cout << "请给电影评分：" << endl;
	
	//2.用户开始进行打分
	int score = 0;
	cin >> score;
	while(1)
	{
		cout << "您打的分数为：" << score << endl;
		if (score >= 0 && score <= 10)              //排除无效打分
		{
			//switch缺点：判断时只能是整型或字符型，不能是一个区间
			//switch优点：结构清晰，执行效率高
			switch (score)
			{
			case 10: cout << "经典电影" << endl;			break;//跳出switch循环
			case 9:  cout << "经典电影" << endl;			break;
			case 8:  cout << "非常好的电影" << endl;		break;
			case 7:  cout << "非常好的电影" << endl;		break;
			case 6:  cout << "一般的电影" << endl;		break;
			case 5:  cout << "一般的电影" << endl;		break;
				//case 4:  cout << "烂片" << endl;				break;
				//case 3:  cout << "烂片" << endl;				break;
				//case 2:  cout << "烂片" << endl;				break;
				//case 1:  cout << "烂片" << endl;				break;
			default: cout << "烂片" << endl;				break;  //除了以上5-10外，其他默认都是烂片
			}
		}
		else
		{
			cout << "输入无效，请重新输入0-10的score打分：" << endl;
			cin >> score;
		}
	}

}