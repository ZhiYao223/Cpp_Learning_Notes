/*

int find(const string& str, int pos = 0) const;//查找str第一次出现位置,从pos开始查找
int find(const char*s, int pos = 0) const;//查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;//从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;//查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const;//查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str);//替换从pos开始n个字符为字符串str
string& replace(int pos, int n,const char* s);//替换从pos开始的n个字符为字符串s

find查找是从左往后，rfind从右往左
find找到字符串后返回查找的第一个字符位置，找不到返回-1
replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串

*/
#include <iostream>
#include <string>
using namespace std;

//字符串查找和替换

//1、查找
void test119_1()
{
	//查找字符串中出现"df"的位置，从0    输出3
	string str1 = "bcabcdefgde";         
	int position = str1.find("def");  //从左往右查，按绝对位置输出第一个de（c后面）的位置为position = 3
	
	if (position == -1)
	{
		cout << "未找到字符串" << endl;  
	}
	else
	{
		cout << "找到字符串，position = " << position << endl; 
	}

	//rfind从右往左查找， find从左往右查找
	position = str1.rfind("de");  //从右往左查，倒数一二就是de（g后面），但按绝对位置数数，所以输出position = 7
	cout << "position = " << position << endl;  //从右往左第一个de的位置下标
}

//2、替换
void test119_2()
{
	string str1 = "abcdefg";   //1~3位置abc替换为1111  输出 a1111efg  是4个1全部替换，而不是只换3个1
	str1.replace(1, 3, "1111");
	cout << "str1 = " << str1 << endl; 
}
//替换
void test119_3()
{
	string str1 = "abcdef";
	string str2 = "ghijk";
	str1.replace(0, 2, str2);  //从第0个位置开始数2个字符ab,替换为ghijkk  输出ghijkcdef
	cout << "str1 = " << str1 << endl;
}

int main119()
{
	test119_1();
	test119_2();
	test119_3();

	system("pause");
	return 0;
}