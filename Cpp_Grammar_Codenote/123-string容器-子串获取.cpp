/*
	从字符串中获取想要的子串
	函数原型：
	string substr(int pos = 0; int n = npos) const; //返回由pos开始的n个字符组成的字符串
*/
#include<iostream>
#include<string>
using namespace std;

//子串获取
void test123_1()
{
	string str = "abcdef";

	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl; 
}

//实用操作   //提取邮箱前面的姓名
void test123_2()
{
	string email = "zhiyao@sina.com";
	//从邮件地址中获取用户名信息
	int position = email.find("@");
	cout << "position = " << position << endl;   //position = 8
	string userName = email.substr(0, position); //从0开始往后截position个字符
	cout << "userName = " << userName << endl; 
}


int main123()
{
	test123_1();
	test123_2();
	system("pause");
	return 0;
}