#include <iostream>

using namespace std;

int main4()
{
	char ch = 'a';  //创建字符用单引号
	cout << ch << endl;
	cout << "char字符型变量所占内存空间：" << sizeof(char) << endl;

	//char ch2 = "abcdef"//单引号内只能放一个字符

	cout << (int)ch << endl; //强制类型转换成ASCII码
	ch = 97;                 //可以直接用ASCII码给字符型变量赋值
	cout << ch << endl;      //输出97对应的字符

	system("pause");

	return 0;
}

