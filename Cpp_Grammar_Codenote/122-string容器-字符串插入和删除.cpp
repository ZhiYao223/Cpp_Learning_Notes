/*
	功能描述：
	对string字符串进行插入和删除字符串操作
	
	函数原理：
	string& insert(int pos, const char* s);  //插入字符串
	string& insert(int pos, const string& str); //插入字符串
	string& insert(int pos, int n, char c); //在指定位置插入n个字符c
	string& erase(int pos, int n = npos); //删除从pos开始的n个字符

	//插入和删除的起始下标都是从0开始
*/
#include<iostream>
#include<string>
using namespace std;

//字符串 插入和删除

void test122()
{
	//插入
	string str = "hello";
	str.insert(1, "111");
	//h111ello
	cout << "str = " << str << endl; 
	
	//删除
	str.erase(1, 3);
	cout << "str = " << str << endl;  //删掉从第1个位置起3个字符，即删掉111 输出hello
}
int main122()
{
	test122();
	system("pause");
	return 0;
}
