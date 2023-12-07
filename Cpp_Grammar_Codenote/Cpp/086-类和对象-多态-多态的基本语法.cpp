/*
多态是c++面向对象三大特性之一
多态分为两类
	静态多态：函数重载和运算符重载属于静态多态， 复用函数名
	动态多态：派生类和虚函数实现运行时多态
静态多态和动态多态区别：
	静态多态的函数地址早绑定 - 编译阶段确定函数地址
	动态多态的函数地址晚绑定 - 运行阶段确定函数地址

动态多态的满足条件
1、得有继承关系如父子关系、动物与猫的关系
2、子类重写父类的虚函数

//动态多态使用
1、父类指针或引用，指向子类对象

重载：函数名相同
重写：函数返回值类型、函数名、参数列表完全相同
*/
#include <iostream>
using namespace std;
//多态

//动物类
class Animal
{
public:
	//虚函数
	virtual void speak1()  //不加virtual"动物在说话",加了virtual"小猫在说话"
	{
		cout << "动物在说话" << endl;

	}
};
//猫类
class Cat :public Animal
{
public:
	void speak1()
	{
		cout << "小猫在说话" << endl;
	}

};
//狗类
class Dog :public Animal
{
public:
	void speak1()
	{
		cout << "小狗在说话" << endl;
	}
};
//执行说话的函数
//地址早绑定，在编译阶段就确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
void doSpeak1(Animal &animal)  //Animal &animal = cat;
{
	animal.speak1();
}

void test86()
{
	Cat cat;
	doSpeak1(cat);

	Dog dog;
	doSpeak1(dog);
}

int main86()
{
	test86();
	system("pause");
	return 0;
}