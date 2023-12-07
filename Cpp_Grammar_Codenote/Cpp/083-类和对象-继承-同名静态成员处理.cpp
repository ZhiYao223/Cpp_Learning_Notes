//总结：同名静态成员处理方式和非静态处理方式一样，只不过有两种访问方式（通过对象和通过类名）
#include <iostream>
using namespace std;

//继承中的同名静态成员处理方式
class Base
{
public:
	static int m_A;  //静态成员属性： 编译阶段分配内存、所有对象共享同一份数据、类内声明内外初始化
    static void func() //父类中的静态同名成员函数
	{
		cout << "Base-static void func()" << endl;
	}
	static void func(int a)  //重名的静态成员函数
	{
		cout << "Base-static void func(int a)" << endl; 
	}
};
int Base::m_A = 100;

class Son :public Base
{
public:
	static int m_A;  //子类下的同名静态成员数学

	static void func()   //子类中的静态同名成员函数
	{
		cout << "Son-static void func()" << endl;
	}
};
int Son::m_A = 200;

//同名静态成员属性
void test83_1()
{
	//1、通过对象访问
	Son s;
	cout << "通过对象访问：" << endl; 
	cout << "Son下的m_A = " << s.m_A << endl;  //访问的是子类中的静态成员属性200
	cout << "Base下的m_A = " << s.Base::m_A << endl; //加上作用域，访问父类中的静态同名成员属性

	//2、通过类名访问
	cout << "通过类名访问：" << endl;
	cout << "Son 下的m_A = " << Son::m_A << endl;
	//第一个：：代表通过类名方式访问    第二个：：代表访问父类作用域下
	cout << "Base下的m_A = " <<Son::Base::m_A << endl;

}
//同名静态函数
void test83_2()
{
	//1、通过对象访问
	cout << "通过对象访问" << endl;
	Son w;
	w.func(); //访问父类中的func()函数
	w.Base::func();
	w.Son::Base::func();

	//2、通过类名访问
	cout << "通过类名访问" << endl;
	Son::func();
	Son::Base::func();
	//Son::func(100);  //父类与子类存在同名成员函数，父类中的所有同名成员函数会被隐藏，无法访问，需要加上Base作用域如下行所示：
	Son::Base::func(100);
}

int main83()
{
	test83_1();
	test83_2();
	system("pause");
	return 0;
}