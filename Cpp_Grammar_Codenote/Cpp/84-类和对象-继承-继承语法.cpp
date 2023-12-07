/*
C++允许一个类继承多个类
语法： class 子类：继承方式 父类1， 继承方式 父类2...
多继承可能会引发父类中有同名成员函数出现，需要加作用域区分
*/

#include <iostream>
using namespace std;

//多继承语法
class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		m_A = 200;//m_B = 200;
	}
	int m_A;//int m_B;
};

//子类  需要继承Base1和Base2
//语法 class 子类 ：继承方式 父类1， 继承方式 父类2......
class Son :public Base1, public Base2   //一个儿子认多个爹
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;

};
void test84_1()
{
	Son s;
	cout << "sizeof Son = " << sizeof(s) << endl;
	//cout << "m_A = " << s.m_A << endl; //若父类Base1 和Base2中都有相同的成员属性m_A，则s.m_A出现二类性错误
	//当父类中出现同名成员，需要加作用域区分
	cout << "Base1::m_A = " << s.Base1::m_A << endl;
	cout << "Base2::m_A = " << s.Base2::m_A << endl;



}
int main84()
{
	test84_1();
	system("pause");
	return 0;
}