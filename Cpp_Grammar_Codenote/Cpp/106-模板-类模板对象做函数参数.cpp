/*
	学习目标：
	类模板实例化出的对象，向函数传参的方式

	一共有三种传入方式:
	1、指定传入的类型 ---直接显示对象的数据类型
	2、参数模板化 ---将对象中的参数变为模板进行传递
	3、整个类模板化 ---将这个对象类型模板化进行传递
	
	总结：
	通过类模板创建的对象，可以有三种方式向函数中进行传参
	使用比较广的是第一种，指定传入的类型
	*/

#include <iostream>
#include <string>
using namespace std; 
//类模板
template<class NameType, class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{	
		this->m_Name = name;
		this->m_Age = age; 
	}
	void showPerson()
	{
		cout << "name:" << this->m_Name << "age: " << this->m_Age << endl;
	}
public:
	NameType m_Name;
	AgeType m_Age;
};


//1.指定传入的类型
void printPerson1(Person<string, int> &P)
{
	P.showPerson();
}
void test105_1()
{
	Person<string, int> p("孙悟空", 100);
	printPerson1(p);
}

//2.参数模板化
template<class T1, class T2>
void printPerson2(Person<T1,T2> &p)
{
	p.showPerson();
	cout << "T1的类型为：" << typeid(T1).name() << endl;
	cout << "T2的类型为：" << typeid(T2).name() << endl;
}

void test105_2()
{
	Person <string, int > p("猪八戒", 90);
	printPerson2(p);
}

//3、整个类模板化
template<class T>
void printPerson3(T &p)
{
	cout << "T的类型为：" << typeid(T).name() << endl;
	p.showPerson(); 
}
void test105_3()
{
	Person<string, int> p("唐僧", 25);
	printPerson3(p);
}
int main106()
{
	test105_1();
	test105_2();
	test105_3(); 
	system("pause");
	return 0;
}