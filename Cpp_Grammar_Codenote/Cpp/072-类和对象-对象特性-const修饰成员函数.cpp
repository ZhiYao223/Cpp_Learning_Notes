#if 0
常函数：
成员函数后加const后，我们称这个函数为常函数
常函数内不可以修改成员属性
成员属性声明时加关键字mutable后，在常函数中依然可以修改

常对象：
声明对象前加const称该对象为常对象
常对象只能调用常函数

常对象可以修改静态成员变量，常对象只能调用常函数，因为常函数本身保证了属性不可修改
成员函数后加const，修饰的是this指针
C++ const成员变量和成员函数（常成员函数）：
http://c.biancheng.net/view/2232.html
http://c.biancheng.net/view/2230.html#:~:text=1%20%E5%87%BD%E6%95%B0%E5%BC%80%E5%A4%B4%E7%9A%84%20const%20%E7%94%A8%E6%9D%A5%E4%BF%AE%E9%A5%B0%E5%87%BD%E6%95%B0%E7%9A%84%E8%BF%94%E5%9B%9E%E5%80%BC%EF%BC%8C%E8%A1%A8%E7%A4%BA%E8%BF%94%E5%9B%9E%E5%80%BC%E6%98%AF%20const%20%E7%B1%BB%E5%9E%8B%EF%BC%8C%E4%B9%9F%E5%B0%B1%E6%98%AF%E4%B8%8D%E8%83%BD%E8%A2%AB%E4%BF%AE%E6%94%B9%EF%BC%8C%E4%BE%8B%E5%A6%82%20const%20char,const%20%E8%A1%A8%E7%A4%BA%E5%B8%B8%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%EF%BC%8C%E8%BF%99%E7%A7%8D%E5%87%BD%E6%95%B0%E5%8F%AA%E8%83%BD%E8%AF%BB%E5%8F%96%E6%88%90%E5%91%98%E5%8F%98%E9%87%8F%E7%9A%84%E5%80%BC%EF%BC%8C%E8%80%8C%E4%B8%8D%E8%83%BD%E4%BF%AE%E6%94%B9%E6%88%90%E5%91%98%E5%8F%98%E9%87%8F%E7%9A%84%E5%80%BC%EF%BC%8C%E4%BE%8B%E5%A6%82%20char%20%2A%20getname%20%28%29%20const%20%E3%80%82
http://c.biancheng.net/view/2041.html
#endif

#include <iostream>
using namespace std;

//常函数
class People
{
public:
	//this指针的本质  是指针常量  指针的指向是不可以修改的
	//const People* const this;//指针的指向和指向的值都不可修改
	//在成员函数后面加const，修饰的是this指针，让指针指向的值也不可修改
	void ShowPeople() const  //若不想修改m_A时，在函数后面加const
	{
		this->m_B = 100;  //加mutable后该变量变为可修改
		//this->m_A = 100;  //本质是this->m_A = 100;
		//this = NULL;//指针一旦指向p,就不能再指向别的地方； this指针不可以修改指针的指向
	}
	void func()
	{
		m_A = 200; //普通函数可以修改m_A属性
	}
	int m_A;
	mutable int m_B;//特殊变量，即使在常函数中，也可以修改这个值,加关键字mutable
};

void test01()
{
	People p;
	p.ShowPeople();
}
void test02()
{
	const People p;//在对象前加const，变为常对象
	//p.m_A = 100;//报错，对象为const,其对象的属性也不可修改
	p.m_B = 100; //m_B加了关键字mutable， 其对象的属性变为可修改
	//常对象只能调用常函数
	p.ShowPeople();
	//p.func();//报错，常对象只能调用常函数，func()不是常函数，如果调用等于侧面修改了m_A=200

}
int main72()
{
	test01();
	test02();
	system("pause");
	return 0;
}