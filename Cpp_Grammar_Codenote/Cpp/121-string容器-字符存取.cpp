/*
	string中单个字符存取方式有两种
	char& operator[](int n); //通过[]方式取字符
	char& at(int n);         //通过at方式获取字符

*/

#include<iostream>
#include<string>
using namespace std;


//string字符存取
void test121()
{
	string str = "hello";
	//1.通过[]访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl; 

	//2.通过at方式访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " " ; 
	}
	cout << endl;

	//修改单个字符
	str[0] = 'x'; //xello
	cout << "str = " << str << endl;

	str.at(1) = 'x'; //xxllo
	cout << "str = " << str << endl; 
}

int main121()
{
	test121();
	system("pause");
	return 0;    
}