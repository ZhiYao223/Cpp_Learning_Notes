/*
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& operator+=(const string& str);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾,一个中文算2个字符
string& append(const string &s);//同operator+=(const string& str)
string& append(const string &s，int pos，int n); //字符s中从pos开始的n个字符连接到字符串结尾

*/
#include<iostream>
#include<string>
using namespace std;

void test118()
{
	string str0 = "青花瓷 稻香";
	string str1 = "我";
	str1 += "喜欢";
	//我喜欢
	cout << "str1 = " << str1 << endl;
	
	//我喜欢：
	str1 += ':';
	cout << "str1 = " << str1 << endl;
	
	string str2 = "周杰伦 的歌";
	
	str1 += str2; 
	cout << "str1 = " << str1 << endl; 
	
	string str3 = "例如";
	str3.append("：");
	cout << "str3 = " << str3 << endl; //例如：

	str3.append("青花瓷 稻香", 6); //提取前6个字符，即青花瓷三个字，共6个字符接到str3后面
	//例如：青花瓷
	cout << "str3 = " << str3 << endl; 
	//只截取稻香，参数从第七个字符(空格)下一位开始截取4个字符
	str3.append(str0, 7, 4); //从第6个字符(瓷)开始取5个，即“ 稻香”。
	//例如：青花瓷 稻香
	cout << "str3 = " << str3 << endl; 

	string str4 = "I love ";
	string str5 = "qinghuaci";
	str4.append(str5); //I love qinghuaci
	cout << "str4 = " << str4 << endl;


	
}

int main118()
{
	test118();
	system("pause");
	return 0;
}