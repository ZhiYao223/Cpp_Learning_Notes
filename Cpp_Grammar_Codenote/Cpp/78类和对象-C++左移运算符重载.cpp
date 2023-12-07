#if 0
#include <iostream>
using namespace std;

//左移运算符重载
class People
{
	friend ostream& operator<<(ostream& out, People& p);
public:
	//利用成员函数重载  左移运算符
	void operator<<(People& p)
	{
		 
	}
	int m_A;
	int m_B;
};

//只能利用全局函数重载左移运算符
ostream & operator<<(ostream &cout, People& p) //本质 operator<<(cout, p) 简化cout<<
{
	cout << "m_A = " << p.m_A << "m_B = " << p.m_B;
	return cout;
}
void test78()
{
	People p;
	p.m_A = 10;
	p.m_B = 10;
	cout << p;
}

int main78()
{
	test78(); 
	system("pause");
	return 0;
}
#endif
//运算符的返回值类型取决于该重函数的作用是什么。
//比如a+b的作用是得到一个加数，那么返回值就是a+b的值
//a+=b的作用是让a的值改变，既然是让参数a的值改变，那么就无需返回值
//还有就是如果我们需要运算符支持多次操作那么也需要返回值，比如流插入运算符<<.
//我们可能需要进行多次插入，像cout<<a<<b<<c；之类就需要返回流ostream本身便于之后的流插工作。
//下面展示几种运算符重载方式：
//加号（双目):
#include <iostream>
using namespace std;

class Time
{
	int _hour;
	int _min;
	int _sec;
public:
	Time(int hour = 0, int min = 0, int sec = 0)
	{
		_hour = hour;
		_min = min;
		_sec = sec;
	}
	void Print()
	{
		cout << _hour << ":" << _min << ":" << _sec << endl;
	}

	Time operator+(int min)//加分钟
	{
		Time t(*this);//因为是+号，规定不能改变左右参数的值，所以使用t来取和用以返回
		t._min += min;
		if (t._min > 59)//检查时间正确性
		{
			t._hour += (t._min / 60);
			if (t._hour > 23)
				t._hour /= 24;
			t._min %= 60;
		}
		return t;
	}
};

int main78()
{
	Time a(10, 30, 30);
	(a + 140).Print();
	system("pause");
	return 0;
}
//默认赋值运算符重载
//即便我们没有手动定义赋值运算符重载，C++也为我们提供了默认函数。

//在默认赋值重载中，内置类型按字节拷贝，自定义类型会去调自己的默认赋值重载。这点与默认拷贝构造极为相似，不懂的可以看看这篇文章：详解析构函数、拷贝构造函数

//因此，当我们的类中只有int、char、double之类内置类型时，无需再写赋值重载。

//但是，如果有指针、malloc、new之类指向地址、手动开辟空间的，一般情况下还是需要手写重载的。

//总而言之，默认赋值重载只能进行浅拷贝，是否需要手动去写要根据类的成员类型判断。
#if 0
#include <iostream>
using namespace std;

class complex {
public:
	complex(double real = 0.0, double imag = 0.0) :m_real(real), m_imag(imag) {};
public:
	friend complex operator+(const complex& A, const complex& B);
	friend complex operator-(const complex& A, const complex& B);
	friend complex operator*(const complex& A, const complex& B);
	friend complex operator/(const complex& A, const complex& B);
	friend istream& operator>>(istream& in, complex& A);
	friend ostream& operator<<(ostream& out, complex& A);

private:
	double m_real;  //实部
	double m_imag;  //虚部
};

//重载加法运算
complex operator+(const complex& A, const complex& B) {
	complex C;
	C.m_real = A.m_real + B.m_real;
	C.m_imag = A.m_imag + B.m_imag;
	return C;
}
//重载减法运算符
complex operator-(const complex& A, const complex& B) {
	complex C;
	C.m_real = A.m_real - B.m_real;
	C.m_imag = A.m_imag - B.m_imag;
	return C; 
}
//重载乘法运算符
complex operator*(const complex& A, const complex& B) {
	complex C;
	C.m_real = A.m_real * B.m_real - A.m_imag * B.m_imag;
	C.m_imag = A.m_imag * B.m_real + A.m_real * B.m_imag;
	return C; 
}
//重载除法运算符
complex operator/(const complex& A, const complex& B) {
	complex C;
	double square = A.m_real * A.m_real + A.m_imag * A.m_imag;
	C.m_real = (A.m_real * B.m_real + A.m_imag * B.m_imag) / square;
	C.m_imag = (A.m_imag * B.m_real - A.m_real * B.m_imag) / square;
	return C;
}
//重载输入运算符
istream& operator>>(istream& in, complex& A) {
	in >> A.m_real >> A.m_imag;
	return in; 
}

//重载输出运算符
ostream& operator<<(ostream& out, complex& A) {
	out << A.m_real << "+" << A.m_imag << "i";
	return out; 
}

int main()
{
	complex c1, c2, c3;
	cin >> c1 >> c2;
	
	c3 = c1 + c2;
	cout << "c1 + c2 = " << c3 << endl;

	c3 = c1 - c2;
	cout << "c1 - c2 = " << c3 << endl;

	c3 = c1 * c2;
	cout << "c1 * c2 = " << c3 << endl;

	c3 = c1 / c2;
	cout << "c1 / c2 = " << c3 << endl;
	system("pause");
	return 0;
}
#endif

