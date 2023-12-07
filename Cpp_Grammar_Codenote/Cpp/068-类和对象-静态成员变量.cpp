////静态成员就是在成员变量和成员函数前加上关键字static，成为静态成员

//静态成员变量：
//所有对象共享同一份数据
//在编译阶段就分配内存
//类内声明，类外初始化

//People::member 表示类People中的成员member
#include <iostream>
using namespace std;

//静态成员变量
class People
{
public:
	static int m_A; //类内声明, 静态变量不能在构造里面初始化

	
private://静态成员变量也是有访问权限的
	static int m_B;
};
int People::m_A = 100; //类外初始化，去掉static，加上::表示people类下的变量
int People::m_B = 200;

void test6()
{
	People p;
	cout << p.m_A << endl;  //100

	People p2;
	p2.m_A = 200;

	cout << p.m_A << endl;//200
}

void test06()
{
	//通过对象进行访问
	//People p;
	//cout << p.m_A << endl;
	
	//通过类名进行访问
	cout << People::m_A << endl;
	//cout << People::m_B << endl; //报错，类外访问不到私有静态成员变量
}

int main68()
{
	test6();
	//test06();
	system("pause");
	return 0;
}