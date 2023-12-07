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