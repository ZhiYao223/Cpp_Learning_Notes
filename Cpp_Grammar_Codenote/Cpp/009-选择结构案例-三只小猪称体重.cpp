#include <iostream>
using namespace std;
int main09()
{
	//三只小猪称体重，判断哪只最重

	//创建三只小猪的体重变量
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	//让用户输入三只小猪的体重
	cout << "请输入三只小猪的体重：" << endl;
	cin >> num1 >> num2 >> num3;

	//判断哪只最重
	if (num1 >= num2)
	{
		if (num1 >= num3)
		{
			cout << "第一只最重" << endl;
		}
		else
		{
			cout << "第三只最重" << endl; 
		}
	}
	else
		if (num2 >= num3)
		{
			cout << "第二只最重" << endl; 
		}
		else
		{
			cout << "第三只最重" << endl; 
		}
	
	system("pause");
	return 0;
}