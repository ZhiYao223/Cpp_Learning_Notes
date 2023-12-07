/*
	类模版作用
	建立一个通用类，类中的成员，数据类型可以不具体定制，用一个虚拟的类型来代表

	语法：
	template ---声明创建模版
	typename --- 表明其后的符号是一种数据类型，可以用class代替
	T ---通用的数据类型， 名称可以替换，通常为大写字母

	总结：类模板和函数模版语法相似，在声明模版template后面加类，此类称为类模版
*/
#include <iostream>
#include <string>
using namespace std;

//类模版
template<class NameType, class Agetype>
class Person
{
public:
	Person(NameType name, Agetype age)   //有参构造函数
	{
		this->m_Name = name;
		this->m_Age = age; 
	}
	void showPerson()  
	{
		cout << "name: " << this->m_Name << "\tage: " << this->m_Age << endl;
	}
	NameType m_Name;
	Agetype m_Age;
};

void test103_1()
{
	//类型参数化
	Person<string, int> p1("孙悟空", 999);
	p1.showPerson();
}
int main103()
{
	test103_1();
	system("pause");
	return 0;
}