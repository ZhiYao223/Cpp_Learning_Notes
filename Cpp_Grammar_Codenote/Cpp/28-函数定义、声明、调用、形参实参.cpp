#include <iostream>
using namespace std;

//声明可以多次,提前告诉编译器，该函数存在，定义只能一次
int max(int a, int b);

int max(int a, int b)
{
	return a > b ? a : b; 
}

int main28()
{
	int a = 10;
	int b = 20;
	int c = max(a, b);
	cout << max(a, b) << endl;

	system("pause");
	return 0;
}

//函数定义在main函数之后，需要在main函数之前声明，在main函数之前定义，则不需函数声明
#if 0
int max(int a, int b)
{
	return a > b ? a : b;
}
#endif

//形参不影响实参，子函数中，形参改变，但实参不会变。