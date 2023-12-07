/*
不允许定义新的运算符
不能改变该运算符操作数(对象)的个数
不能改变该运算符的优先级别和结合性
应该符合实际需要，重载的功能应该与运算符原有的功能相似，避免没有目的的使用重载运算符
*/
/*
在响应的类中声明为该类的友元函数，声明一般形式为:
	friend 返回类型 operator @(参数表);
	而函数的具体定义如下：
	返回类型 operator @(参数表)
	{
		//函数体
	｝
*/
//案例： 定义复数类Complex， 采用友元函数实现运算符重载+和==


#include <iostream>
using namespace std;

class Complex77
{
	friend Complex77 operator+(const Complex77& c1, const Complex77& c2);//友元函数声明
	friend bool operator==(const Complex77& c1, const Complex77& c2); //函数声明
	double real, image;
public:
	Complex77(double r = 0, double i = 0)
	{
		real = r;
		image = i;
	}
	void show()
	{
		if (image > 0)
		{
			if (image == 1)
				cout << real << "+" << "i" << endl; //处理虚部为1的情况，如3+i
			else
				cout << real << "+" << image << "i" << endl;//处理虚部为其他正数的情况如3+2i;
		}
		else if (image < 0)
		{
			if (image == -1)
				cout << real << "-" << "i" << endl;//处理虚部为-1的情况，如3-i
			else
				cout << real << image << "i" << endl;//处理虚部为其他负数的情况如3-2i
		}
		else                 // image = 0 
		{
			cout << real << endl;
		}
	}
	/*  成员函数实现运算符重载
	Complex Add(const Complex& c)   //成员函数运算符重载，第一个对象就是它本身用this
	{
		Complex temp;
		temp.real = this->real + c.real;
		temp.image = this->image + c.image;
		return temp;
	}
	*/

};
/*友元函数实现运算符重载Complex c3 = c1 + c2;
友元函数实现，c1+c2，需要两个参数如下,且返回Complex类型*/
Complex77 operator+(const Complex77& c1, const Complex77& c2)
{
	Complex77 temp;
	temp.real = c1.real + c2.real;
	temp.image = c1.image + c2.image;
	return temp;
}
bool operator==(const Complex77& c1, const Complex77& c2)//==是双目运算符，两个参数,如果相等返回True,不相等False
{
	if (c1.real == c2.real && c1.image == c2.image)
		return true;
	else
		return false;
}
int main77_2()
{
	Complex77 c1(1, 1), c2(2, -3);  //生成两个复数 
	c1.show();
	c2.show();

	Complex77 c3 = operator+(c1, c2);  //显示的调用

	c3.show();
	if (c1 == c2)
		cout << "两个复数相等" << endl;
	else
		cout << "两个复数不相等" << endl;
	//Complex c3 = c1 + c2; //隐式的调用

	//cout << c1; //报错
	cout.operator<<(3);
	cout.operator<< ('a');


	return 0;
}