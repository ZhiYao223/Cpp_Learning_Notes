#include <iostream>

using namespace std;

int main3()
{
	short num1 = 10;
	cout << "short占用内存空间为：" << sizeof(num1) << endl;
	
	int num2 = 10;
	cout << "int占用内存空间为：" << sizeof(int) << endl;

	long num3 = 10;
	cout << "long占用内存空间为：" << sizeof(long) << endl;

	long long num4 = 10;
	cout << "long long 占用内存空间为：" << sizeof(long long) << endl;

	float f1 = 4.1415926f;//句末f表示float类型
	cout << "f1 = " << f1 << endl;

	double d1 = 3.1515926;
	cout << "d1 = " << d1 << endl;

	cout << "float占用内存空间为：" << sizeof(float) << endl;
	
	cout << "double占用内存空间为: " << sizeof(double) << endl;

	float f2 = 3e2f;// 3*10^2;
	cout << "f2 = " << f2 << endl;

	float f3 = 3e-2;//3*10^(-2);
	cout << "f3 = " << f3 << endl;

	system("pause");
	
	return 0;
}