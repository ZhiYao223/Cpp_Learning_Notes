/*
	解决方法2：将类模板声明和实现写入同一个头文件，并改后缀为.hpp
	若要使用类模板，则在cpp文件开头加入#include "109-类模板分文件编写Person.hpp"
	
*/
#pragma once
#include <iostream>
using namespace std;
#include <string>

//类模板分文件编写问题及解决
template <class T1, class T2> 
class Person
{
public:
	Person(T1 name, T2 age);
	void showPerson();

	T1 m_Name;
	T2 m_Age;
};

template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age; 
}

template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名：" << this->m_Name << "年龄：" << this->m_Age << endl; 
}


