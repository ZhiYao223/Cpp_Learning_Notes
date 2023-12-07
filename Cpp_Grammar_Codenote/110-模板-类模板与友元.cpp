/*
	//全局函数类内实现，直接在类内声明友元即可
	//全局函数类外实现，需要提前让编译器知道全局函数的存在
	
	//总结：建议全局函数做类内实现，用法简单，而且编译器可以直接识别


*/
#if 1

#include <iostream>
using namespace std;
#include <string>

//全局函数配合友元，类外实现，先做函数声明，下方在做函数模板定义，提前让编译器知道Person类的存在
template<class T1, class T2>
class Person;
//类外实现  函数模板的实现 放前面让编译器先看见

template<class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
	cout << "类外实现----姓名：" << p.m_Name << "年龄：" << p.m_Age << endl;
}


template<class T1, class T2>
class Person
{
	 //全局函数类内实现， 加friend前是成员函数，加上后是全局函数
	friend void printPerson1(Person<T1, T2>p)
	{
		cout << "姓名： " << p.m_Name << "年龄：" << p.m_Age << endl;
	}

	//全局函数类外实现 加空模板参数列表
	//如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
	friend void printPerson2<>(Person<T1, T2>p);

public: 
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age; 
	}
private:
	T1 m_Name;
	T2 m_Age;
};

//1、全局函数在类内实现
void test110()
{
	//Person<string, int>("Tom", 12);
	//printPerson1(p);
}

int main110()
{
	test110();
	system("pause");
	return 0;
}

#endif


