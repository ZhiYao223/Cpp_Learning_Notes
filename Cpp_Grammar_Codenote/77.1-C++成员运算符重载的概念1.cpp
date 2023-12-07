/*
运算符重载为成员函数：
	如果是重载双目运算符，就只要设置一个参数作为右侧运算量，而左侧运算量就是该对象本身；
	如果是重载单目运算符，就不必另外设置参数，运算符的操作量就是对象本身。

引例：定义了一个复数类，为了实现复数的加法，可以定义一个成员
函数Add,调用它可以实现两个复数对象相加，并返回一个新的复数对象
*/
#if 0
#include <iostream>
#include<string>
using namespace std;

class Complex
{
	double real, image;
public:
	Complex(double r = 0, double i = 0)
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
	Complex Add(const Complex& c)   //成员函数运算符重载，第一个对象就是它本身用this
	{
		Complex temp;
		temp.real = this->real + c.real;
		temp.image = this->image + c.image;
		return temp;
	}
	bool operator==(const Complex& c2)//==是双目运算符，两个参数,如果相等返回True,不相等False
	{
		if (this->real == c2.real && this->image == c2.image)
			return true;
		else
			return false;
	}
};

int main77_1()
{
	Complex c1(1, 1), c2(8, -3);
	c1.show();
	c2.show();
	Complex c3 = c1.Add(c2);  //成员函数重载，计算
	if (c1 == c2)               //判断两个复数是否相等
		cout << "两个复数相等" << endl;
	else
		cout << "两个复数不相等" << endl;
	//Complex c3 = c1 + c2; 报错
	c3.show();
	return 0;
}

#endif
