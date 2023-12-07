#include <iostream>
using namespace std;
int main27()
{
	//二维数组案例
	//1.创建二维数组
	int scores[3][3] = { {100,100,100},{90,50,100},{60,70,80} };

	//统计每个人的总和分数
	for (int i = 0;i < 3;i++)
	{
		int sum = 0;   //统计分数总和
		for (int j = 0;j < 3;j++)
		{
			//cout << scores[i][j] << "\t";
			sum = sum + scores[i][j];
		}
		switch (i)
		{
			case 0:  cout << "张三的各科成绩分别为：" << scores[i][0] << "\t" << scores[i][1] << "\t" << scores[i][2] << "\t";cout << "各科总分为：" << sum << endl; break;
			case 1:  cout << "李四的各科成绩分别为：" << scores[i][0] << "\t" << scores[i][1] << "\t" << scores[i][2] << "\t";cout << "各科总分为：" << sum << endl; break;
			case 2:  cout << "王五的各科成绩分别为：" << scores[i][0] << "\t" << scores[i][1] << "\t" << scores[i][2] << "\t";cout << "各科总分为：" << sum << endl; break;
			default: break;
		}
	}

	string name;       //学生姓名变量
	int i = 0; int j = 0;
	int sum = scores[i][j] + scores[i][j + 1] + scores[i][j + 2];   //统计分数总和
	while (1)
	{
		cout << "请输入您要查看的学生姓名： ";
		cin >> name;
		if (name == "张三")
		{
			i = 0;
			cout << "张三的各科成绩分别为：\t" << scores[i][0] << "\t" << scores[i][1] << "\t" << scores[i][2] << "\t";cout << "各科总分为：" << sum << endl;
		}
		else if (name == "李四")
		{
			i = 1;
			cout << "李四的各科成绩分别为：\t" << scores[i][0] << "\t" << scores[i][1] << "\t" << scores[i][2] << "\t";cout << "各科总分为：" << sum << endl;
		}
		else if (name == "王五")
		{
			i = 2;
			cout << "王五的各科成绩分别为：\t" << scores[i][0] << "\t" << scores[i][1] << "\t" << scores[i][2] << "\t";cout << "各科总分为：" << sum << endl;
		}
		else
		{
			cout << "系统中不含该学生信息，\t";
			
		}
	}
	system("pause");
	return 0;
}