//函数传参时，可以利用引用的技术让形参修饰实参
//优点:简化指针修改实参
#include <iostream>
using namespace std;

//1.值传递
void Myswap01(int a, int b)  //值传递不影响main中的实参
{
	int temp = a;
	a = b;
	b = temp;
/*	cout << "Myswap01 a = " << a << endl;   //形参发生改变
	cout << "Myswap01 b = " << b << endl;*/

}
//2.地址传递
void Myswap02(int* c, int* d)  //地址传递，可以修改main函数中实参c,d的值
{
	int temp = *c;    
	*c = *d;
	*d = temp;
}

//3.引用传递
void Myswap03(int &e, int &f)   //引用传递，可以影响实参的值,引用参数与实参共用一个地址，只是名字不同，所以修改形参即修改main中的实参e,f
{
	int temp = e;
	e = f;
	f = temp;
}


int main47()
{
	int a = 10;
	int b = 20;
	cout << "值传递：" << endl;
	Myswap01(a, b);   //值传递，形参不会影响实参的值
	cout << "a = " << a << endl;  //实参不变
	cout << "b = " << b << endl;

	int c = 10;
	int d = 20;
	cout << "地址传递：" << endl;
	Myswap02(&c, &d);  //地址传递，会影响实参
	cout << "c = " << c << endl;  //实参变
	cout << "d = " << d << endl;

	int e = 10;
	int f = 20;
	cout << "引用传递：" << endl;
	Myswap03(e, f);       // 引用传递，会影响实参
	cout << "e = " << e << endl;  //实参变
	cout << "f = " << f << endl;

	system("pause");
	return 0;
	//普通形参的地址在栈区，调用结束，销毁释放a,b； 而引用是用堆区地址，不会销毁
	//指针拿的地址是那块内存的地址，而引用是把那块内存重新起个别名
	//在统一函数中/局部空间,别名和原名不能相同，引用中的
}