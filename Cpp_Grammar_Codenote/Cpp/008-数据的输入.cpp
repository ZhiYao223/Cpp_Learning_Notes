#include <iostream>
#include <string>      //vs2019后可不写，编译器已内置
using namespace std;
int main8()
{
#if 0
	//整型
	int a = 0;
	cout << "请给整型变量a赋值：" << endl;
	cin >> a;
	//cout << "整型变量a = " << a << endl;

	//浮点型
	float f = 3.14f;
	cout << "请给浮点型变量赋值：" << endl;
	cin >> f;
	cout << "浮点型变量f =" << f << endl;

	//字符型
	char ch = 'a';
	cout << "请给字符型变量ch赋值：" << endl;
	cin >> ch;
	cout << "字符型变量ch =" << ch << endl;

	//字符串型
	string str = "hello world";
	cout << "请给字符串str赋值：" << endl;
	cin >> str;
	cout << "字符串str= " << str << endl;
#endif
	//布尔类型
	bool flag = false;
	cout << "请给布尔类型的flag赋值：" << endl;
	cin >> flag;
	cout << char(flag) << endl;     
	cout << "布尔类型flag = " << flag << endl;

	system("pause");
	return 0;
}