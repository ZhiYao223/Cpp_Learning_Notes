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
	static int count;//声明静态成员变量
	
private://静态成员变量也是有访问权限的
	static int m_B;

public:
	People() {
		count++; //每次创建对象时，增加count
	}
};

//类外初始化，去掉static，加上::表示people类下的变量
int People::m_A = 100; 
int People::m_B = 200;
int People::count = 0; 
void test6()
{
	People p;
	cout << p.m_A << endl;  //100

	cout << "Initial count : " << People::count << endl;//0

	People p2;
	p2.m_A = 200;
	cout << p.m_A << endl;//200

	People p3;
	cout << "Final count: " << People::count << endl;//3
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
/*
每次创建对象时，count 都会增加。由于 count 是静态成员变
量，因此它被所有的 MyClass 对象所共享，所以输出结果将显示对象的总
数。
*/
int main68()
{
	test6();
	//test06();
	system("pause");
	return 0;
}