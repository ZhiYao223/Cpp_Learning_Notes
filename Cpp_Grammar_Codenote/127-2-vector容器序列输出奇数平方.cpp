/*
	在指定大小为N的容器中，插入N个数据，并计算其中的奇数个数，将奇数平方后，再输出容器序列

*/
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

void print190(int val)
{
	cout << val << " ";
}

void test190()
{
	vector<int> nums;  //创建容器
	int N = 0;
	cout << "指定容器大小:";
	cin >> N;
	nums.resize(N);  //给容器分配空间

	cout << "请输入" << N << "个整数：";


	for (int i = 0; i < N; i++)  //输入数据
	{
		cin >> nums[i];
		//nums.push_back(nums[i]);
	}

	int odd_number = 0;
	cout << "容器有效元素为：";
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)  //遍历容器,检查数据
	{
		bool is_normal = true;     //非奇非偶标志位，若为奇数或偶数，则true，如果为小数，则false输出错误提示
		cout << *it << "  ";       //
		if (*it % 2 == 1 || *it % 2 == -1)  //如果余数为1，为奇数
		{
			*it = pow(*it, 2);		//替换为奇数的平方
			odd_number++;			//计算奇数个数
			is_normal = true;
		}
		else if (*it % 2 == 0)		//如果为偶数
		{
			continue;
			is_normal = true;
		}
		else if (!is_normal)
		{
			cout << "数据有误！" << endl;
			return;
		}

	}
	cout << endl;
	cout << "共有：" << odd_number << "个奇数，处理后的数据为：" << " ";
	for_each(nums.begin(), nums.end(), print190);  //处理奇数后，遍历容器
	cout << endl;
}

int main127_2()
{
	test190();
	system("pause");
	return 0;
}