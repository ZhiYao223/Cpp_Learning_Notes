/*
	学习目标：能够掌握类模板中的成员函数类外实现
	类的声明中只做函数的声明，定义在定义的.cpp文件中写
	模板中成员函数类外实现时，需要加上模板参数列表	
*/

#include<string>
#include<iostream>

using namespace std;

//类模板中成员函数类外实现
template<class T1, class T2>
class Person
{
public:
	T1 m_Name;
	T2 m_Age;

	//构造函数、成员函数类内声明
	Person(T1 name, T2 age);
	void showPerson();

};

//构造函数，类外实现
//为了告诉编译器这是一个类模板的函数类外实现，给作用域加上template 和Person<T1,T2>作用域
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age; 
}


//成员函数的类外实现
//由于showPerson是类模板中的成员函数，为了让编译器知道，也要加template...., 以及Person<T1,T2>
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名:" << this->m_Name << "年龄:" << this->m_Age << endl; 
}

void test108()
{
	Person<string, int> P("Tom", 20);
	P.showPerson();
}
int main108()
{
	test108();
	system("pause");
	return 0;
}