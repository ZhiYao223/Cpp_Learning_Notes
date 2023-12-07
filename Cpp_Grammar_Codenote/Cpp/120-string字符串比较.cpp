/*
	字符串是按字符的ASCII码进行比对的
	= 返回 0
	> 返回 1
	< 返回 -1

	int compare(const string &s) const; //与字符串s比较
	int compare(const char *s) const;   //与字符串s比较

*/
#include<iostream>
#include<string>
using namespace std;

//字符串比较
void test120()
{
	string str1 = "hello";
	string str2 = "hello";
	int returnvalue = str1.compare(str2);
	cout << "returnvalue = " << returnvalue << endl;  //相等，返回0


	//string str1 = "xello";
	//string str2 = "hello";
	//int returnvalue = str1.compare(str2);
	//cout << "returnvalue = " << returnvalue << endl;  //str1 > str2 返回 1

	//string str1 = "hello";
	//string str2 = "xello";
	//int returnvalue = str1.compare(str2);
	//cout << "returnvalue = " << returnvalue << endl; //str1 < str2 返回 -1

	if (str1.compare(str2) == 0)
	{
		cout << "str1 等于 str2" << endl; 
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1 大于str2" << endl; 
	}
	else
	{
		cout << "str1 小于 str2" << endl; 
	}

}
int main120()
{
	test120();
	system("pause");
	return 0;
}