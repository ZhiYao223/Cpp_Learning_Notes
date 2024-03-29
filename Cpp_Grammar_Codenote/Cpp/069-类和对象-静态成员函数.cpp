//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
//静态成员函数：http://c.biancheng.net/view/2228.html
/*
通过对象访问和通过类名访问静态成员函数的区别在于调用语法和
使用场景。通过对象访问适用于已经存在的对象实例，而通过类
名访问更适用于在对象不存在的情况下调用静态成员函数，或者
不想创建对象的情况。
*/
#if 1
#include <iostream>
using namespace std;

class People
{
public:
	static void func()
	{
		m_C = 100;   //静态成员函数可以访问静态成员变量
		//m_B = 200;  //报错,静态成员函数不可以访问非静态成员变量，无法区分到底是哪个对象的m_B属性
		cout << "static void func调用" << endl;
	}

	static int m_C; //静态成员变量
	int m_B;		//非静态成员变量
};
int People::m_C = 0;   //静态成员变量在类内声明，类外初始化
//两种访问方式
void test7()
{
	//1.通过对象访问
	People p;
	p.func();

	//2.通过类名访问
	People::func();
}
int main69()
{
	test7();
	system("pause");
	return 0;
}
#endif 
