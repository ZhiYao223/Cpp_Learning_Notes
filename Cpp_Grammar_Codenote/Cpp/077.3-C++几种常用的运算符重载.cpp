/*
1.输入输出运算符>> 和 <<
2.自增运算符++
3.赋值操作符 = 
案例： 实现运算符重载函数>>和<<
*/
/*
标准输入流对象cin， 是istream类的对象，用于处理标准输入（即键盘输入）
标准输出流对象cout, 是ostream类的对象，用户处理标准输出（即屏幕输出）

只能采用友元函数的形式，通常格式如下：
ostream &operator <<(ostream &, const 类对象引用）
istream &operator >>(istream &, 类对象引用）

*/


#include <iostream>
using namespace std;

class Complex
{
	friend Complex operator+(const Complex& c1, const Complex& c2);//友元函数声明
	friend bool operator==(const Complex& c1, const Complex& c2); //函数声明
	friend ostream& operator<<(ostream& myout, const Complex& c); //<<运算符函数重载声明
	friend istream& operator>>(istream& myin, Complex& c);
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
};
/*元函数实现运算符重载Complex c3 = c1 + c2;
友元函数实现，c1+c2，需要两个参数如下,且返回Complex类型*/
#if 0
Complex operator+(const Complex& c1, const Complex& c2)
{
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.image = c1.image + c2.image;
	return temp;
}
//==是双目运算符，两个参数,如果相等返回True,不相等False
bool operator==(const Complex& c1, const Complex& c2)
{
	if (c1.real == c2.real && c1.image == c2.image)
			return true;
	else
		return false;
}
#endif
//返回类型为输入流的引用  第一个参数流的状态会被改变不能加const，
//第二个参数complex对象的引用不能加const，因为要对它进行输入修改
istream& operator>>(istream& myin, Complex& c)   
{
	cin >> c.real >> c.image;
	return myin;
}
ostream& operator<<(ostream& myout, const Complex& c)  //向流中写入数据会改变流的状态,无需加const
{
	if (c.image > 0)
	{
		if (c.image == 1)
			cout << c.real << "+" << "i" << endl; //处理虚部为1的情况，如3+i
		else
			cout << c.real << "+" << c.image << "i" << endl;//处理虚部为其他正数的情况如3+2i;
	}
	else if (c.image < 0)
	{
		if (c.image == -1)
			cout << c.real << "-" << "i" << endl;//处理虚部为-1的情况，如3-i
		else
				cout << c.real << c.image << "i" << endl;//处理虚部为其他负数的情况如3-2i
		}
	else                 // image = 0 
	{
		cout << c.real << endl;
	}
	return myout;
}

int main77_3()
{
	Complex c1(7, 3), c2(2, 8);
	c1.show();
	c2.show();

	cout<<5<<'t'<<5.76<<endl;
	//cout << c1;
	cout << c1 << c2;  //连续输出c1，c2


	cout<<"--------------------------------" << endl;
	cin >> c1 >> c2;
	cout << c1 << c2;

	cout.operator<<(3);   //显式输出
	cout.operator<<('a');
	system("pause");
	return 0;
}