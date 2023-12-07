#include <iostream>
using namespace std;


//1.不要返回局部变量的引用
int& test01()
{
	int a = 10;  //局部变量存放在四区中的栈区，函数执行完后释放
	return a;
}
//返回的a是int&类型的，所以必须用同类型去接收，这里用ref接收，即int& ref = a,即ref为a的别名

//2.函数的调用可以作为左值
int& test02()
{
	static int a = 10; //静态变量，存放在全局区，其上的数据在整个程序结束后系统释放
	return a;   //int& 返回的是变量的引用，也是变量的别名，可以再定义一个变量接收这个引用，即别名的别名。
	            //返回变量a的引用，即a的与原名相同的别名
} 

//遇到return时，类似做了一次int &a = a的强制转换，再把左边的a作为返回值，即是个和原名一样的别名变量
int main48()
{
	//不要返回局部变量的引用
	//int& ref = test01();
	//cout << "ref = " << ref << endl;  //第一次结果正确，结果为10，是因为编译器做了保留
	//cout << "ref = " << ref << endl;  //第二次结果错误，是因为a的内存已经释放，属于非法操作

	int& ref2 = test02();  //ref2是函数返回的变量a的引用的引用，即变量a的别名的别名
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl; //a为静态变量，程序结束前a内存都未被释放，结果都是10

	//如果函数的返回值是引用，那这个函数调用可以作为左值
	test02() = 1000; //test02函数中，返回了int&类型的a,即返回了a的与原名相同的别名a，或者说返回了a的引用,此时等价于a = 1000;
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;
	//test02() ,ref2都是a的别名，只不过test02()用来赋值成了1000，再用ref2输出而已
	system("pause");
	return 0;
}