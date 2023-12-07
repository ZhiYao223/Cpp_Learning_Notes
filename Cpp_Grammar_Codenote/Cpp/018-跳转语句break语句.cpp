#include <iostream>
using namespace std;
int main18()
{
	cout << "请选择副本难度" << endl;
	cout << "1.普通" << endl;
	cout << "2.中等" << endl;
	cout << "3.困难" << endl;
	int select = 0;   //创建选择结果的变量
	cin >> select;//等待用户输入
	switch (select)
	{
	case 1: cout << "您选择的是普通难度" << endl; break;
	case 2: cout << "您选择的是中等难度" << endl; break;
	case 3: cout << "您选择的是困难难度" << endl; break;
	default: break;                                      //默认情况下，跳出，即输入不是1,2,3时

	}
	//break会退出循环，而continue不会，continue是当前截止，执行下一次循环；
	system("pause");
	return 0;
}