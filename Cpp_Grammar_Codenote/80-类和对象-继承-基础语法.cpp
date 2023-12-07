/*
利用开发人员命令提示工具查看对象模型
跳转盘符 F :
跳转文件路径cd，具体路径下
查看命名 c1 / d1 reportSingleClassLayout类名
*/
//父类中所有非静态成员属性都会被子类继承下去
//父类中私有成员属性，是被编译器给隐藏了，因此是访问不到，但确实被继承下去了

#include <iostream>
using namespace std;

//继承方式

//公共继承
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10; //父类中的公共权限成员，到子类中已然是公共权限
		m_B = 10; //父类中的包含权限成员，到子类中依然是保护权限
		//m_C = 10; //父类中的私有权限成员，子类访问不到
	}
};

void test79_1()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100; //到Son1中m_B是保护权限，类外访问不到
}
//保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 :protected Base2
{
public:
	void func()
	{
		m_A = 100; //父类中公共成员，到子类中变为保护权限
		m_B = 100; //父类中保护成员，到子类中变为保护权限
		//m_C = 100; //父类中私有成员，子类访问不到
	};
};

void test79_2()
{
	Son2 s1;
	//s1.m_A = 100; //在Son2中，m_A变为保护权限，因此类外访问不到
	//s1.m_B = 100; //在Son2中，m_B变为保护权限，不可以访问
}

//私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//公有继承
class Son3 :private Base3
{
public:
	void func()
	{
		m_A = 100;   //父类中公共成员，到子类中变为 私有成员
		m_B = 100;   //父类中保护成员，到子类中变为 私有成员
	   //m_C = 100;   //父类中私有成员，子类访问不到
	}
};

class GrandSon3 :public Son3
{
public:
	void func()
	{
		//m_A = 1000; //到了Son3中，m_A变为私有，即使是儿子，也访问不到
		//m_B = 1000; //到了Son3中，m_A变为私有，即使是儿子，也访问不到
	}
};

void test03()
{
	Son3 s1;
	//s1.m_A = 1000;  //到Son3中，变为私有成员，类外访问不到
	//s1.m_B = 1000;   //到Son3中，变为私有成员，类外访问不到
}

int main80()
{

	system("pause");
	return 0;
}
