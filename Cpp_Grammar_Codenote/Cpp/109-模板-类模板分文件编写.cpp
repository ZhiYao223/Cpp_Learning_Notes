/*
	类模板份文件编写
	学习目标：掌握类模板成员函数份文件编写产生的问题以及解决方式

	问题:
	类模板中成员函数创建时机是在调用阶段，导致份文件编写时链接不到
	解决：
	解决方式1：直接包含.cpp文件
	解决方式2：将声明和实现写到同一个文件

	类模板中的成员函数创建时机是在调用阶段，一开始不创建。所以要么直接包含类模板实现的源文件
	要么将.h和.cpp文件，即模板声明和实现写在同一个.hpp文件中。
*/
#pragma once
#include <iostream>
using namespace std;
#include <string>

#include "109-类模板分文件编写Person.cpp"
//类模板分文件编写问题及解决
//template <class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	void showPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};

//template <class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template <class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "姓名：" << this->m_Name << "年龄：" << this->m_Age << endl;
//}

void test109()
{
	//加上第16行.cpp源文件，为了让编译器看见.cpp源文件中的类模板实现
	//否则，由于类模板创建时机问题，下面两行会报错
	Person<string, int> p("Jerry", 18);    
	p.showPerson();
}

int main109()
{
	test109();
	system("pause");
	return 0;
}














