//常量指针:指向常量的指针是一个指向可改，值不可改的指针
//指针常量：该指针是常量，是一个指向不可改，值可改的指针
//记忆方法：谁先说谁不变，谁先说先写谁
// 引用的本质就是一个指针常量，一旦初始化后，就不可以发生改变
//引用的地址和原变量地址一样，只是名字不同；指针的地址和原变量不一样，所以引用更省空间。
#include <iostream>
using namespace std;

//编译器发现是引用，转换为int* const ref = &a;
void func(int& ref)
{
	ref = 100; //ref是引用，转换为*ref = 100
}

int main49()
{
	int a = 10;
	int& ref = a; //自动转换为int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
	ref = 20;    //内部发现ref是引用，编译器自动帮我们转换为：*ref = 20;

	cout << "a: " << a << endl;
	cout << "ref:" << ref << endl;

	func(a);
	return 0;
}
