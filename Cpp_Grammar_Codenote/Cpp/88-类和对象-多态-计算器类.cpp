#include <iostream>
using namespace std;
#include <string>
//**********************************************************************************************************
//分别利用普通写法和多态技术实现计算器
//普通写法/传统计算机写法
class Calculator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")  //oper表示字符
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		else
		{
			return m_Num1 / m_Num2;
		}
		//如果想扩展新的功能，需要修改源码
		//在真实开发中，提倡开闭原则：对扩展进行开发，对修改进行关闭
	}
	int m_Num1; //操作数1
	int m_Num2; //操作数2
};
void test88_1()
{
	//创建计算器类
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
	cout << c.m_Num1 << "/" << c.m_Num2 << "=" << c.getResult("/") << endl;
}
//****************************************************************************************************
//利用多态实现计算器，实现计算器抽象类
/*
多态好处：
1、组织结构清晰
2、可读性强
3、对于前期和后期扩展以及维护性高
*/
//实现计算机抽象类
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_Num1 = 0;
	int m_Num2 = 0;
};


//设计加法计算器类
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//设计减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//设计乘法计算器类
class MulCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};
//设计除法计算器类
class DivCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 / m_Num2;
	}
};
void test88_2()
{
	//多态使用条件:父类指针或引用指向子类对象
	//加法
	AbstractCalculator* abc = new AddCalculator; //new说明创建在堆区，手动开放手动释放
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;	//用完后记得销毁
	//减法
	abc = new SubCalculator;
	abc->m_Num1 = 20;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	//乘法
	abc = new MulCalculator;
	abc->m_Num1 = 20;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;	
	//除法
	abc = new DivCalculator;
	abc->m_Num1 = 20;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "/" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
}


int main88()
{
	//test88_1();
	test88_2(); 
	system("pause");
	return 0;
}