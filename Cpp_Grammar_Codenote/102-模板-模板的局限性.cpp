/*
	模版的通用性并不是万能的
	有些特定的数据类型，需要用具体化方式做特殊处理
	函数模版无法比较Person类，因此需要用template<>再具体化一个Person版本的函数重载模版
	大众类型用模版，特定类型再写具体化的特殊特定函数
	利用具体化的模版，可以解决自定义类型的通用化
	学习模版不是为了写模版，而是在STL能够运用系统提供的模版
	*/
#include<iostream>
using namespace std;
#include<string>
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	Person(const Person& p)
	{
	this->m_Name = p.m_Name;
	this->m_Age = p.m_Age;
	//this->m_Height = p.m_Height;
	cout << p.m_Name << ":拷贝\n";
	}
	string m_Name;
	int m_Age;
};


//对比两个数据是否相等
//无法比较Person类的实例化对象p1,p2
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true; 
	}
	else
	{
		return false;
	}
} 

//利用具体化的Person版本实现代码，具体化优先调用
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true; 
	}
	else
	{
		return false; 
	}
}

//调用普通函数比较两个数据
void test102_1()
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);
	if (ret)
	{ 
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a == b" << endl;

	}
}

//在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了
//调用函数模版实现比较两个数据
void test102_2()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);

	bool ret = myCompare(p1, p2);  //调用的是具体化的重载函数模版
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl; 
	}
}

int main102()
{
	test102_1();
	test102_2();
	system("pause");
	return 0;
}
 