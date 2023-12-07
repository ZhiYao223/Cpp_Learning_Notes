//类和对象
//c++面向对象的三大特性为：封装、继承、多态
//c++认为万事万物都皆为对象，对象上有其属性和行为
//
//封装的意义：
//将属性和行为作为一个整体，表现生活中的事物
//将属性和行为加以权限控制
//
//语法： class 类名{访问权限：属性/行为};


#include <iostream>
using namespace std;
const double PI = 3.14;

//设计一个圆类，求圆的周长, 2*PI*半径
class Circle
{
	//属性
public:
	int m_r;//半径

	double calculateZC()
	{
		return 2 * PI * m_r; 
	}

private:

};

int main55()
{
	//通过圆类，创建具体的圆（对象）
	//实例化：通过一个类，创建一个对象的过程
	Circle c1;
	//给圆对象的属性进行赋值操作
	c1.m_r = 10;
	cout << "圆的周长为：" << c1.calculateZC() << endl;

	system("pause");
	return 0;
}

