/*
	在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容

	因此可以将虚函数改为纯虚函数

	纯虚函数语法：virtual 返回值类型 函数名（参数列表） = 0;
	当类中有了纯虚函数，这个类也叫抽象类
	抽象类特点：无法实例化对象 、子类必须重写抽象类中的纯虚函数，否则也属于抽象类
*/
#include <iostream>
using namespace std;

class Base 
{
public:
	virtual void func() = 0;  //在虚函数基础上写 "= 0"

};
class Son :public Base
{
public:
	virtual void func() //重写父类的纯虚函数
	{
		cout << "func函数调用" << endl; 
	};

};

void test89_1()
{
	//Base b;   //父类是抽象类，抽象类无法实例化对象  栈
	//new Base; //抽象类无法实例化对象               堆区

	Son s; //子类必须重写父类中的纯虚函数，否则无法实例化对象
	Base* base = new Son;  //
	base->func();
}
int main89()
{
	test89_1();
	system("pause");
	return 0;
}