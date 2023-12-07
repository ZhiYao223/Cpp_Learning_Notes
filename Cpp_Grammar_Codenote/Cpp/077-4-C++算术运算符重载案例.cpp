#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
//构造函数
public:
	//以全局函数形式重载+ - * /  
	friend Complex operator+(const Complex& c1, const Complex& c2);
	friend Complex operator-(const Complex& c1, const Complex& c2);
	friend Complex operator*(const Complex& c1, const Complex& c2);
	friend Complex operator/(const Complex& c1, const Complex& c2);
	friend bool operator==(const Complex& c1, const Complex& c2);
	friend bool operator!=(const Complex& c1, const Complex& c2);

public:  
	
	Complex(double real = 0.0, double image = 0.0) : m_real(real), m_image(image) {}

	//以成员函数形式重载运算符 只需要一个参数,另一个用this返回自身
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

	//复数显示函数
	void complexshow()
	{
		if (m_image > 0)
		{
			if (m_image == 1)
			{
				cout << m_real << "+" << "i" << endl;
			}
			else
			{
				cout << m_real << "+" << m_image << "i" << endl; 
			}
		}
		else if(m_image < 0)
		{
			if (m_image == -1)
			{
				cout << m_real << "-" << "i" << endl; 
			}
			else
			{
				cout << m_real << "-" << m_image << "i" << endl; 
			}
		}
		else
		{
			cout << endl;
		}
	}
public:
	//该函数没有修改对象的状态，因此在函数声明的末尾使用了 const 关键字来确保不会对成员变量造成修改。
	double getreal() const { return m_real; }    
	double getimage() const { return m_image; } 

private:
	double m_real;  //实部
	double m_image; //虚部
};

/************************************************************************************
	类外以全局函数形式进行运算符重载，需要传递两个参数进行赋值，比较等操作，
	而类内成员函数重载只需要一个参数，另一个可以通过this指针调用自身
************************************************************************************/
//加法+运算符重载   
Complex operator+(const Complex& c1, const Complex& c2)
{
	Complex temp;
	temp.m_real = c1.m_real + c2.m_real;
	temp.m_image = c1.m_image + c2.m_image;
	return temp;
}
//减法-运算符重载
Complex operator-(const Complex& c1, const Complex& c2)
{
	Complex temp;
	temp.m_real = c1.m_real - c2.m_real;
	temp.m_image = c1.m_image - c2.m_image;
	return temp; 
}
//乘法*运算符重载
Complex operator*(const Complex& c1, const Complex& c2) 
{
	Complex temp;
	temp.m_real = (c1.m_real * c2.m_real) - (c1.m_image * c2.m_image);
	temp.m_image = (c1.m_real * c2.m_image) + (c1.m_image * c2.m_real);
	return temp; 
}
//除法/运算符重载
Complex operator/(const Complex& c1, const Complex& c2)
{
	Complex temp;
	temp.m_real = (c1.m_real * c2.m_real + c1.m_image * c2.m_image) / (pow(c2.m_real, 2) + pow(c2.m_real, 2));
	temp.m_image = (c1.m_image * c2.m_real - c1.m_real * c2.m_image) / (pow(c2.m_real, 2) + pow(c2.m_real, 2));
	return temp; 
}
//重载 == 运算符
bool operator==(const Complex& c1, const Complex& c2)  // 需要在类内友元声明
{
	if (c1.getreal() == c2.getreal() && c1.getimage() == c2.getimage())
	{
		return true; 
	}
	else
	{
		return false;
	}
}
//重载 != 运算符
bool operator!=(const Complex& c1, const Complex& c2)
{
	//两个复数，只要实部、虚部任何一方不相等，即为不等
	if (c1.m_real != c2.m_real || c1.m_image != c2.m_image)
	{
		return true; 
	}
	else
	{
		return false;
	}
}
//重载+=运算符

/*
在下面
的示例中，我们假设 Complex 类包含了两个私有成员变量 m_real 和 m_imag，分别表示实部和虚部。
在 operator+= 函数中，我们将传入的 c 对象的实部和虚部分别加到当前对象的实部和虚部上，
并将结果保存在当前对象中。最后，我们返回 *this，即当前对象的引用，以支持链式赋值操作。
如果 operator+= 返回的是对象而不是引用，那么我们只能对两个对象进行一次累加操作，
并无法在同一行上对多个对象进行连续的累加操作。
*/
//重载 += 运算符
Complex& Complex::operator+=(const Complex& c)
{
	this->m_real += c.m_real;
	this->m_image += c.m_image;
	return *this; 
}

//重载 -= 运算符
Complex& Complex::operator-=(const Complex& c)
{
	this->m_real -= c.m_real;
	this->m_image -= c.m_image;
	return *this; 
}
//重载*= 运算符
Complex& Complex::operator*=(const Complex& c)
{
	this->m_real = this->m_real * c.m_real - this->m_image * c.m_image;
	this->m_image = this->m_real * c.m_image + this->m_image * c.m_real;
	return *this; 
}

//重载/=运算符
Complex& Complex::operator/=(const Complex& c)
{
	this->m_real = (this->m_real * c.m_real + this->m_image * c.m_image) / (pow(c.m_real, 2) + pow(c.m_image, 2));
	this->m_image = (this->m_image * c.m_real - this->m_real * c.m_image) / (pow(c.m_real, 2) + pow(c.m_image, 2));
	return *this;
}




void test77_4()
{
	Complex c1(1, 2);
	Complex c2(2, 3);
	Complex c3(3, 4);
	Complex c4(4, 5);
	Complex c5(5, 6);
	c1.complexshow();
	c2.complexshow();
	c3.complexshow();
	c4.complexshow();
	cout << endl;

	//测试加减乘除
	Complex c6 = c1 + c2;
	Complex c7 = c2 - c3;
	Complex c8 = c3 * c4;
	Complex c9 = c4 / c5;
	c6.complexshow();
	c7.complexshow();
	c8.complexshow();
	c9.complexshow();
	cout << endl;

	c3 += c1;
	c4 -= c2;
	c5 *= c2;
	c6 /= c2;
	c3.complexshow();
	c4.complexshow();
	c5.complexshow();
	c6.complexshow();
	cout << endl;   

	if (c1 != c2)
	{
		cout << "true" << endl; 
	}
	else
	{
		cout << "false" << endl;
	}
	if (c3 == c4)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false"<< endl;
	}

}

int main77_4()
{
	test77_4();
	system("pause");
	return 0;
}