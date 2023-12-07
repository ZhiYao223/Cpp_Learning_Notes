/*
* 主要区别有两点：
	1、类模板没有自动类型推导的使用方式, 只能使用显示指定类型方式
	2、类模板在模版参数列表中可以有默认参数
*/
#include <iostream>
#include <string>
using namespace std;

//类模板与函数模板区别
template<class NameType, class AgeType = int>//默认参数int
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
		cout << "name = "<< this->m_Name <<"age = "<< this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

//1、类模板没有自动类型推导的使用方式
void test104_1()
{
	//Person p("孙悟空", 1000); //错误，无法用自动类型推导
	Person<string, int> p("孙悟空", 1000); //正确，只能用显示指定类型
	p.showPerson();
}

//2、类模板在模版参数列表中可以有默认参数
void test104_2()
{
	Person<string, int> p1("猪八戒", 999);
	p1.showPerson();
	//如果第11行处，函数模板改为, 第二个参数默认为int，则调用时<>中可以不写第二个参数
	//template<class NameType, class AgeType = int>d
	//则可以这样也不报错：第二个参数默认为int可省略
	Person<string> p2("猪八戒", 999);
	p2.showPerson();
}



int main104()
{
	test104_1();
	test104_2();
	system("pause");
	return 0;
}