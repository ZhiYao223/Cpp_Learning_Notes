#include <iostream>
//#include <string>           //vs2019默认添加过，不加也行
//#include <bits/stdc++.h>   //万能头文件

using namespace std;
int main6()
{
	cout << "hello world" << endl;

	//c语言风格，字符串双引号，字符单引号,字符串用数组
	char str1[] = "hello world";   
	cout << str1 << endl;

	//C++风格字符串，包含一个头文件 #include <string>  
	string str2 = "hello world";   
	cout << str2 << endl;

	system("pause");
	return 0;
}