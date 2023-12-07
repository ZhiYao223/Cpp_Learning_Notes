#include <iostream>
using namespace std;
//函数重载的首要条件是作用域相同
/*
1.子类对象可以直接访问到子类中同名成员
2.子类对象加作用域可以访问到父类同名成员
3.当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
*/
class Base
{
public:
	Base()        //父类的构造函数
	{
		m_A = 100;   //父类中的m_A的值为100
	}
	void func()  //父类中的同名构造函数
	{
		cout << "Base-func()调用" << endl;
	}
	void func(int a)  //父类中的带参数的同名构造函数
	{
		cout << "Base-func()调用" << endl;
	}
	int m_A;
};

class Son :public Base  //继承父类的Son子类
{
public:
	Son()      //子类的构造函数
	{
		m_A = 200;  //Son子类中的m_A的值为200
	}
	void func()  //子类中的同名构造函数
	{
		cout << "Son-func()调用" << endl;
	}
	int m_A;
};
//同名成员属性处理
void test82_1()
{
	Son s;
	cout << "Son下的m_A =" << s.m_A << endl;   //直接输出s.m_A是子类中的200
	cout << "Base下的m_A ="<<s.Base::m_A <<endl; //加上作用域后，才能通过子类对象访问父类中继承下来的同名成员
}

//同名成员函数处理
void test82_2()
{
	Son w;
	w.func();        //直接调用，调用的是子类中的同名构造函数"Son-func()调用"
	w.Base::func();  // 如果父类和子类出现同名函数，若要调用Base父类下的构造函数，需要加上作用域"Base-func()调用"
	//w.func(100);//错误，子类中的成员函数将父类中所有的同名函数都隐藏掉了，无法访问
	w.Base::func(100);//带作用域正确，可以访问父类中带参数的同名函数

}
//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数，func(),func(int a)都算同名
// 如果想访问到父类中被隐藏的同名成员函数，需要加作用域
// 
 //思考，打印出来的m_A的值是父类中的100，还是子类中的200？
int main82()
{
	test82_1();
	test82_2();
	system("pause");
	return 0;
}