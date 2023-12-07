/*
虚构和纯虚析构共性：
1、可以解决父类指针释放之类对象
2、都需要有具体的函数实现
虚析构和纯析构区别：
1、如果是纯虚析构，该类属于抽象类，无法实例化对象
2、如果子类中没有堆区数据，可以不写为虚析构或纯析构

虚构语法：virtual ~类名(){}
纯虚析构语法： virtual ~类名() = 0;  //声明
类名::~类名(){}   //代码实现
*/
#include <iostream>
using namespace std;
#include <string>
class Animal
{
public:
	Animal()
	{
		cout << "Animal构造函数调用" << endl; 
	}
	//利用虚析构可以解决 父类指针释放子类对象时不干净的问题
//	virtual ~Animal()
//	{
//		cout << "Animal析构函数调用" << endl; 
//	}
	//纯虚析构 需要声明也需要实现，有了纯虚析构后，这个类也属于抽象类，无法实例化对象
	virtual ~Animal() = 0;      //纯虚析构
	virtual void speak() = 0;   //纯虚函数
};
Animal::~Animal()
{
	cout << "Animal的纯虚析构函数调用" << endl; 
}


class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat的构造函数" << endl;
		m_Name = new string(name);
	}

	virtual void speak()
	{
		cout << *m_Name <<"小猫在说话" << endl;
	}
	~Cat()
	{
		if (m_Name != NULL)
		{

		}
	}
	string* m_Name; //创建在堆区

};

void test91()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	delete animal;
}
int main91()
{
	test91();
	system("pause");
	return 0;
}