/*
	普通含糊调用时可以发生字段类型转换(隐式类型转换）
	函数模版调用时，如果利用自动类型推导，不会发生隐式类型转换
	如果利用显示制定类型的方式，可以发生隐式类型转换
*/

#include <iostream>

using namespace std;

//函数模版
template<class T>
T myAdd02(T a, T b)
{
	return a + b; 
}

//普通函数
int myAdd01(int a, int b)
{
	return a + b; 
}
void test100_1()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd01(a, c) << endl; //c会自动转为99 再加10 结果为109
	
	//自动类型推导  不会发生隐式类型转换
	//cout << myAdd02(a, b) << endl;  //结果为30
	//cout << myAdd02(a, c) << endl;  //报错，函数模版不会自动将字符c转化为ASCII码
	
	//显示制定类型  会发生隐式类型转换
	cout << myAdd02<int>(a, c) << endl; //不是int类型的，自动转成int类型，'c'为99，不能转的类型即报错
}
 

int main100()
{
	test100_1();
	system("pause");
	return 0;
}