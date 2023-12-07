/*
不管什么类型的指针都占4个字节空间，virtual 
空类的大小是1，sizeof Animal = 1  加上virtual后，sizeof Animal = 4 
只有非静态成员变量才在类对象的存储空间里，成员函数不是
成员变量和成员函数分开存储，只有非静态成员变量才属于类的对象上。
非静态成员函数，静态成员函数，静态成员变量占用的内存均不占用类的对象空间，不属于某一类的对象
*/

#include <iostream>
using namespace std;
//多态

//动物类
class Animal
{
public:
	//虚函数
	//加上virtual后，变成四个字节，没加virtual是空类，占1个字节
	virtual void speak()  //不加virtual"动物在说话",加了virtual"小猫在说话"   非静态成员函数不属于类的对象
	{
		cout << "动物在说话" << endl;

	}
};
//猫类
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}

};
//狗类
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};
//执行说话的函数
//地址早绑定，在编译阶段就确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
void doSpeak(Animal& animal)  //Animal &animal = cat;
{
	animal.speak();
}

void test87()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

int main87()
{
	test87();
	system("pause");
	return 0;
}

